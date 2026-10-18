// sub_46e6d1 @ 0x46e6d1
// hopper name: sub_46e6d1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e6d1() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (*dword_bc46d4 != 0x0 && *esi != 0xffffffff) {
            sub_46e113();
            esp = esp - 0x4;
            (*dword_bc46d4)(*esi);
    }
    return;
}
