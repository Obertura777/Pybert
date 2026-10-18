// sub_46f397 @ 0x46f397
// hopper name: sub_46f397
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f397() {
    esp = esp - 0x4;
    sub_47d6bb(0x4);
    esi = ecx;
    *esi = 0x4b2784;
    eax = esi[0xb];
    decomp_var_4 = 0x4 & 0x0;
    if (eax != 0x0) {
            CloseHandle(eax);
    }
    eax = sub_4715ed();
    if (eax[0x1] == esi) {
            eax[0x1] = eax[0x1] & 0x0;
    }
    sub_46f008();
    eax = sub_47d75a();
    return eax;
}
