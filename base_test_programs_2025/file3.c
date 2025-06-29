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

    //"FOR"

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF63378BBA0:

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63378A2B0;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"_CYCLEAA"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_CYCLEAA"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63378BBA0;
    LABEL__EXIT_FOR_00007FF63378A2B0:
    --contextStackIndex;

    //null statement (non-context)

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"FOR"

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF633791710:

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63378FE20;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"FOR"

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF6337944C8:

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF633792BD8;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"_XVALUEE"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337944C8;
    LABEL__EXIT_FOR_00007FF633792BD8:
    --contextStackIndex;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF633791710;
    LABEL__EXIT_FOR_00007FF63378FE20:
    --contextStackIndex;

    //null statement (non-context)

    //"_XVALUEE"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    return 0;
}