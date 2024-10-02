[BITS 16]
[ORG 0x7C00]

start:
    ; OS 커널을 로드하는 코드
    ; (예: BIOS 인터럽트를 사용하여 커널을 디스크에서 메모리로 로드)

    ; 커널로 점프
    jmp 0x0000:0x7E00

times 510-($-$$) db 0
dw 0xAA55
