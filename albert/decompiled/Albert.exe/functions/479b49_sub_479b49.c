// sub_479b49 @ 0x479b49
// hopper name: sub_479b49
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479b49() {
    esp = esp - 0x4;
    esi = ecx;
    if (esi[0x3] == 0x0) {
            esp = esp - 0xc;
            decomp_var_10 = esi + 0x8;
            eax = sub_479d75();
            ecx = esi[0x1];
            ecx = ecx - 0x1;
            eax = eax + 0x4 + *esi * ecx;
            while (ecx >= 0x0) {
                    *eax = esi[0x3];
                    esi[0x3] = eax;
                    ecx = ecx - 0x1;
                    eax = eax - *esi;
            }
    }
    eax = esi[0x3];
    esi[0x3] = *eax;
    return eax;
}
