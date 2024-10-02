[BITS 32]
[GLOBAL start]

start:
    ; 커널 C 코드로 진입하기 위해 스택 설정 및 메모리 초기화
    call kernel_main

hang:
    jmp hang
