// sub_470e1d @ 0x470e1d
// hopper name: sub_470e1d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470e1d() {
    ebp = &var_1B4;
    arg_1a8 = *dword_4c8db8 ^ ebp;
    esi = ecx;
    sub_470d40();
    edi = esi[0x2];
    arg_1a4 = arg_1a4 & 0x0;
    esp = esp - 0x244;
    eax = GetModuleFileNameW(edi, &decomp_var_60, 0x105);
    if (eax != 0x0) {
            if (arg_1a4 != 0x0) {
                    esp = esp - 0x4;
                    SetLastError(0x6f);
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_80 = 0x20;
                    eax = sub_470dae();
                    esi[0x20] = eax;
                    if (eax == 0xffffffff) {
                            esp = esp - 0x4;
                            esi[0x20] = sub_470dae();
                    }
                    if (esi[0x20] == 0xffffffff) {
                            esp = esp - 0x4;
                            eax = sub_470dae();
                            esi[0x20] = eax;
                            if (eax == 0xffffffff) {
                                    esi[0x20] = esi[0x20] & 0x0;
                            }
                    }
            }
    }
    eax = sub_47ad69();
    return eax;
}
