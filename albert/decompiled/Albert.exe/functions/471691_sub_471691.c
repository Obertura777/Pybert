// sub_471691 @ 0x471691
// hopper name: sub_471691
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471691() {
    esp = esp - 0x4;
    decomp_var_4 = ebx;
    if (*dword_bc5f3c != 0x0) {
            eax = *dword_bc5f30 != 0x0 ? 0x1 : 0x0;
    }
    else {
            decomp_var_8 = esi;
            decomp_var_c = edi;
            esp = esp - 0xc;
            *dword_bc5f40 = sub_471639();
            edi = GetModuleHandleA("USER32");
            if (edi != 0x0) {
                    ebx = 0x0;
                    esp = esp - 0x8;
                    eax = GetProcAddress(edi, "GetSystemMetrics");
                    *dword_bc5f20 = eax;
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            eax = GetProcAddress(edi, "MonitorFromWindow");
                            *dword_bc5f24 = eax;
                            if (eax != ebx) {
                                    esp = esp - 0x8;
                                    eax = GetProcAddress(edi, "MonitorFromRect");
                                    *dword_bc5f28 = eax;
                                    if (eax != ebx) {
                                            esp = esp - 0x8;
                                            eax = GetProcAddress(edi, "MonitorFromPoint");
                                            *dword_bc5f2c = eax;
                                            if (eax != ebx) {
                                                    esp = esp - 0x8;
                                                    eax = GetProcAddress(edi, "EnumDisplayMonitors");
                                                    *dword_bc5f34 = eax;
                                                    if (eax != ebx) {
                                                            esi = GetProcAddress;
                                                            esp = esp - 0x8;
                                                            eax = GetProcAddress(edi, "GetMonitorInfoA");
                                                            *dword_bc5f30 = eax;
                                                            if (eax != ebx) {
                                                                    esp = esp - 0x8;
                                                                    eax = (esi)(edi, "EnumDisplayDevicesA");
                                                                    *dword_bc5f38 = eax;
                                                                    if (eax != ebx) {
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            *dword_bc5f20 = ebx;
                                                                            *dword_bc5f24 = ebx;
                                                                            *dword_bc5f28 = ebx;
                                                                            *dword_bc5f2c = ebx;
                                                                            *dword_bc5f30 = ebx;
                                                                            *dword_bc5f34 = ebx;
                                                                            *dword_bc5f38 = ebx;
                                                                            eax = 0x0;
                                                                    }
                                                                    *dword_bc5f3c = 0x1;
                                                            }
                                                            else {
                                                                    *dword_bc5f20 = ebx;
                                                                    *dword_bc5f24 = ebx;
                                                                    *dword_bc5f28 = ebx;
                                                                    *dword_bc5f2c = ebx;
                                                                    *dword_bc5f30 = ebx;
                                                                    *dword_bc5f34 = ebx;
                                                                    *dword_bc5f38 = ebx;
                                                                    eax = 0x0;
                                                                    *dword_bc5f3c = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc5f20 = ebx;
                                                            *dword_bc5f24 = ebx;
                                                            *dword_bc5f28 = ebx;
                                                            *dword_bc5f2c = ebx;
                                                            *dword_bc5f30 = ebx;
                                                            *dword_bc5f34 = ebx;
                                                            *dword_bc5f38 = ebx;
                                                            eax = 0x0;
                                                            *dword_bc5f3c = 0x1;
                                                    }
                                            }
                                            else {
                                                    *dword_bc5f20 = ebx;
                                                    *dword_bc5f24 = ebx;
                                                    *dword_bc5f28 = ebx;
                                                    *dword_bc5f2c = ebx;
                                                    *dword_bc5f30 = ebx;
                                                    *dword_bc5f34 = ebx;
                                                    *dword_bc5f38 = ebx;
                                                    eax = 0x0;
                                                    *dword_bc5f3c = 0x1;
                                            }
                                    }
                                    else {
                                            *dword_bc5f20 = ebx;
                                            *dword_bc5f24 = ebx;
                                            *dword_bc5f28 = ebx;
                                            *dword_bc5f2c = ebx;
                                            *dword_bc5f30 = ebx;
                                            *dword_bc5f34 = ebx;
                                            *dword_bc5f38 = ebx;
                                            eax = 0x0;
                                            *dword_bc5f3c = 0x1;
                                    }
                            }
                            else {
                                    *dword_bc5f20 = ebx;
                                    *dword_bc5f24 = ebx;
                                    *dword_bc5f28 = ebx;
                                    *dword_bc5f2c = ebx;
                                    *dword_bc5f30 = ebx;
                                    *dword_bc5f34 = ebx;
                                    *dword_bc5f38 = ebx;
                                    eax = 0x0;
                                    *dword_bc5f3c = 0x1;
                            }
                    }
                    else {
                            *dword_bc5f20 = 0x0;
                            *dword_bc5f24 = 0x0;
                            *dword_bc5f28 = 0x0;
                            *dword_bc5f2c = 0x0;
                            *dword_bc5f30 = 0x0;
                            *dword_bc5f34 = 0x0;
                            *dword_bc5f38 = 0x0;
                            eax = 0x0;
                            *dword_bc5f3c = 0x1;
                    }
            }
            else {
                    *dword_bc5f20 = 0x0;
                    *dword_bc5f24 = 0x0;
                    *dword_bc5f28 = 0x0;
                    *dword_bc5f2c = 0x0;
                    *dword_bc5f30 = 0x0;
                    *dword_bc5f34 = 0x0;
                    *dword_bc5f38 = 0x0;
                    eax = 0x0;
                    *dword_bc5f3c = 0x1;
            }
    }
    return eax;
}
