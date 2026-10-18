// sub_419fa0 @ 0x419fa0
// hopper name: sub_419fa0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_419fa0() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_c = ebp;
    ebp = arg_4;
    esp = esp - 0x10;
    esi = edx;
    var_8 = 0x1;
    if (eax[0x19] == 0x0) {
            esp = esp - 0x4;
            edi = *ebp;
            do {
                    esi = eax;
                    var_8 = edi > eax[0x3] ? 0x1 : 0x0;
                    if (edi != eax[0x3]) {
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x19] == 0x0);
            esp = esp + 0x4;
    }
    eax = sub_414ee0(&saved_fp, saved_fp, esi, ebp, var_8, decomp_var_4, saved_fp, arg_0, arg_4);
    ecx = eax;
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    eax[0x8] = 0x1;
    return eax;
}
