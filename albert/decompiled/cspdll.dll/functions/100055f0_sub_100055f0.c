// sub_100055f0 @ 0x100055f0
// hopper name: sub_100055f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100055f0() {
    ebx = sub_10005a90();
    edi = malloc(0x20);
    esp = (esp - 0xc) + 0x4 - 0x4;
    saved_fp = 0x1c;
    *(int8_t *)edi = 0xff;
    eax = (*0x10009140)();
    edx = arg_8;
    edi[0x1] = eax;
    edi[0x4] = arg_10;
    edi[0x1] = arg_14;
    bool_2 = true;
    bool_1 = true;
    eax = arg_c;
    *ebx = 0x0;
    ebx[0x2] = edi;
    ebx[0x2] = 0x20;
    if (arg_10 == 0x4) {
            ecx = *(edx + eax * 0x4 + 0x4);
            esp = esp - 0x8;
            ecx = ecx[0xd];
            *(edi + 0x1c) = ecx;
            esi = *(edx + eax * 0x4 + 0x4);
            *(edi + 0xa) = *(esi + 0x22);
            asm { rep movsb  byte [edi], byte [esi] };
            esp = esp + 0x8;
    }
    eax = sub_10005680(edx, ebx, eax, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14);
    return eax;
}
