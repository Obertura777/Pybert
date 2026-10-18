// sub_410980 @ 0x410980
// hopper name: sub_410980
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_410980() {
    decomp_var_14 = ebx;
    ebx = arg_4;
    esp = esp - 0x20;
    esi = ecx;
    edi = sub_40ee50(ebx);
    var_C = edi;
    if (esi == 0x0) {
            sub_47a948();
    }
    var_10 = esi;
    if (edi != esi[0x1]) {
            esp = esp - 0x4;
            if (sub_465cf0(edi + 0xc) == 0x0) {
                    ecx = &var_10;
            }
            else {
                    var_8 = esi;
                    ecx = &var_8;
            }
    }
    else {
            var_8 = esi;
            ecx = &var_8;
    }
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
