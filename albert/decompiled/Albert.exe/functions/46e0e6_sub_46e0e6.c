// sub_46e0e6 @ 0x46e0e6
// hopper name: sub_46e0e6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e0e6() {
    if (*dword_bc46d8 == 0x0) {
            eax = 0x1;
    }
    else {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            esi = *ecx;
            if (esi != 0xffffffff) {
                    eax = ecx + 0x4;
                    if (*eax != 0x0) {
                            eax = 0x0;
                    }
                    else {
                            eax = dword_bc46d8(esi, eax);
                            eax = (-(eax - 0x1) - -(eax - 0x1) + CARRY(EFLAGS(cf))) + 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
