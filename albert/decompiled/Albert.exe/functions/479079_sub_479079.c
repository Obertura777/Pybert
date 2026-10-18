// sub_479079 @ 0x479079
// hopper name: sub_479079
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479079() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    esi = ecx;
    if (edi == 0x0) {
            *esi = 0x0;
            esi[0x1] = 0x0;
            esi[0x2] = 0x0;
            eax = esi;
    }
    else {
            eax = sub_478d60(edi);
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_478e2a(edi, eax);
            if (eax == 0x0) {
                    sub_46dea8();
            }
            eax = esi;
    }
    return eax;
}
