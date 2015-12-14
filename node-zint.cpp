//
// Created by stephen on 15/12/11.
//

#include "node-zint.h"
#include <node.h>
#include <gd.h>
#include "./zint_lib/zint.h"
#include "nan.h"
#include <cstdlib>

namespace node_zint {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Exception;


    //symbology
    //size
    //fg_color
    //bg_color
    //txt
    //margin
    //level
    //ecc_level
    //hint
    //ver
    void GeneratorZint(const FunctionCallbackInfo <Value> &args) {
        Isolate *isolate = args.GetIsolate();

        if( args.Length() < 10) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong number of arguments")));
            return;
        }

        if( !args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsString() || 
            !args[3]->IsString() || !args[4]->IsString() || !args[5]->IsNumber() || 
            !args[6]->IsNumber() || !args[7]->IsNumber() || !args[8]->IsNumber() ||
            !args[9]->IsNumber() ){
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong type of arguments")));
            return;

        }
        int symbology = args[0]->NumberValue(),
            size = args[1]->NumberValue();

        String::Utf8Value param1(args[2]->ToString());
        std::string s_fg_color = std::string(*param1);
        String::Utf8Value param2(args[3]->ToString());
        std::string s_bg_color = std::string(*param2);
        String::Utf8Value param3(args[4]->ToString());
        std::string txt = std::string(*param3);

        int margin = args[5]->NumberValue(),
            level = args[6]->NumberValue(),
            ecc_level = args[7]->NumberValue(),
            hint = args[8]->NumberValue(),
            ver = args[9]->NumberValue();

        //const char *x = "hello";
        //unsigned char *y;
        //y = (unsigned char *) x;


        void *img_stream = NULL;
        struct zint_symbol *my_symbol;
        my_symbol = ZBarcode_Create();
        my_symbol->symbology = symbology;
        //if(symbology==BARCODE_QRCODE)
            my_symbol->option_1 = ecc_level;
        //my_symbol->


        int nRet1 = ZBarcode_Encode(my_symbol, (unsigned char *)txt.c_str(), 0);

        int nRet3 = 0;
        if (nRet1 == 0) {
            nRet3 = ZBarcode_Buffer(my_symbol, 0);

            // args.GetReturnValue().Set(String::NewFromUtf8(isolate, "error 1"));
            //return;
        }
       
        if (nRet1 != 0 || nRet3 != 0) {
            args.GetReturnValue().Set(String::NewFromUtf8(isolate, "error 2"));
            return ;
        }
        else {

            int img_stream_len = 0;
            gdImagePtr img;
            //int code_size = (size-margin*2)/my_symbol->bitmap_width;
            //code_size = (code_size == 0) ? 1 : code_size;
            int img_margin = margin;
            int img_width = 0;
            int img_height = 0;
            float extend = 1.0;

            if( (size-margin*2)<my_symbol->bitmap_width ){
                img_width = my_symbol->bitmap_width+img_margin*2;
                img_height = my_symbol->bitmap_height+img_margin*2;
                extend = 1.0;
            }
            else{
                img_width = size;
                extend = (float)(img_width-img_margin*2)/(float)my_symbol->bitmap_width;
                img_height = (int)(extend*(float)my_symbol->bitmap_height)+img_margin*2; // +0.5

            }

            //int img_width = my_symbol->bitmap_width * code_size + 2 * img_margin;
            //int img_height = my_symbol->bitmap_height * code_size + 2 * img_margin;

            img = gdImageCreate(img_width, img_height);

            // extract rgb color from string
            int fg_r = 0, fg_g = 0, fg_b = 0;
            if( s_fg_color.size()>=6 ) {
                char ss[3];
                ss[2] = '\0';
                char *pEnd;
                ss[0] = s_fg_color[0];
                ss[1] = s_fg_color[1];
                fg_r = std::strtol(ss,&pEnd,16);

                ss[0] = s_fg_color[2];
                ss[1] = s_fg_color[3];
                fg_g = std::strtol(ss,&pEnd,16);

                ss[0] = s_fg_color[4];
                ss[1] = s_fg_color[5];
                fg_b = std::strtol(ss,&pEnd,16);
            }

            int fg_color = gdImageColorAllocate(img, fg_r, fg_g, fg_b);

            int bg_r = 0, bg_g = 0, bg_b = 0;
            if( s_bg_color.size()>=6 ) {
                char ss[3];
                ss[2] = '\0';
                char *pEnd;
                ss[0] = s_bg_color[0];
                ss[1] = s_bg_color[1];
                bg_r = std::strtol(ss,&pEnd,16);

                ss[0] = s_bg_color[2];
                ss[1] = s_bg_color[3];
                bg_g = std::strtol(ss,&pEnd,16);

                ss[0] = s_bg_color[4];
                ss[1] = s_bg_color[5];
                bg_b = std::strtol(ss,&pEnd,16);
            }
            int bg_color = gdImageColorAllocate(img, bg_r, bg_g, bg_b);

            gdImageFill(img, 0, 0, bg_color);


            int i = 0, posx, posy, x, y, red, blue, green;

            int preX = 0, preY = 0;
            int nextX = 0 ,nextY = 0;

            for (y = 0; y < my_symbol->bitmap_height; y++) {
                nextY = preY+extend;
                while(true){
                    if( int(nextY/extend)>y ){
                        nextY--;
                    }
                    else
                        break;
                }
                preX = 0;
                nextX = 0;
                for (x = 0; x < my_symbol->bitmap_width; x++) {
                    nextX = preX+extend;
                    while(true){
                        if( int(nextX/extend)>x ){
                            nextX--;
                        }
                        else
                            break;
                    }

                    red = (int) my_symbol->bitmap[i];
                    green = (int) my_symbol->bitmap[i + 1];
                    blue = (int) my_symbol->bitmap[i + 2];

                    if (red == 0 && green == 0 && blue == 0){

//                        posx = (x*extend)+img_margin;
//                        posy = (y*extend)+img_margin;
//                        gdImageFilledRectangle(img, posx, posy, posx + extend, posy + extend, fg_color);
//                        posx = x * code_size + img_margin;
//                        posy = y * code_size + img_margin;
//
//                        gdImageFilledRectangle(img, posx, posy, posx + code_size, posy + code_size, fg_color);



                        gdImageFilledRectangle(img, preX+img_margin, preY+img_margin, nextX+img_margin, nextY+img_margin, fg_color);
                    }
                    i += 3;
                    preX = nextX+1;

                }

                preY = nextY+1;
            }

            img_stream = gdImagePngPtr(img, &img_stream_len);

            gdImageDestroy(img);

            /* QRcode_free(code); */
            ZBarcode_Delete(my_symbol);


            Nan::MaybeLocal<Object> result = Nan::CopyBuffer((char*)img_stream, img_stream_len);
            gdFree(img_stream);


            //args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
            args.GetReturnValue().Set(result.ToLocalChecked());
        }
        
    }

    void init(Local <Object> exports) {
        NODE_SET_METHOD(exports, "zint", GeneratorZint);
    }

    NODE_MODULE(addon, init);

}