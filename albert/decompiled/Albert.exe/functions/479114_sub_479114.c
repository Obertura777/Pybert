// sub_479114 @ 0x479114
// hopper name: sub_479114
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479114() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    esi = ecx;
    if (edi == 0x0) {
            edi = 0x11;
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi[0x1];
    if (eax != 0x0) {
            eax = sub_47c8f9();
            esi[0x1] = esi[0x1] & 0x0;
            esp = (esp - 0x4) + 0x4;
    }
    if (arg_4 != 0x0) {
            eax = sub_46dbce(-(OVERFLOW(edi * 0x4) ? 0x1 : 0x0) | edi * 0x4);
            esi[0x1] = eax;
            eax = sub_47ba40(eax, 0x0, edi << 0x2);
            esp = ((esp - 0x4) + 0x4 - 0x10) + 0x10;
    }
    esi[0x2] = edi;
    return eax;
}
