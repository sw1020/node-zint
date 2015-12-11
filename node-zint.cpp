//
// Created by stephen on 15/12/11.
//

#include "node-zint.h"
#include <node.h>
#include "./zint_lib/zint.h"

namespace node_zint{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void GeneratorZint(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        const char* x = "hello";
        unsigned char* y;

        y = (unsigned char*) x;

        struct zint_symbol *my_symbol;
        my_symbol = ZBarcode_Create();
        ZBarcode_Encode_and_Print(my_symbol, y, 0, 0);
        ZBarcode_Delete(my_symbol);


        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "zint", GeneratorZint);
    }

    NODE_MODULE(addon, init)

}