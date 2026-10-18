// sub_46e0b0 @ 0x46e0b0
// hopper name: sub_46e0b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e0b0() {
    esp = esp - 0x4;
    esi = ecx;
    if (*dword_bc46d0 == 0x0) {
            eax = 0x1;
    }
    else {
            if (arg_0 == 0x0) {
                    eax = 0x0;
            }
            else {
                    if (*esi == 0xffffffff) {
                            esp = esp - 0x4;
                            eax = dword_bc46d0(arg_0);
                            *esi = eax;
                            eax = eax != 0xffffffff ? 0x1 : 0x0;
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
