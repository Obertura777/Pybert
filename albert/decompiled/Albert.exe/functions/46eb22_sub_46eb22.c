// sub_46eb22 @ 0x46eb22
// hopper name: sub_46eb22
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46eb22() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x10;
    eax = GetModuleFileNameA(ecx[0x11], &var_114, 0x104);
    if (eax != 0x0) {
            bool_5 = true;
            bool_4 = true;
            bool_3 = true;
            if (eax != 0x104) {
                    esp = esp - 0x8;
                    eax = PathFindExtensionA(&var_114, edi);
                    esi = "%s.dll";
                    edi = &var_C;
                    *edi = *esi;
                    asm { movsw      word [edi], word [esi] };
                    bool_2 = eax - &var_114 > 0xff;
                    asm { movsb      byte [edi], byte [esi] };
                    esp = esp + 0x4;
                    if (!bool_2) {
                            var_114 = &var_C;
                            sub_46e5ba(eax, &var_E - eax, var_114);
                            esp = (esp - 0xc) + 0xc - 0x4;
                            sub_46e83b(&var_114);
                    }
            }
    }
    eax = sub_47ad69();
    return eax;
}
