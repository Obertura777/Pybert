// sub_47391c @ 0x47391c
// hopper name: sub_47391c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47391c() {
    esp = esp - 0x4;
    esi = ecx;
    if (esi[0x5] == 0x0) {
            decomp_var_8 = "InitCommonControlsEx";
            esp = esp - 0x8;
            esi[0x5] = GetProcAddress(sub_47384c(), "InitCommonControlsEx");
    }
    eax = saved_fp;
    *eax = esi[0x5];
    return eax;
}
