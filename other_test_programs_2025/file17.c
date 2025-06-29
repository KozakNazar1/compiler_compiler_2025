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

    //"23"
    opStack[++opStackIndex] = opTemp = 0x00000017;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"FOR"

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF63378E530:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF63378CC40;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_TOVALUE"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63378E530;
    LABEL__EXIT_FOR_00007FF63378CC40:
    --contextStackIndex;

    //null statement (non-context)

    //"FOR"

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF633793000:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF633791710;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"_TOVALUE"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF633793000;
    LABEL__EXIT_FOR_00007FF633791710:
    --contextStackIndex;

    //null statement (non-context)

    //"FOR"

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF633797AD0:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF6337961E0;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

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
    LABEL__AFTER_TO_00007FF63379A888:

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF633798F98;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"_JINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"_JINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"_JINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000018];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"*"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex--];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF63379A888;
    LABEL__EXIT_FOR_00007FF633798F98:
    --contextStackIndex;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF633797AD0;
    LABEL__EXIT_FOR_00007FF6337961E0:
    --contextStackIndex;

    //null statement (non-context)

    //"28"
    opStack[++opStackIndex] = opTemp = 0x0000001C;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"9"
    opStack[++opStackIndex] = opTemp = 0x00000009;

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"_TOVALUE"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"FOR"

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF6337A5718:

    //"18"
    opStack[++opStackIndex] = opTemp = 0x00000012;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF6337A3E28;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX"
    opTemp = opStack[opStackIndex - 1] += 128 * opStack[opStackIndex--]);

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"_NORMVAL"
    opStack[++opStackIndex] = opTemp = data[0x0000001C];

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex--];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337A5718;
    LABEL__EXIT_FOR_00007FF6337A3E28:
    --contextStackIndex;

    //null statement (non-context)

    //";"

    //"FOR"

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"TO" (after "FOR")
    --data[lastBindDataIndex];
    contextStack[++contextStackIndex] = lastBindDataIndex;
    LABEL__AFTER_TO_00007FF6337AB6B0:

    //"18"
    opStack[++opStackIndex] = opTemp = 0x00000012;

    //null statement (non-context)

    //"DO" (after "TO" after "FOR")
    if (data/*OLD: opStack*/[contextStack[contextStackIndex]] >= opTemp) goto LABEL__EXIT_FOR_00007FF6337A9DC0;
    ++data/*OLD: opStack*/[contextStack[contextStackIndex]];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_IINDEXT"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"INDEX_TO_VALUE"
    opTemp = opStack[opStackIndex - 1] = data[opStack[opStackIndex - 1] += (128 * opStack[opStackIndex--])];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //"NULL" (after "FOR")
    goto LABEL__AFTER_TO_00007FF6337AB6B0;
    LABEL__EXIT_FOR_00007FF6337A9DC0:
    --contextStackIndex;

    //null statement (non-context)

    return 0;
}