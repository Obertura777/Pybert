// sub_4880b8 @ 0x4880b8
// hopper name: sub_4880b8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4880b8() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (*dword_bc7210 == *dword_bc7220) {
            eax = *dword_bc7220;
            esp = esp - 0x10;
            eax = HeapReAlloc(*dword_bc69f4, 0x0, *dword_bc7214, (eax + 0x10) * 0x14);
            if (eax == 0x0) {
                    eax = 0x0;
            }
            else {
                    *dword_bc7220 = *dword_bc7220 + 0x10;
                    *dword_bc7214 = eax;
                    edi = 0x0;
                    esi = *dword_bc7210;
                    esi = esi * 0x14 + *dword_bc7214;
                    esp = esp - 0xc;
                    eax = HeapAlloc(*dword_bc69f4, 0x8, 0x41c4);
                    esi[0x4] = eax;
                    if (eax != 0x0) {
                            esp = esp - 0x10;
                            eax = VirtualAlloc(edi, 0x100000, 0x2000, 0x4);
                            esi[0x3] = eax;
                            if (eax == edi) {
                                    esp = esp - 0xc;
                                    HeapFree(*dword_bc69f4, edi, esi[0x4]);
                                    eax = 0x0;
                            }
                            else {
                                    esi[0x2] = esi[0x2] | 0xffffffff;
                                    *esi = edi;
                                    esi[0x1] = edi;
                                    *dword_bc7210 = *dword_bc7210 + 0x1;
                                    eax = esi[0x4];
                                    *eax = *eax | 0xffffffff;
                                    eax = esi;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    else {
            esi = *dword_bc7210;
            esi = esi * 0x14 + *dword_bc7214;
            esp = esp - 0xc;
            eax = HeapAlloc(*dword_bc69f4, 0x8, 0x41c4);
            esi[0x4] = eax;
            if (eax != 0x0) {
                    esp = esp - 0x10;
                    eax = VirtualAlloc(0x0, 0x100000, 0x2000, 0x4);
                    esi[0x3] = eax;
                    if (eax == 0x0) {
                            esp = esp - 0xc;
                            HeapFree(*dword_bc69f4, 0x0, esi[0x4]);
                            eax = 0x0;
                    }
                    else {
                            esi[0x2] = esi[0x2] | 0xffffffff;
                            *esi = 0x0;
                            esi[0x1] = 0x0;
                            *dword_bc7210 = *dword_bc7210 + 0x1;
                            eax = esi[0x4];
                            *eax = *eax | 0xffffffff;
                            eax = esi;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
