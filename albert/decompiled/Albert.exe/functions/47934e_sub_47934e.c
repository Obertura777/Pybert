// sub_47934e @ 0x47934e
// hopper name: sub_47934e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47934e() {
    esp = esp - 0x4;
    esi = ecx;
    if (esi[0x4] == 0x0) {
            esp = esp - 0xc;
            decomp_var_10 = esi + 0x14;
            eax = sub_479d75();
            ecx = esi[0x6];
            edx = ecx * 0xc;
            ecx = ecx - 0x1;
            eax = eax + 0x4 + (edx - 0xc);
            if (ecx >= 0x0) {
                    do {
                            *eax = esi[0x4];
                            esi[0x4] = eax;
                            ecx = ecx - 0x1;
                            eax = eax - 0xc;
                    } while (ecx >= 0x0);
            }
    }
    eax = esi[0x4];
    ecx = *eax;
    esi[0x3] = esi[0x3] + 0x1;
    esi[0x4] = ecx;
    eax[0x1] = eax[0x1] & 0x0;
    eax[0x2] = eax[0x2] & 0x0;
    return eax;
}
