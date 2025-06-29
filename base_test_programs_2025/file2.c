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

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"GET"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //"IF"

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex--];

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF63378D490;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
    LABEL__AFTER_THEN_00007FF63378D490:

    //"ELSE" (part of "ELSEIF")
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF63378F1A8;

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex--];

    //null statement (non-context)

    //after cond expresion (after "ELSEIF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF633791F60;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //"}" (after "then"-part of ELSEIF-operator)
    opTemp = 1;
    LABEL__AFTER_ELSE_00007FF63378F1A8:
    LABEL__AFTER_THEN_00007FF633791F60:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF633793C78;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //":="
    lastBindDataIndex = opStack[opStackIndex - 1];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "ELSE")
    LABEL__AFTER_ELSE_00007FF633793C78:

    //"_MAXMAXM"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"IF"

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex--];

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex--];

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex--];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex--];

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex--];

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF63379A888;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
    LABEL__AFTER_THEN_00007FF63379A888:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF63379C178;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "ELSE")
    LABEL__AFTER_ELSE_00007FF63379C178:

    //"IF"

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"OR"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex--];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"OR"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex--];

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF6337A2538;

    //"-1"
    opStack[++opStackIndex] = opTemp = 0xFFFFFFFF;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
    LABEL__AFTER_THEN_00007FF6337A2538:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF6337A3E28;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "ELSE")
    LABEL__AFTER_ELSE_00007FF6337A3E28:

    //"IF"

    //"_AAAAAAA"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_BBBBBBB"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_CCCCCCC"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex--];

    //">="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex--];

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF6337A7C80;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
    LABEL__AFTER_THEN_00007FF6337A7C80:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF6337A9570;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PUT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "ELSE")
    LABEL__AFTER_ELSE_00007FF6337A9570:

    return 0;
}