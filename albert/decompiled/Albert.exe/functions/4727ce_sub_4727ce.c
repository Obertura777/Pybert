// sub_4727ce @ 0x4727ce
// hopper name: sub_4727ce
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4727ce() {
    esp = esp - 0x4;
    esi = ecx;
    eax = *esi;
    if (eax != 0x7fffffff) {
            esp = esp - 0x4;
            decomp_var_8 = eax;
            eax = sub_478171();
            *esi = 0x7fffffff;
    }
    return eax;
}
