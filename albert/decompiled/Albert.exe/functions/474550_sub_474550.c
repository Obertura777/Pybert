// sub_474550 @ 0x474550
// hopper name: sub_474550
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474550() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    esi = ecx;
    if (sub_473b2f(arg_0) != 0x0) {
            (*(*esi + 0x50))();
            esp = esp - 0xc;
            esi = (*(*esi + 0xf0))();
            eax = SetWindowLongA(arg_0, 0xfffffffc, sub_4741ee);
            if (*esi == 0x0) {
                    *esi = eax;
            }
    }
    return;
}
