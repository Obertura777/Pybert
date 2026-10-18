// sub_4867db @ 0x4867db
// hopper name: sub_4867db
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4867db() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    eax = esi[0x3];
    if ((eax & 0x83) != 0x0 && (eax & 0x8) != 0x0) {
            sub_47c8f9();
            esi[0x3] = esi[0x3] & 0xfffffbf7;
            eax = 0x0;
            esp = (esp - 0x4) + 0x4;
            *esi = 0x0;
            esi[0x2] = 0x0;
            esi[0x1] = 0x0;
    }
    return eax;
}
