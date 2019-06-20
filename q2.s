.pos 0x0
                 ld   $0x1028, r5             # r5 = &0x1028
                 ld   $0xfffffff4, r0         # r0 = -12
                 add  r0, r5                  # allocate space on stack
                 ld   $0x200, r0              # r0 = &w
                 ld   0x0(r0), r0             # r0 = w
                 st   r0, 0x0(r5)             # arg0 = w
                 ld   $0x204, r0              # r0 = &x
                 ld   0x0(r0), r0             # r0 = x
                 st   r0, 0x4(r5)             # arg1 = x
                 ld   $0x208, r0              # r0 = y
                 ld   0x0(r0), r0             # r0 = y
                 st   r0, 0x8(r5)             # arg2 = y
                 gpc  $6, r6                  # set Return Address
                 j    0x300                   # jump to: r0 = q2(w,x,y)
                 ld   $0x20c, r1              # r1 = &z
                 st   r0, 0x0(r1)             # return z
                 halt
.pos 0x200
                 .long 0x00000000             # w
                 .long 0x00000000             # x
                 .long 0x00000000             # y
                 .long 0x00000000             # z   ;stackbtm
.pos 0x300
q2:              ld   0x0(r5), r0             # r0 = w
                 ld   0x4(r5), r1             # r1 = x
                 ld   0x8(r5), r2             # r2 = y
                 ld   $0xfffffff6, r3         # r3 = -10
                 add  r3, r0                  # r0 = w - 10 = temp_i
                 mov  r0, r3                  # r3 = w - 10
                 not  r3
                 inc  r3                      # r3 = 10 - w
                 bgt  r3, L6                  # if w < 10 goto L6
                 mov  r0, r3                  # r3 = w - 10
                 ld   $0xfffffff8, r4         # r4 = -8
                 add  r4, r3                  # r3 = w - 18
                 bgt  r3, L6                  # if w > 18 goto L6=
                 ld   $0x400, r3              # r3 = 0x400
                 j    *(r3, r0, 4)            # indirect jump to jt[w-10]
.pos 0x330
                 add  r1, r2                  # r2 = x + y
                 br   L7                      # break
                 not  r2
                 inc  r2                      # r2 = - x - y
                 add  r1, r2                  # r2 = - y
                 br   L7                      # break
                 not  r2
                 inc  r2                      # r2 = y
                 add  r1, r2                  # r2 = x + y
                 bgt  r2, L0                  # if x > y goto L0
                 ld   $0x0, r2                # r2 = 0
                 br   L1                      # goto L1
L0:              ld   $0x1, r2                # r2 = 1
L1:              br   L7                      # break
#case 16
                 not  r1
                 inc  r1                      # r1 = - x
                 add  r2, r1                  # r1 = y - x
                 bgt  r1, L2                  # if (y > x) goto L2
                 ld   $0x0, r2                # r2 = 0
                 br   L3                      # goto L3
#case 18
L2:              ld   $0x1, r2                # r2 = 1
L3:              br   L7                      # break
                 not  r2
                 inc  r2                      # r2 = - y
                 add  r1, r2                  # r2 = x - y
                 beq  r2, L4                  # if x == y goto L4
                 ld   $0x0, r2                # r2 = 0
                 br   L5                      # goto L5
L4:              ld   $0x1, r2                # r2 = 1
L5:              br   L7                      # break
L6:              ld   $0x0, r2                # r2 = 0
                 br   L7                      # break
L7:              mov  r2, r0                  # r0 = return value
                 j    0x0(r6)                 # return to RA
.pos 0x400
jt:              .long 0x00000330             # case 10
                 .long 0x00000384             # default
                 .long 0x00000334             # case 12
                 .long 0x00000384             # default
                 .long 0x0000033c             # case 14
                 .long 0x00000384             # default
                 .long 0x00000354             # case 16
                 .long 0x00000384             # default
                 .long 0x0000036c             # case 18
.pos 0x1000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
                 .long 0x00000000
