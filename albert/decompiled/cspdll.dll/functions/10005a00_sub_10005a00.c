// sub_10005a00 @ 0x10005a00
// hopper name: sub_10005a00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005a00() {
    decomp_var_4 = ebp;
    ebp = arg_0;
    esp = esp - 0xc;
    esi = *(ebp + arg_4 * 0x4 + 0x4);
    eax = *esi;
    if (eax != 0xffffffff) {
            esp = esp - 0x4;
            (*0x10009130)();
    }
    esp = esp - 0x4;
    (*0x10009168)(esi[0x1]);
    eax = esi[0x3];
    if (eax != 0x0) {
            do {
                    ecx = *eax;
                    esi[0x3] = ecx;
                    if (ecx == 0x0) {
                            esi[0x4] = ecx;
                    }
                    *eax = 0x0;
                    eax = esi[0x3];
            } while (eax != 0x0);
    }
    eax = esi[0x7];
    if (eax != 0x0) {
            free(eax);
            esp = (esp - 0x4) + 0x4;
            esi[0x7] = 0x0;
    }
    if (*(*ebp + 0x44) != 0x0) {
            fclose(esi[0xe]);
            esp = (esp - 0x4) + 0x4;
    }
    eax = free(esi);
    return eax;
}
