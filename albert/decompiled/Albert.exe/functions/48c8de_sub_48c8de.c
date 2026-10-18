// sub_48c8de @ 0x48c8de
// hopper name: sub_48c8de
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c8de() {
    edx = arg_4;
    eax = edx[0x3] & 0xffff;
    decomp_var_8 = ebx;
    decomp_var_c = esi;
    esp = esp - 0xc;
    decomp_var_10 = edi;
    ecx = eax >> 0x4 & 0x7ff;
    arg_4 = eax & 0x8000;
    eax = edx[0x1];
    edx = *edx;
    ebx = ecx & 0xffff;
    eax = eax & 0xfffff;
    var_4 = 0x80000000;
    if (ebx != 0x0) {
            if (ebx != 0x7ff) {
                    ecx = ecx + 0x3c00;
                    edi = ecx & 0xffff;
            }
            else {
                    edi = 0x7fff;
            }
            ecx = edx >> 0x15 | eax << 0xb | var_4;
            eax = arg_0;
            eax[0x1] = ecx;
            *eax = edx << 0xb;
            if ((0x80000000 & ecx) == 0x0) {
                    ecx = *eax;
                    edx = eax[0x1];
                    edi = edi + 0xffff;
                    eax[0x1] = edx + edx | ecx >> 0x1f;
                    *eax = ecx + ecx;
                    if ((0x80000000 & (edx + edx | ecx >> 0x1f)) == 0x0) {
                            continue;
                    }
                    break;
            }
            ecx = arg_4 | edi;
            eax[0x4] = ecx;
    }
    else {
            if (eax == 0x0) {
                    if (edx == 0x0) {
                            eax = arg_0;
                            ecx = arg_4;
                            eax[0x1] = 0x0;
                            *eax = 0x0;
                            eax[0x4] = ecx;
                    }
                    else {
                            ecx = ecx + 0x3c01;
                            var_4 = 0x0;
                            edi = ecx & 0xffff;
                            ecx = edx >> 0x15 | eax << 0xb | var_4;
                            eax = arg_0;
                            eax[0x1] = ecx;
                            *eax = edx << 0xb;
                            if ((0x80000000 & ecx) == 0x0) {
                                    ecx = *eax;
                                    edx = eax[0x1];
                                    edi = edi + 0xffff;
                                    eax[0x1] = edx + edx | ecx >> 0x1f;
                                    *eax = ecx + ecx;
                                    if ((0x80000000 & (edx + edx | ecx >> 0x1f)) == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            ecx = arg_4 | edi;
                            eax[0x4] = ecx;
                    }
            }
            else {
                    ecx = ecx + 0x3c01;
                    var_4 = 0x0;
                    edi = ecx & 0xffff;
                    ecx = edx >> 0x15 | eax << 0xb | var_4;
                    eax = arg_0;
                    eax[0x1] = ecx;
                    *eax = edx << 0xb;
                    if ((0x80000000 & ecx) == 0x0) {
                            do {
                                    ecx = *eax;
                                    edx = eax[0x1];
                                    edi = edi + 0xffff;
                                    eax[0x1] = edx + edx | ecx >> 0x1f;
                                    *eax = ecx + ecx;
                            } while ((0x80000000 & (edx + edx | ecx >> 0x1f)) == 0x0);
                    }
                    ecx = arg_4 | edi;
                    eax[0x4] = ecx;
            }
    }
    return;
}
