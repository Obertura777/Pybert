// sub_47a6e4 @ 0x47a6e4
// hopper name: sub_47a6e4
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a6e4() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    esi = ecx;
    *esi = 0x4b3940;
    eax = ebx[0x2];
    esi[0x2] = eax;
    bool_0 = eax == 0x0;
    eax = ebx[0x1];
    esp = esp - 0xc;
    if (!bool_0) {
            if (eax != 0x0) {
                    edi = sub_47d630(eax) + 0x1;
                    eax = sub_47c836();
                    esp = (esp - 0x8) + 0x8;
                    esi[0x1] = eax;
                    if (eax != 0x0) {
                            sub_47db5e(eax, edi, ebx[0x1]);
                            esp = (esp - 0xc) + 0xc;
                    }
            }
            else {
                    esi[0x1] = esi[0x1] & 0x0;
            }
    }
    else {
            esi[0x1] = eax;
    }
    eax = esi;
    return eax;
}
