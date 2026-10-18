// sub_474239 @ 0x474239
// hopper name: sub_474239
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474239() {
    esp = esp - 0x4;
    sub_47d6bb(0x4);
    esi = ecx;
    *esi = 0x4b2ebc;
    decomp_var_4 = 0x4 & 0x0;
    if (esi[0x8] != 0x0 && esi != dword_bc5f50 && esi != dword_bc5fa8) {
            if (esi != dword_bc6000) {
                    if (esi != dword_bc6058) {
                            sub_473d2d();
                    }
            }
    }
    ecx = esi[0x13];
    if (ecx != 0x0) {
            (*(*ecx + 0x4))(0x1);
    }
    eax = esi[0x14];
    if (eax != 0x0 && eax[0xa] == esi) {
            eax[0xa] = eax[0xa] & 0x0;
    }
    sub_46f008();
    eax = sub_47d75a();
    return eax;
}
