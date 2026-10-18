// sub_488b20 @ 0x488b20
// hopper name: sub_488b20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488b20() {
    ecx = arg_0[0xf];
    eax = *(int16_t *)(ecx + arg_0 + 0x14) & 0xffff;
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = *(int16_t *)(ecx + arg_0 + 0x6) & 0xffff;
    edx = 0x0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    eax = eax + ecx + arg_0 + 0x18;
    if (esi > 0x0) {
            edi = arg_4;
            while (true) {
                    ecx = eax[0x3];
                    if (edi < ecx) {
                            edx = edx + 0x1;
                            eax = eax + 0x28;
                            if (edx < esi) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (edi < eax[0x2] + ecx) {
                            temp_0 = 0x1;
                            break;
                    }
                    edx = edx + 0x1;
                    eax = eax + 0x28;
                    if (edx < esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 == 0x0) {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
