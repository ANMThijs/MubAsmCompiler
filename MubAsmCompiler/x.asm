MOV AL, 0xfe    ;set al to 0xfe
MOV CL, 0x00
MOV DL, 0x00
MOV BL, 0x32

MOV AH, 0xaf
MOV CH, 0x00
MOV DH, 0x00
MOV BH, 0x00

INT 0x10
