// sub_10005980 @ 0x10005980
// hopper name: sub_10005980
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005980() {
    esi = malloc(0x3c);
    esp = (esp - 0xc) + 0x4;
    if (esi != 0x0) {
            eax = (*0x1000916c)();
            esi[0x1] = eax;
            if (eax == 0x0) {
                    free(esi);
                    eax = 0x0;
            }
            else {
                    esi[0x2] = 0x0;
                    esi[0x3] = 0x0;
                    esi[0x4] = 0x0;
                    esi[0xc] = 0x4;
                    esi[0x7] = 0x0;
                    *esi = 0xffffffff;
                    if (*(*arg_8 + 0x20) != 0x0) {
                            esi[0x20] = 0x1;
                    }
                    else {
                            esi[0x20] = 0x0;
                    }
                    *(esi + 0x22) = 0x0;
                    *(esi + 0x26) = 0x0;
                    *(esi + 0x2a) = 0x0;
                    *(esi + 0x2e) = 0x0;
                    esi[0xd] = 0x10;
                    esi[0xe] = 0x0;
                    eax = esi;
            }
    }
    else {
            eax = esi;
    }
    return eax;
}
