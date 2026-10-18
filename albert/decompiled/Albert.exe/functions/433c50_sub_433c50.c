// sub_433c50 @ 0x433c50
// hopper name: sub_433c50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_433c50() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = sub_410050();
    ecx[0x1] = eax;
    eax[0x31] = 0x1;
    eax = ecx[0x1];
    eax[0x1] = eax;
    eax = ecx[0x1];
    *eax = eax;
    eax = ecx[0x1];
    eax[0x2] = eax;
    ecx[0x2] = 0x0;
    sub_430d90(arg_0);
    eax = ecx;
    *0x0 = var_C;
    &var_14 = ebp;
    return eax;
}
