P    1 | ld 0 r3
ADV 7 (0x0000 -> 0x0007) 02 90 00 00 00 00 03 
P    1 | zjmp 80 OK
P    1 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    1 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    1 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    1 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    1 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    1 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    1 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    1 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    1 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    1 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    1 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    1 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    1 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    1 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    1 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    1 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    1 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    2 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    2 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    2 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    2 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    2 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    1 | fork 40 (230)
ADV 3 (0x00be -> 0x00c1) 0c 00 28 
P    1 | live 4
ADV 5 (0x00c1 -> 0x00c6) 01 00 00 00 04 
P    2 | live 42
ADV 5 (0x00e6 -> 0x00eb) 01 00 00 00 2a 
P    2 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    2 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    3 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    3 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    3 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    3 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    3 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    1 | fork 69 (267)
ADV 3 (0x00c6 -> 0x00c9) 0c 00 45 
P    2 | fork 61 (296)
ADV 3 (0x00eb -> 0x00ee) 0c 00 3d 
P    1 | live 42
ADV 5 (0x00c9 -> 0x00ce) 01 00 00 00 2a 
P    4 | live 42
ADV 5 (0x010b -> 0x0110) 01 00 00 00 2a 
P    2 | live 42
ADV 5 (0x00ee -> 0x00f3) 01 00 00 00 2a 
P    3 | live 42
ADV 5 (0x0128 -> 0x012d) 01 00 00 00 2a 
P    1 | ldi 8 65343 r15
ADV 7 (0x00ce -> 0x00d5) 0a a4 00 08 ff 3f 0f 
P    4 | ldi 12 65277 r15
ADV 7 (0x0110 -> 0x0117) 0a a4 00 0c fe fd 0f 
P    2 | ldi 4 65306 r15
ADV 7 (0x00f3 -> 0x00fa) 0a a4 00 04 ff 1a 0f 
P    3 | ldi 0 65248 r15
ADV 7 (0x012d -> 0x0134) 0a a4 00 00 fe e0 0f 
P    1 | ld -186 r14
ADV 7 (0x00d5 -> 0x00dc) 02 90 ff ff ff 46 0e 
P    4 | ld -182 r14
ADV 7 (0x0117 -> 0x011e) 02 90 ff ff ff 4a 0e 
P    2 | ld -190 r14
ADV 7 (0x00fa -> 0x0101) 02 90 ff ff ff 42 0e 
P    3 | ld -194 r14
ADV 7 (0x0134 -> 0x013b) 02 90 ff ff ff 3e 0e 
P    1 | ld 0 r2
ADV 7 (0x00dc -> 0x00e3) 02 90 00 00 00 00 02 
P    4 | ld 0 r2
ADV 7 (0x011e -> 0x0125) 02 90 00 00 00 00 02 
P    2 | ld 0 r2
ADV 7 (0x0101 -> 0x0108) 02 90 00 00 00 00 02 
P    3 | ld 0 r2
ADV 7 (0x013b -> 0x0142) 02 90 00 00 00 00 02 
P    1 | zjmp -220 OK
P    4 | zjmp -286 OK
P    2 | zjmp -257 OK
P    3 | zjmp -315 OK
P    2 | fork 40 (230)
ADV 3 (0x00be -> 0x00c1) 0c 00 28 
P    2 | live 4
ADV 5 (0x00c1 -> 0x00c6) 01 00 00 00 04 
P    5 | live 42
ADV 5 (0x00e6 -> 0x00eb) 01 00 00 00 2a 
P    1 | zjmp 80 OK
P    4 | zjmp 80 OK
P    2 | zjmp 80 OK
P    3 | zjmp 80 OK
P    1 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    4 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    2 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    3 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    3 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    1 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    4 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    2 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    3 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    3 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    4 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    1 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    4 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    2 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    3 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    4 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    4 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    1 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    4 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    2 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    3 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    4 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    4 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    1 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    4 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    2 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    3 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    1 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    4 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    2 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    3 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    1 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    4 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    2 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    3 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    1 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    4 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    2 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    3 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    1 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    4 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    2 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    3 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    1 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    4 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    2 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    3 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    1 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    4 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    2 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    3 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    1 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    4 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    2 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    3 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    1 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    4 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    2 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    3 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    1 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    4 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    2 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    3 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    1 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    4 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    2 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    3 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    2 | fork 69 (267)
ADV 3 (0x00c6 -> 0x00c9) 0c 00 45 
P    5 | fork 61 (296)
ADV 3 (0x00eb -> 0x00ee) 0c 00 3d 
P    2 | live 42
ADV 5 (0x00c9 -> 0x00ce) 01 00 00 00 2a 
P    6 | live 42
ADV 5 (0x010b -> 0x0110) 01 00 00 00 2a 
P    5 | live 42
ADV 5 (0x00ee -> 0x00f3) 01 00 00 00 2a 
P    6 | live 42
ADV 5 (0x0128 -> 0x012d) 01 00 00 00 2a 
P    2 | ldi 8 65343 r15
ADV 7 (0x00ce -> 0x00d5) 0a a4 00 08 ff 3f 0f 
P    6 | ldi 12 65277 r15
ADV 7 (0x0110 -> 0x0117) 0a a4 00 0c fe fd 0f 
P    5 | ldi 4 65306 r15
ADV 7 (0x00f3 -> 0x00fa) 0a a4 00 04 ff 1a 0f 
P    6 | ldi 0 65248 r15
ADV 7 (0x012d -> 0x0134) 0a a4 00 00 fe e0 0f 
P    2 | ld -186 r14
ADV 7 (0x00d5 -> 0x00dc) 02 90 ff ff ff 46 0e 
P    6 | ld -182 r14
ADV 7 (0x0117 -> 0x011e) 02 90 ff ff ff 4a 0e 
P    5 | ld -190 r14
ADV 7 (0x00fa -> 0x0101) 02 90 ff ff ff 42 0e 
P    6 | ld -194 r14
ADV 7 (0x0134 -> 0x013b) 02 90 ff ff ff 3e 0e 
P    2 | ld 0 r2
ADV 7 (0x00dc -> 0x00e3) 02 90 00 00 00 00 02 
P    6 | ld 0 r2
ADV 7 (0x011e -> 0x0125) 02 90 00 00 00 00 02 
P    5 | ld 0 r2
ADV 7 (0x0101 -> 0x0108) 02 90 00 00 00 00 02 
P    6 | ld 0 r2
ADV 7 (0x013b -> 0x0142) 02 90 00 00 00 00 02 
P    2 | zjmp -220 OK
P    6 | zjmp -286 OK
P    5 | zjmp -257 OK
P    6 | zjmp -315 OK
P    3 | fork 40 (230)
ADV 3 (0x00be -> 0x00c1) 0c 00 28 
P    3 | live 4
ADV 5 (0x00c1 -> 0x00c6) 01 00 00 00 04 
P    4 | live 42
ADV 5 (0x00e6 -> 0x00eb) 01 00 00 00 2a 
P    2 | zjmp 80 OK
P    6 | zjmp 80 OK
P    5 | zjmp 80 OK
P    6 | zjmp 80 OK
P    2 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    6 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    5 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    6 | sti r1 -74 1
       | -> store to -74 + 1 = -73 (with pc and mod 14)
