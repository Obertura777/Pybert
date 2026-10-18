// sub_41a180 @ 0x41a180
// hopper name: sub_41a180
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41a180() {
    eax = ecx[0x1];
    edx = eax[0x1];
    decomp_var_c = ebx;
    esp = esp - 0x14;
    edi = arg_4;
    esi = eax;
    var_8 = 0x1;
    if (edx[0x15] == 0x0) {
            do {
                    asm { fld        dword [edi] };
                    esi = edx;
                    asm { fld        dword [edx+0xc] };
                    asm { fcompp };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            edx = *edx;
                            var_8 = 0x1;
                    }
                    else {
                            edx = edx[0x2];
                            var_8 = 0x0;
                    }
            } while (edx[0x15] == 0x0);
    }
    eax = sub_415bb0(&saved_fp, saved_fp, esi, edi, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0);
    ecx = eax;
    eax = arg_8;
    edx = *ecx;
    ecx = ecx[0x1];
    eax[0x8] = 0x1;
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
