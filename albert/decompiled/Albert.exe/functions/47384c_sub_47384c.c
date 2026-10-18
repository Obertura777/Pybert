// sub_47384c @ 0x47384c
// hopper name: sub_47384c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47384c() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (esi[0x1] == 0x0) {
            esp = esp - 0x4;
            eax = GetModuleHandleA(esi[0x3]);
            esi[0x1] = eax;
            if (eax == 0x0) {
                    esp = esp - 0x4;
                    eax = LoadLibraryA(esi[0x3]);
                    esi[0x1] = eax;
                    esi[0x8] = eax != 0x0 ? 0x1 : 0x0;
            }
    }
    eax = esi[0x1];
    return eax;
}
