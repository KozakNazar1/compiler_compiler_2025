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

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"25630"
    opStack[++opStackIndex] = opTemp = 0x0000641E;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"FOR"

    //"24"
    opStack[++opStackIndex] = opTemp = 0x00000018;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF63378E958:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63378D068;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"}" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63378E958;
    LABEL__EXIT_FOR_00007FF63378D068:
    --contextStackIndex;

    //"FOR"

    //"24"
    opStack[++opStackIndex] = opTemp = 0x00000018;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF6337976A8:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF633795DB8;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_KKKKKKK"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"2"
    opStack[++opStackIndex] = opTemp = 0x00000002;

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex--];

    //"-"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex--];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337976A8;
    LABEL__EXIT_FOR_00007FF633795DB8:
    --contextStackIndex;

    //null statement (non-context)

    //"FOR"

    //"24"
    opStack[++opStackIndex] = opTemp = 0x00000018;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF6337A03F8:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63379EB08;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337A03F8;
    LABEL__EXIT_FOR_00007FF63379EB08:
    --contextStackIndex;

    //null statement (non-context)

    return 0;
}