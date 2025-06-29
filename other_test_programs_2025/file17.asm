.686
.model flat, stdcall
option casemap : none

GetStdHandle proto STDCALL, nStdHandle : DWORD
ExitProcess proto STDCALL, uExitCode : DWORD
;MessageBoxA PROTO hwnd : DWORD, lpText : DWORD, lpCaption : DWORD, uType : DWORD
ReadConsoleA proto STDCALL, hConsoleInput : DWORD, lpBuffer : DWORD, nNumberOfCharsToRead : DWORD, lpNumberOfCharsRead : DWORD, lpReserved : DWORD
WriteConsoleA proto STDCALL, hConsoleOutput : DWORD, lpBuffert : DWORD, nNumberOfCharsToWrite : DWORD, lpNumberOfCharsWritten : DWORD, lpReserved : DWORD
wsprintfA PROTO C : VARARG

GetConsoleMode PROTO STDCALL, hConsoleHandle:DWORD, lpMode : DWORD

SetConsoleMode PROTO STDCALL, hConsoleHandle:DWORD, dwMode : DWORD

ENABLE_LINE_INPUT EQU 0002h
ENABLE_ECHO_INPUT EQU 0004h

.data
    data_start db 8192 dup (0)
    ;title_msg db "Output:", 0
    valueTemp_msg db 256 dup(0)
    valueTemp_fmt db "%d", 10, 13, 0
    ;NumberOfCharsWritten dd 0
    hConsoleInput dd 0
    hConsoleOutput dd 0
    buffer db 128 dup(0)
    readOutCount dd ?

.code
start:

    db 0E8h, 00h, 00h, 00h, 00h; call NexInstruction
;NexInstruction:
    pop esi
    sub esi, 5
    mov edi, esi
    add edi, 000004000h
    mov ecx, edi
    add ecx, 24576
    jmp initConsole
    putProc PROC
        push eax
        push offset valueTemp_fmt
        push offset valueTemp_msg
        call wsprintfA
        add esp, 12

        ;push 40h
        ;push offset title_msg
        ;push offset valueTemp_msg;
        ;push 0
        ;call MessageBoxA

        push 0
        push 0; offset NumberOfCharsWritten
        push eax; NumberOfCharsToWrite
        push offset valueTemp_msg
        push hConsoleOutput
        call WriteConsoleA

        ret
    putProc ENDP


    getProc PROC
        push ebp
        mov ebp, esp

        push 0
        push offset readOutCount
        push 15
        push offset buffer + 1
        push hConsoleInput
        call ReadConsoleA

        lea esi, offset buffer
        add esi, readOutCount
        sub esi, 2
        call string_to_int

        mov esp, ebp
        pop ebp
        ret
    getProc ENDP

    string_to_int PROC
    ;  input: ESI - string
    ; output: EAX - value
        xor eax, eax
        mov ebx, 1
        xor ecx, ecx

convert_loop :
        movzx ecx, byte ptr[esi]
        cmp ecx, '+'
        jz done
        cmp ecx, '-'
        jz neg_and_done
        test ecx, ecx
        jz done
        sub ecx, '0'
        imul ecx, ebx
        add eax, ecx
        imul ebx, ebx, 10
        dec esi
        jmp convert_loop

neg_and_done:
        neg eax
