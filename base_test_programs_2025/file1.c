#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"GET"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"GET"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"-"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"MOD"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"-"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex--];

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex--];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_XXXXXXX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_XXXXXXX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"MOD"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex--];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"_XXXXXXX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"_YYYYYYY"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    return 0;
}