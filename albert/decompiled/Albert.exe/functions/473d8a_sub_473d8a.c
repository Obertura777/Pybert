// sub_473d8a @ 0x473d8a
// hopper name: sub_473d8a
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473d8a() {
    esi = ecx;
    esp = esp - 0x8;
    decomp_var_18 = 0x46def6;
    decomp_var_c = arg_8;
    eax = sub_477aab();
    if (eax == 0x0) {
            sub_46dedc();
    }
    eax = *esi;
    eax = (eax[0x42])(0x19, 0x0, &decomp_var_c);
    return eax;
}
