// sub_46e83b @ 0x46e83b
// hopper name: sub_46e83b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e83b() {
    ebp = &var_11C;
    arg_22c = *dword_4c8db8 ^ ebp;
    sub_47d6bb(0x58);
    arg_d4 = arg_238;
    arg_104 = 0x0;
    eax = GetModuleHandleA("kernel32.dll");
    esp = esp - 0x128;
    arg_fc = eax;
    eax = GetProcAddress(eax, "GetUserDefaultUILanguage");
    if (eax != 0x0) {
            eax = (eax)();
            arg_f8 = eax & 0xffff & 0xffff & 0x3ff & 0xffff;
            ConvertDefaultLocale((eax & 0xffff & 0xffff) >> 0xa << 0xa & 0xffff | eax & 0xffff & 0xffff & 0x3ff & 0xffff);
            esp = esp - 0x10;
            ConvertDefaultLocale(arg_f8);
            arg_104 = 0x2;
            eax = GetProcAddress(arg_fc, "GetSystemDefaultUILanguage");
            if (eax != 0x0) {
                    eax = (eax)();
                    edi = eax & 0xffff & 0xffff & 0x3ff & 0xffff;
                    esp = esp - 0x8;
                    ConvertDefaultLocale((eax & 0xffff & 0xffff) >> 0xa << 0xa & 0xffff | edi);
                    ConvertDefaultLocale(edi);
                    arg_104 = 0x4;
            }
    }
    else {
            if (GetVersion() < 0x0) {
                    esp = esp - 0x14;
                    arg_fc = 0x0;
                    eax = RegOpenKeyExA(0x80000001, "Control Panel\Desktop\ResourceLocale", 0x0, 0x20019, &arg_fc);
                    if (eax == 0x0) {
                            esp = esp - 0x18;
                            arg_d0 = 0x10;
                            eax = RegQueryValueExA(arg_fc, 0x0, 0x0, &arg_f4, &arg_21c, &arg_d0);
                            if (eax == 0x0 && arg_f4 == 0x1) {
                                    eax = sub_47dc2b(&arg_21c, 0x4b25d4, &arg_f8);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax == 0x1) {
                                            esp = esp - 0x8;
                                            ConvertDefaultLocale((arg_f8 & 0xffff) >> 0xa << 0xa & 0xffff | arg_f8 & 0xffff & 0x3ff & 0xffff);
                                            ConvertDefaultLocale(arg_f8 & 0xffff & 0x3ff & 0xffff);
                                            arg_104 = 0x2;
                                    }
                            }
                            esp = esp - 0x4;
                            RegCloseKey(arg_fc);
                    }
            }
            else {
                    esp = esp - 0x4;
                    eax = GetModuleHandleA("ntdll.dll");
                    if (eax != 0x0) {
                            esp = esp - 0x14;
                            arg_100 = 0x0;
                            eax = EnumResourceLanguagesA(eax, 0x10, 0x1, 0x46dfea, &arg_100);
                            if (arg_100 != 0x0) {
                                    esp = esp - 0x8;
                                    ConvertDefaultLocale((arg_100 & 0xffff) >> 0xa << 0xa & 0xffff | arg_100 & 0xffff & 0x3ff & 0xffff);
                                    ConvertDefaultLocale(arg_100 & 0xffff & 0x3ff & 0xffff);
                                    arg_104 = 0x2;
                            }
                    }
            }
    }
    eax = arg_104;
    arg_104 = arg_104 + 0x1;
    *(ebp + (eax * 0x4 - 0x34)) = 0x800;
    esp = esp - 0xc;
    if (GetModuleFileNameA(word_400000, ebp, 0x105) != 0x0) {
            sub_47ba40(&arg_b0, 0x0, 0x20);
            arg_b0 = 0x20;
            sub_46e000();
            esp = ((esp - 0x4) + 0x4 - 0xc) + 0xc - 0x8;
            arg_110 = 0x0;
            eax = sub_46e0b0(&arg_b0);
            if (eax != 0x0) {
                    sub_46e0e6();
            }
            edi = 0x0;
            esi = 0x0;
            if (arg_104 > 0x0) {
                    eax = sub_46e604(*(ebp + (esi * 0x4 - 0x34)));
                    esp = (esp - 0x4) + 0x4;
                    if (eax == edi) {
                            esi = esi + 0x1;
                            if (esi < arg_104) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            edi = eax;
                            break;
                    }
            }
            sub_46e6d1();
    }
    *0x0 = arg_108;
    eax = sub_47ad69();
    return eax;
}
