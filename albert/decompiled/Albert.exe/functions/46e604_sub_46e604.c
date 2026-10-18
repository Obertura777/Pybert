// sub_46e604 @ 0x46e604
// hopper name: sub_46e604
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e604() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x4;
    decomp_var_120 = esi;
    esi = ecx;
    eax = &var_11C;
    if (arg_0 == 0x800) {
            sub_47db5e(eax, 0x4, 0x4b25c4);
            sub_40bd00();
            esp = (esp - 0x10) + 0x10;
            decomp_var_124 = ebx;
            decomp_var_128 = edi;
            edi = *sub_47d812();
            eax = sub_47d812();
            *eax = *eax & 0x0;
            eax = sub_47d382(&var_118, 0x112, 0x111, esi, &var_11C);
            esp = (esp - 0x1c) + 0x14;
            ebx = eax;
            if (*sub_47d812() != 0x0) {
                    *sub_47d812();
                    sub_46dcfa();
                    esp = (esp - 0x4) + 0x4;
            }
            else {
                    *sub_47d812() = edi;
            }
            if (ebx != 0xffffffff && ebx < 0x112) {
                    esp = esp - 0x4;
                    LoadLibraryA(&var_118);
            }
            esp = esp + 0x8;
            eax = sub_47ad69();
    }
    else {
            esp = esp - 0x10;
            if (GetLocaleInfoA(arg_0, 0x3, eax, 0x4) == 0x0) {
                    eax = sub_47ad69();
            }
            else {
                    decomp_var_124 = ebx;
                    decomp_var_128 = edi;
                    edi = *sub_47d812();
                    eax = sub_47d812();
                    *eax = *eax & 0x0;
                    eax = sub_47d382(&var_118, 0x112, 0x111, esi, &var_11C);
                    esp = (esp - 0x1c) + 0x14;
                    ebx = eax;
                    if (*sub_47d812() != 0x0) {
                            *sub_47d812();
                            sub_46dcfa();
                            esp = (esp - 0x4) + 0x4;
                    }
                    else {
                            *sub_47d812() = edi;
                    }
                    if (ebx != 0xffffffff && ebx < 0x112) {
                            esp = esp - 0x4;
                            LoadLibraryA(&var_118);
                    }
                    esp = esp + 0x8;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
