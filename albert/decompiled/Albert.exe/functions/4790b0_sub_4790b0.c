// sub_4790b0 @ 0x4790b0
// hopper name: sub_4790b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4790b0() {
    var_4 = esi;
    esi = arg_0;
    esp = (esp - 0x8) + 0x4;
    if (sub_478cea(esi) != 0x0) {
            eax = sub_478d15(esi);
            *(int16_t *)arg_8 = *(int16_t *)eax;
            bool_1 = esi[0x1] == 0xffff;
            WideCharToMultiByte(0x0, 0x0, eax + ((bool_1 ? 0x1 : 0x0) + (bool_1 ? 0x1 : 0x0) + 0x1) * 0x2, 0xffffffff, sub_4701ea(0x20), decomp_var_10, decomp_var_c, decomp_var_8);
            sub_45ba50();
    }
    return;
}