done:
        ret
    string_to_int ENDP

    initConsole:
    push -10
    call GetStdHandle
    mov hConsoleInput, eax
    push -11
    call GetStdHandle
    mov hConsoleOutput, eax
    
    ;push ecx
    ;push ebx
    ;push esi
    ;push edi
    ;push offset mode
    ;push hConsoleInput
    ;call GetConsoleMode
    ;mov ebx, eax
    ;or ebx, ENABLE_LINE_INPUT 
    ;or ebx, ENABLE_ECHO_INPUT
    ;push ebx
    ;push hConsoleInput
    ;call SetConsoleMode
    ;pop edi
    ;pop esi
    ;pop ebx
    ;pop ecx

    ;hw stack save(save esp)
    mov ebp, esp

    ;"4"
    add ecx, 4
    mov eax, 000000004h
    mov dword ptr [ecx], eax

    ;"23"
    add ecx, 4
    mov eax, 000000017h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"FOR"

    ;"20"
    add ecx, 4
    mov eax, 000000014h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF63378E530:

    ;"9"
    add ecx, 4
    mov eax, 000000009h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF63378CC40
    inc dword ptr [ebx]

    ;"8"
    add ecx, 4
    mov eax, 000000008h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX"
    mov eax, dword ptr[ecx]
    imul eax, 128
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"_TOVALUE"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF63378E530
    LABEL@EXIT_FOR_00007FF63378CC40:
    add esp, 4; add esp, 8

    ;null statement (non-context)

    ;"FOR"

    ;"20"
    add ecx, 4
    mov eax, 000000014h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF633793000:

    ;"9"
    add ecx, 4
    mov eax, 000000009h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF633791710
    inc dword ptr [ebx]

    ;"12"
    add ecx, 4
    mov eax, 00000000Ch
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX"
    mov eax, dword ptr[ecx]
    imul eax, 128
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"_TOVALUE"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF633793000
    LABEL@EXIT_FOR_00007FF633791710:
    add esp, 4; add esp, 8

    ;null statement (non-context)

    ;"FOR"

    ;"20"
    add ecx, 4
    mov eax, 000000014h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF633797AD0:

    ;"9"
    add ecx, 4
    mov eax, 000000009h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF6337961E0
    inc dword ptr [ebx]

    ;"FOR"

    ;"24"
    add ecx, 4
    mov eax, 000000018h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF63379A888:

    ;"9"
    add ecx, 4
    mov eax, 000000009h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF633798F98
    inc dword ptr [ebx]

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_JINDEXT"
    mov eax, edi
    add eax, 000000018h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"+"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"INDEX"
    mov eax, dword ptr[ecx]
    imul eax, 128
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_JINDEXT"
    mov eax, edi
    add eax, 000000018h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"+"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"8"
    add ecx, 4
    mov eax, 000000008h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"12"
    add ecx, 4
    mov eax, 00000000Ch
    mov dword ptr [ecx], eax

    ;"_JINDEXT"
    mov eax, edi
    add eax, 000000018h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"*"
    mov eax, dword ptr[ecx - 4]
    ;cdq
    imul dword ptr [ecx]
    sub ecx, 4
    mov dword ptr [ecx], eax

    ;"+"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF63379A888
    LABEL@EXIT_FOR_00007FF633798F98:
    add esp, 4; add esp, 8

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF633797AD0
    LABEL@EXIT_FOR_00007FF6337961E0:
    add esp, 4; add esp, 8

    ;null statement (non-context)

    ;"28"
    add ecx, 4
    mov eax, 00000001Ch
    mov dword ptr [ecx], eax

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"9"
    add ecx, 4
    mov eax, 000000009h
    mov dword ptr [ecx], eax

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"_TOVALUE"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"DIV"
    mov eax, dword ptr[ecx - 4]
    cdq
    idiv dword ptr [ecx]
    sub ecx, 4
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"FOR"

    ;"20"
    add ecx, 4
    mov eax, 000000014h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF6337A5718:

    ;"18"
    add ecx, 4
    mov eax, 000000012h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF6337A3E28
    inc dword ptr [ebx]

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX"
    mov eax, dword ptr[ecx]
    imul eax, 128
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"_NORMVAL"
    mov eax, edi
    add eax, 00000001Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"DIV"
    mov eax, dword ptr[ecx - 4]
    cdq
    idiv dword ptr [ecx]
    sub ecx, 4
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF6337A5718
    LABEL@EXIT_FOR_00007FF6337A3E28:
    add esp, 4; add esp, 8

    ;null statement (non-context)

    ;";"

    ;"FOR"

    ;"20"
    add ecx, 4
    mov eax, 000000014h
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;":="
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;"TO" (after "FOR")
    dec dword ptr [ebx]
    push ebx
    LABEL@AFTER_TO_00007FF6337AB6B0:

    ;"18"
    add ecx, 4
    mov eax, 000000012h
    mov dword ptr [ecx], eax

    ;null statement (non-context)

    ;"DO" (after "TO" after "FOR")
    mov ebx, dword ptr [esp]
    cmp dword ptr [ebx], eax
    jge LABEL@EXIT_FOR_00007FF6337A9DC0
    inc dword ptr [ebx]

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"_IINDEXT"
    mov eax, edi
    add eax, 000000014h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"INDEX_TO_VALUE"
    mov eax, dword ptr[ecx]
    mov ebx, dword ptr[ecx - 4]
    imul eax, 128
    sub ecx, 4
    add ebx, edi
    add ebx, eax
    mov eax, dword ptr[ebx]
    mov dword ptr[ecx], eax

    ;"PUT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;"NULL" (after "FOR")
    jmp LABEL@AFTER_TO_00007FF6337AB6B0
    LABEL@EXIT_FOR_00007FF6337A9DC0:
    add esp, 4; add esp, 8

    ;null statement (non-context)

    ;hw stack reset(restore esp)
    mov esp, ebp

    xor eax, eax
    ret


end start


