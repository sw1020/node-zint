//
// Created by stephen on 15/12/11.
//

#ifndef NODE_ZINT_NODE_ZINT_H
#define NODE_ZINT_NODE_ZINT_H

#endif //NODE_ZINT_NODE_ZINT_H
namespace node_zint{
    enum SYMBOLOGY_CODE{
        BARCODE_CODE11 =1,    /* Code 11  */
            BARCODE_C25MATRIX =2,    /* Standard Code 2 of 5  */
            BARCODE_C25INTER=3,    /* Interleaved 2 of 5  */
            BARCODE_C25IATA =4,    /* Code 2 of 5 IATA  */
            BARCODE_C25LOGIC=6,    /* Code 2 of 5 Data Logic  */
            BARCODE_C25IND=7,    /* Code 2 of 5 Industrial  */
            BARCODE_CODE39=8,    /* Code 3 of 9 (Code 39)  */
            BARCODE_EXCODE39 =9,    /* Extended Code 3 of 9 (Code 39+)  */
            BARCODE_EANX=13,    /* EAN  */
            BARCODE_EAN128 =16,    /* GS1-128  */
            BARCODE_CODABAR =18,    /* Codabar  */
            BARCODE_CODE128 =20,    /* Code 128 (automatic subset switching)  */
            BARCODE_DPLEIT=21,    /* Deutshe Post Leitcode  */
            BARCODE_DPIDENT=22,    /* Deutshe Post Identcode  */
            BARCODE_CODE16K =23,    /* Code 16K  */
            BARCODE_CODE49=24,    /* Code 49  */
            BARCODE_CODE93=25,    /* Code 93  */
            BARCODE_FLAT=28,    /* Flattermarken  */
            BARCODE_RSS14 =29,    /* GS1 DataBar-14  */
            BARCODE_RSS_LTD =30,    /* GS1 DataBar Limited  */
            BARCODE_RSS_EXP=31,    /* GS1 DataBar Expanded  */
            BARCODE_TELEPEN=32,    /* Telepen Alpha  */
            BARCODE_UPCA=34,    /* UPC A  */
            BARCODE_UPCE=37,    /* UPC E  */
            BARCODE_POSTNET =40,    /* PostNet  */
            BARCODE_MSI_PLESSEY =47,    /* MSI Plessey  */
            BARCODE_FIM =49,    /* FIM  */
            BARCODE_LOGMARS=50,    /* LOGMARS  */
            BARCODE_PHARMA=51,    /* Pharmacode One-Track  */
            BARCODE_PZN =52,    /* PZN  */
            BARCODE_PHARMA_TWO =53,    /* Pharmacode Two-Track  */
            BARCODE_PDF417 =55,    /* PDF417  */
            BARCODE_PDF417TRUNC =56,    /* PDF417 Truncated  */
            BARCODE_MAXICODE=57,    /* Maxicode  */
            BARCODE_QRCODE =58,    /* QR Code  */
            BARCODE_CODE128B =60,    /* Code 128 (Subset B)  */
            BARCODE_AUSPOST =63,    /* Australia Post Standard Customer  */
            BARCODE_AUSREPLY =66,    /* Australia Post Reply Paid  */
            BARCODE_AUSROUTE =67,    /* Australia Post Routing  */
            BARCODE_AUSREDIRECT =68,    /* Australia Post Redirection  */
            BARCODE_ISBNX=69,    /* ISBN (EAN-13 with verification stage)  */
            BARCODE_RM4SCC=70,    /* Royal Mail 4 State (RM4SCC)  */
            BARCODE_DATAMATRIX =71,    /* Data Matrix  */
            BARCODE_EAN14 =72,    /* EAN-14  */
            BARCODE_NVE18 =75,    /* NVE-18  */
            BARCODE_JAPANPOST =76,    /* Japanese Post  */
            BARCODE_KOREAPOST =77,    /* Korea Post  */
            BARCODE_RSS14STACK =79,    /* GS1 DataBar-14 Stacked  */
            BARCODE_RSS14STACK_OMNI =80,    /* GS1 DataBar-14 Stacked Omnidirectional  */
            BARCODE_RSS_EXPSTACK =81,    /* GS1 DataBar Expanded Stacked  */
            BARCODE_PLANET =82,    /* PLANET  */
            BARCODE_MICROPDF417 =84,    /* MicroPDF417  */
            BARCODE_ONECODE=85,    /* USPS OneCode  */
            BARCODE_PLESSEY=86,    /* Plessey Code  */
            BARCODE_TELEPEN_NUM =87,    /* Telepen Numeric  */
            BARCODE_ITF14 =89,    /* ITF-14  */
            BARCODE_KIX =90,    /* Dutch Post KIX Code  */
            BARCODE_AZTEC=92,    /* Aztec Code  */
            BARCODE_DAFT =93,    /* DAFT Code  */
            BARCODE_MICROQR =97,    /* Micro QR Code  */
            BARCODE_HIBC_128 =98,    /* HIBC Code 128  */
            BARCODE_HIBC_39=99,    /* HIBC Code 39  */
            BARCODE_HIBC_DM=102,    /* HIBC Data Matrix  */
            BARCODE_HIBC_QR=104,    /* HIBC QR Code  */
            BARCODE_HIBC_PDF=106,    /* HIBC PDF417  */
            BARCODE_HIBC_MICPDF =108,    /* HIBC MicroPDF417  */
            BARCODE_HIBC_AZTEC =112,    /* HIBC Aztec Code  */
            BARCODE_AZRUNE =128,    /* Aztec Runes  */
            BARCODE_CODE32=129,    /* Code 32  */
            BARCODE_EANX_CC=130,    /* Composite Symbol with EAN linear component  */
            BARCODE_EAN128_CC =131,    /* Composite Symbol with GS1-128 linear component  */
            BARCODE_RSS14_CC =132,    /* Composite Symbol with GS1 DataBar-14 linear component  */
            BARCODE_RSS_LTD_CC =133,    /* Composite Symbol with GS1 DataBar Limited component  */
            BARCODE_RSS_EXP_CC =134,    /* Composite Symbol with GS1 DataBar Extended component  */
            BARCODE_UPCA_CC=135,    /* Composite Symbol with UPC A linear component  */
            BARCODE_UPCE_CC=136,    /* Composite Symbol with UPC E linear component  */
            BARCODE_RSS14STACK_CC =137,    /* Composite Symbol with GS1 DataBar-14 Stacked component  */
            BARCODE_RSS14_OMNI_CC =138,    /* Composite Symbol with GS1 DataBar-14 Stacked Omnidirectional component  */
            BARCODE_RSS_EXPSTACK_CC =139,    /* Composite Symbol with GS1 DataBar Expanded Stacked component  */
            BARCODE_CHANNEL =140,    /* Channel Code  */
            BARCODE_CODEONE=141,    /* Code One  */
            BARCODE_GRIDMATRIX =142,    /* Grid Matrix  */
    };
}