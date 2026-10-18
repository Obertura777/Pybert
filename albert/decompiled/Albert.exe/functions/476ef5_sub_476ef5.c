// sub_476ef5 @ 0x476ef5
// hopper name: sub_476ef5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476ef5() {
    decomp_var_4 = esi;
    esi = ecx;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = esi[0x1];
    if (edi != 0x0) {
            esp = esp - 0x4;
            eax = sub_476e40();
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    sub_479251(esi[0x1]);
            }
    }
    (*(*esi + 0x14))();
    esi[0x1] = esi[0x1] & 0x0;
    eax = edi;
    return eax;
}
