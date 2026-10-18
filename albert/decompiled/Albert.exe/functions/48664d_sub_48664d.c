// sub_48664d @ 0x48664d
// hopper name: sub_48664d
// contains unmarked entry 0x486670
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48664d() {
    esi = arg_0;
    decomp_var_8 = edi;
    decomp_var_c = esi;
    esp = (esp - 0xc) + 0x4;
    if (sub_48e43c(decomp_var_c) != 0xffffffff) {
            if (esi == 0x1) {
                    if ((*(int8_t *)(*dword_bc7240 + 0x54) & 0x1) == 0x0) {
                            if (esi == 0x2) {
                                    if ((*(int8_t *)(*dword_bc7240 + 0x2c) & 0x1) != 0x0) {
                                            decomp_var_c = 0x2;
                                            esp = (esp - 0x8) + 0x8;
                                            if (sub_48e43c(0x1) != sub_48e43c(0x2)) {
                                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                                    decomp_var_c = sub_48e43c(esi);
                                                    if (CloseHandle(decomp_var_c) == 0x0) {
                                                            edi = GetLastError();
                                                    }
                                                    else {
                                                            edi = 0x0;
                                                    }
                                            }
                                            else {
                                                    edi = 0x0;
                                            }
                                            sub_48e3bb(esi);
                                            esp = (esp - 0x4) + 0x4;
                                            *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                                            if (edi != 0x0) {
                                                    eax = sub_47d838(edi);
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = eax | 0xffffffff;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4 - 0x4;
                                            decomp_var_c = sub_48e43c(esi);
                                            if (CloseHandle(decomp_var_c) == 0x0) {
                                                    edi = GetLastError();
                                            }
                                            else {
                                                    edi = 0x0;
                                            }
                                            sub_48e3bb(esi);
                                            esp = (esp - 0x4) + 0x4;
                                            *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                                            if (edi != 0x0) {
                                                    eax = sub_47d838(edi);
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = eax | 0xffffffff;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                    decomp_var_c = sub_48e43c(esi);
                                    if (CloseHandle(decomp_var_c) == 0x0) {
                                            edi = GetLastError();
                                    }
                                    else {
                                            edi = 0x0;
                                    }
                                    sub_48e3bb(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                                    if (edi != 0x0) {
                                            eax = sub_47d838(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = eax | 0xffffffff;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            decomp_var_c = 0x2;
                            esp = (esp - 0x8) + 0x8;
                            if (sub_48e43c(0x1) != sub_48e43c(0x2)) {
                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                    decomp_var_c = sub_48e43c(esi);
                                    if (CloseHandle(decomp_var_c) == 0x0) {
                                            edi = GetLastError();
                                    }
                                    else {
                                            edi = 0x0;
                                    }
                            }
                            else {
                                    edi = 0x0;
                            }
                            sub_48e3bb(esi);
                            esp = (esp - 0x4) + 0x4;
                            *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                            if (edi != 0x0) {
                                    eax = sub_47d838(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    eax = eax | 0xffffffff;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    if (esi == 0x2) {
                            if ((*(int8_t *)(*dword_bc7240 + 0x2c) & 0x1) != 0x0) {
                                    decomp_var_c = 0x2;
                                    esp = (esp - 0x8) + 0x8;
                                    if (sub_48e43c(0x1) != sub_48e43c(0x2)) {
                                            esp = (esp - 0x4) + 0x4 - 0x4;
                                            decomp_var_c = sub_48e43c(esi);
                                            if (CloseHandle(decomp_var_c) == 0x0) {
                                                    edi = GetLastError();
                                            }
                                            else {
                                                    edi = 0x0;
                                            }
                                    }
                                    else {
                                            edi = 0x0;
                                    }
                                    sub_48e3bb(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                                    if (edi != 0x0) {
                                            eax = sub_47d838(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = eax | 0xffffffff;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                    decomp_var_c = sub_48e43c(esi);
                                    if (CloseHandle(decomp_var_c) == 0x0) {
                                            edi = GetLastError();
                                    }
                                    else {
                                            edi = 0x0;
                                    }
                                    sub_48e3bb(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                                    if (edi != 0x0) {
                                            eax = sub_47d838(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = eax | 0xffffffff;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = (esp - 0x4) + 0x4 - 0x4;
                            decomp_var_c = sub_48e43c(esi);
                            if (CloseHandle(decomp_var_c) == 0x0) {
                                    edi = GetLastError();
                            }
                            else {
                                    edi = 0x0;
                            }
                            sub_48e3bb(esi);
                            esp = (esp - 0x4) + 0x4;
                            *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
                            if (edi != 0x0) {
                                    eax = sub_47d838(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    eax = eax | 0xffffffff;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    else {
            sub_48e3bb(esi);
            esp = (esp - 0x4) + 0x4;
            *(int8_t *)(*((SAR(esi, 0x5)) * 0x4 + dword_bc7240) + (esi & 0x1f) * 0x28 + 0x4) = 0x0;
            if (0x0 != 0x0) {
                    eax = sub_47d838(0x0);
                    esp = (esp - 0x4) + 0x4;
                    eax = eax | 0xffffffff;
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
