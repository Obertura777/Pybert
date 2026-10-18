// sub_472073 @ 0x472073
// hopper name: sub_472073
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_472073() {
    var_4 = var_4 & 0x0;
    decomp_var_8 = esi;
    esi = ecx;
    eax = *esi;
    esp = esp - 0x14;
    decomp_var_18 = arg_0;
    eax = (eax[0x43])(decomp_var_18, arg_4, arg_8, &var_4, decomp_var_8, var_4);
    if (eax == 0x0) {
            esp = esp - 0xc;
            var_4 = (*(*esi + 0x110))(arg_0, arg_4, arg_8);
    }
    eax = var_4;
    return eax;
}
