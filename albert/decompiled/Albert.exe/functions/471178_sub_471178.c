// sub_471178 @ 0x471178
// hopper name: sub_471178
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471178() {
    esp = esp - 0x4;
    esi = ecx;
    bool_0 = esi[0x8] == 0x0;
    *esi = 0x4b2ae8;
    if (!bool_0) {
            esp = esp - 0x4;
            FreeLibrary(saved_fp);
    }
    sub_40b670();
    return;
}
