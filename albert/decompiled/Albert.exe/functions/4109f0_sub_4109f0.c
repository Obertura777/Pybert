// sub_4109f0 @ 0x4109f0
// hopper name: sub_4109f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4109f0() {
    decomp_var_14 = ebx;
    ebx = arg_4;
    esp = esp - 0x24;
    esi = ecx;
    eax = sub_40fb30(&var_10, ebx, edi);
    eax = var_10;
    edi = esi[0x1];
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    eax = var_C;
    if (eax != edi && *ebx >= eax[0x4]) {
            ecx = &var_10;
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
