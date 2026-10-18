// sub_4762f5 @ 0x4762f5
// hopper name: sub_4762f5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4762f5() {
    decomp_var_4 = esi;
    esi = arg_0;
    decomp_var_8 = edi;
    esi[0x9] = arg_4;
    eax = sub_4715ba(decomp_var_8, decomp_var_4);
    eax = eax[0x3];
    esp = esp - 0x10;
    eax = LoadIconA(eax, arg_8 & 0xffff);
    esi[0x5] = eax;
    if (eax == 0x0) {
            esp = esp - 0x8;
            esi[0x5] = LoadIconA(eax, 0x7f00, decomp_var_8, decomp_var_4);
    }
    eax = sub_476152();
    return eax;
}
