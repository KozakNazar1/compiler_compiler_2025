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
    LABEL__AFTER_TO_00007FF63378A2B0:

    //"5"
    opStack[++opStackIndex] = opTemp = 0x00000005;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF6337889C0;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"_CYINDEX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"GET"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63378A2B0;
    LABEL__EXIT_FOR_00007FF6337889C0:
    --contextStackIndex;

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
    LABEL__AFTER_TO_00007FF63378E958:

    //"5"
    opStack[++opStackIndex] = opTemp = 0x00000005;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63378D068;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_CYINDEX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"2"
    opStack[++opStackIndex] = opTemp = 0x00000002;

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"_CYINDEX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63378E958;
    LABEL__EXIT_FOR_00007FF63378D068:
    --contextStackIndex;

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
    LABEL__AFTER_TO_00007FF6337944C8:

    //"5"
    opStack[++opStackIndex] = opTemp = 0x00000005;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF633792BD8;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_CYINDEX"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337944C8;
    LABEL__EXIT_FOR_00007FF633792BD8:
    --contextStackIndex;

    //null statement (non-context)

    return 0;
}