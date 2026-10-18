// sub_47aea2 @ 0x47aea2
// hopper name: sub_47aea2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47aea2() {
    eax = arg_0;
    esp = esp - 0x4;
    esi = ecx;
    esi[0xc] = 0x0;
    if (eax == 0x0) {
            eax = sub_480086();
            esi[0x2] = eax;
            *esi = eax[0x1b];
            esi[0x1] = eax[0x1a];
            ecx = *esi;
            bool_2 = ecx != *dword_4c95f8;
            if (ecx != *dword_4c95f8 && !bool_2) {
                    *esi = sub_481ce6();
            }
            eax = esi[0x1];
            bool_5 = eax == *dword_4c9418;
            bool_3 = eax != *dword_4c9418;
            if (!bool_5 && !bool_3) {
                    esi[0x1] = sub_4815b1();
            }
            eax = esi[0x2];
            if ((eax[0x70] & 0x2) == 0x0) {
                    eax[0x1c] = eax[0x1c] | 0x2;
                    esi[0xc] = 0x1;
            }
    }
    else {
            *esi = *eax;
            esi[0x1] = eax[0x1];
    }
    eax = esi;
    return eax;
}
