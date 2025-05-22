       dcd     1
       dcd     2
       dcd     1
       dcd     100000
       dcd     6
       dcd     8
       dcd     10
       dcd     100

       mov     R1, #0X200
       mov     R2, #4
       mov     R3, R1
       ADD     R3, R3, #2

       ADD     R3, R1, #0x1C
loop   LDR     R0, [R3, #-4]
       STR     R0, [R3], #-4
       CMP     R1, R3
       Bne     loop
