// sub_4801bf @ 0x4801bf
// hopper name: sub_4801bf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4801bf() {
    decomp_var_4 = edi;
    esp = esp - 0x8;
    edi = GetModuleHandleA("KERNEL32.DLL");
    if (edi == 0x0) {
            sub_47ff12();
            eax = 0x0;
    }
    else {
            *dword_bc6508 = GetProcAddress(edi, "FlsAlloc");
            *dword_bc650c = GetProcAddress(edi, "FlsGetValue");
            esp = esp - 0x24;
            *dword_bc6510 = GetProcAddress(edi, "FlsSetValue");
            eax = GetProcAddress(edi, "FlsFree");
            bool_1 = *dword_bc6508 == 0x0;
            *dword_bc6514 = eax;
            if (!bool_1) {
                    if (*dword_bc650c != 0x0) {
                            if (*dword_bc6510 != 0x0) {
                                    if (eax == 0x0) {
                                            *dword_bc650c = TlsGetValue;
                                            *dword_bc6508 = 0x47fedf;
                                            *dword_bc6510 = TlsSetValue;
                                            *dword_bc6514 = TlsFree;
                                    }
                            }
                            else {
                                    *dword_bc650c = TlsGetValue;
                                    *dword_bc6508 = 0x47fedf;
                                    *dword_bc6510 = TlsSetValue;
                                    *dword_bc6514 = TlsFree;
                            }
                    }
                    else {
                            *dword_bc650c = TlsGetValue;
                            *dword_bc6508 = 0x47fedf;
                            *dword_bc6510 = TlsSetValue;
                            *dword_bc6514 = TlsFree;
                    }
            }
            else {
                    *dword_bc650c = TlsGetValue;
                    *dword_bc6508 = 0x47fedf;
                    *dword_bc6510 = TlsSetValue;
                    *dword_bc6514 = TlsFree;
            }
            eax = TlsAlloc();
            *dword_4c8fc4 = eax;
            if (eax != 0xffffffff) {
                    esp = esp - 0x8;
                    if (TlsSetValue(eax, *dword_bc650c) != 0x0) {
                            sub_47db12();
                            eax = sub_47fe10(*dword_bc6508);
                            decomp_var_c = *dword_bc650c;
                            *dword_bc6508 = eax;
                            eax = sub_47fe10(decomp_var_c);
                            decomp_var_10 = *dword_bc6510;
                            *dword_bc650c = eax;
                            eax = sub_47fe10(decomp_var_10);
                            decomp_var_14 = *dword_bc6514;
                            *dword_bc6510 = eax;
                            esp = (esp - 0x10) + 0x10;
                            *dword_bc6514 = sub_47fe10(decomp_var_14);
                            if (sub_487a90() != 0x0) {
                                    eax = sub_47fe7c(*dword_bc6508);
                                    esp = (esp - 0x8) + 0x4;
                                    eax = (eax)();
                                    *dword_4c8fc0 = eax;
                                    if (eax != 0xffffffff) {
                                            esi = sub_4812c0(0x1, 0x214);
                                            esp = (esp - 0x8) + 0x8;
                                            if (esi != 0x0) {
                                                    esp = (esp - 0xc) + 0x4;
                                                    if ((sub_47fe7c(*dword_bc6510))() != 0x0) {
                                                            decomp_var_1c = 0x0;
                                                            decomp_var_20 = esi;
                                                            sub_47ff4f();
                                                            esp = (esp - 0x8) + 0x8;
                                                            eax = GetCurrentThreadId();
                                                            esi[0x1] = esi[0x1] | 0xffffffff;
                                                            *esi = eax;
                                                            eax = 0x1;
                                                    }
                                                    else {
                                                            sub_47ff12();
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    sub_47ff12();
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            sub_47ff12();
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    sub_47ff12();
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
