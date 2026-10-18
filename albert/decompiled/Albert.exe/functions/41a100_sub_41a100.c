// sub_41a100 @ 0x41a100
// hopper name: sub_41a100
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41a100() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    ebp = arg_4;
    ebx = ecx;
    eax = ebx[0x1];
    esi = eax[0x1];
    esp = esp - 0x18;
    edi = eax;
    var_8 = 0x1;
    if (esi[0x21] == 0x0) {
            do {
                    esp = esp - 0x4;
                    edi = esi;
                    eax = sub_465cf0(esi + 0xc);
                    var_8 = eax;
                    if (eax != 0x0) {
                            esi = *esi;
                    }
                    else {
                            esi = esi[0x2];
                    }
            } while (esi[0x21] == 0x0);
    }
    eax = sub_4155b0(&saved_fp, saved_fp, edi, ebp, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
    ecx = eax;
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    eax[0x8] = 0x1;
    return eax;
}