ADV 7 (0x0057 -> 0x005e) 0b 68 01 ff b6 00 01 
P    4 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    2 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    6 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    5 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    6 | sti r1 -81 15
       | -> store to -81 + 15 = -66 (with pc and mod 28)
ADV 7 (0x005e -> 0x0065) 0b 68 01 ff af 00 0f 
P    4 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    5 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    2 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    6 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    5 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    6 | sti r1 -88 29
       | -> store to -88 + 29 = -59 (with pc and mod 42)
ADV 7 (0x0065 -> 0x006c) 0b 68 01 ff a8 00 1d 
P    5 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    5 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    2 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    6 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    5 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    6 | sti r1 -95 43
       | -> store to -95 + 43 = -52 (with pc and mod 56)
ADV 7 (0x006c -> 0x0073) 0b 68 01 ff a1 00 2b 
P    5 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    5 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    2 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    6 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    5 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    6 | sti r1 -102 57
       | -> store to -102 + 57 = -45 (with pc and mod 70)
ADV 7 (0x0073 -> 0x007a) 0b 68 01 ff 9a 00 39 
P    2 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    6 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    5 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    6 | sti r1 -109 71
       | -> store to -109 + 71 = -38 (with pc and mod 84)
ADV 7 (0x007a -> 0x0081) 0b 68 01 ff 93 00 47 
P    2 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    6 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    5 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    6 | ld 393216 r4
ADV 7 (0x0081 -> 0x0088) 02 90 00 06 00 00 04 
P    2 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    6 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    5 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    6 | ld 917504 r12
ADV 7 (0x0088 -> 0x008f) 02 90 00 0e 00 00 0c 
P    2 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    6 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    5 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    6 | ld 1 r11
ADV 7 (0x008f -> 0x0096) 02 90 00 00 00 01 0b 
P    1 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    4 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    2 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    3 | fork -25 (157)
ADV 3 (0x00b6 -> 0x00b9) 0c ff e7 
P    2 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    6 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    5 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    6 | ld 6 r10
ADV 7 (0x0096 -> 0x009d) 02 90 00 00 00 06 0a 
P    1 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    7 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    4 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    7 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    2 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    3 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    3 | live 3
ADV 5 (0x00b9 -> 0x00be) 01 00 00 00 03 
P    7 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    2 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    6 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    5 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    6 | live 42
ADV 5 (0x009d -> 0x00a2) 01 00 00 00 2a 
P    7 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    7 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    3 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    7 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    2 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    6 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    5 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    6 | sti r4 -155 1
       | -> store to -155 + 1 = -154 (with pc and mod 8)
ADV 7 (0x00a2 -> 0x00a9) 0b 68 04 ff 65 00 01 
P    7 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    7 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    3 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    7 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    2 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    6 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    5 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    6 | add r4 r12 r4
ADV 5 (0x00a9 -> 0x00ae) 04 54 04 0c 04 
P    7 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    7 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    3 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    7 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    2 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    6 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    5 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    6 | sub r10 r11 r10
ADV 5 (0x00ae -> 0x00b3) 05 54 0a 0b 0a 
P    7 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    7 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    3 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    7 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    2 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    6 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    5 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
P    6 | zjmp -50 FAILED
ADV 3 (0x00b3 -> 0x00b6) 09 ff ce 
