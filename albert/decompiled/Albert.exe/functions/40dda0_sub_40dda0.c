// sub_40dda0 @ 0x40dda0
// hopper name: sub_40dda0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40dda0() {
    decomp_var_4 = ecx;
    eax = ecx[0x2];
    decomp_var_8 = ebx;
    ebx = eax[0x900];
    esp = esp - 0xc;
    decomp_var_c = esi;
    esi = 0x0;
    var_1 = 0x0;
    if (ebx <= 0x0) goto loc_40de1c;
    goto loc_40ddb8;

loc_40de1c:
    eax = 0x0;
    return eax;

loc_40ddb8:
    decomp_var_10 = ebp;
    esp = esp - 0x8;
    decomp_var_14 = edi;
    ebp = eax + 0x20;
    goto loc_40ddc0;

loc_40ddc0:
    if (decomp_var_1d != 0x0) {
            eax = *(int16_t *)ebp;
            bool_7 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_7) {
                    eax = 0x14;
            }
            edx = arg_0;
            if (edx == eax) {
                    ecx = *(esi * 0x8 + 0x4d2e10);
                    edi = *(esi * 0x8 + 0x4d2e14);
                    if ((ecx & edi) != 0xffffffff) {
                            eax = edx;
                            edx = eax & 0x80000000 ? 0xffffffff : 0x0;
                            if (ecx == eax && edi == edx) {
                                    var_1 = 0x1;
                            }
                    }
                    else {
                            var_1 = 0x1;
                    }
            }
    }
    esi = esi + 0x1;
    ebp = &arg_20;
    if (esi < ebx) {
            continue;
    }
    break;
    eax = var_1;
    return eax;
}
