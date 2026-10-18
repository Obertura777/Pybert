// sub_10005f10 @ 0x10005f10
// hopper name: sub_10005f10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005f10() {
    eax = arg_4;
    ecx = eax[0x3];
    if (ecx != 0x0) {
            do {
                    eax = ecx;
                    ecx = eax[0x3];
            } while (ecx != 0x0);
    }
    ecx = arg_8;
    decomp_var_4 = esi;
    esi = eax[0x1];
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edx = *ecx;
    edi = *eax;
    *eax = edx;
    eax[0x1] = ecx[0x1];
    eax[0x4] = ecx[0x4];
    *eax[0x1] = eax;
    eax[0x3] = ecx[0x3];
    eax[0x8] = ecx[0x8];
    *eax[0x3] = eax;
    edx = *ecx;
    if (edx == 0x0) {
            edx = arg_0;
            edx[0x1] = eax;
    }
    else {
            ebp = edx[0x3];
            edx = *eax;
            esp = (esp - 0x4) + 0x4;
            if (ebp == ecx) {
                    edx[0x3] = eax;
            }
            else {
                    edx[0x1] = eax;
            }
    }
    *ecx = edi;
    ecx[0x1] = esi;
    ecx[0x3] = 0x0;
    if (esi != 0x0) {
            *esi = ecx;
            eax = *ecx;
            ecx[0x4] = 0x1;
            ecx[0x8] = 0x0;
            eax[0x3] = ecx;
    }
    else {
            eax = *ecx;
            ecx[0x4] = 0x0;
            ecx[0x8] = 0x0;
            eax[0x3] = ecx;
    }
    return eax;
}
