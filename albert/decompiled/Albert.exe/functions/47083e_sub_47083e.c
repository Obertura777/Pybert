// sub_47083e @ 0x47083e
// hopper name: sub_47083e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47083e() {
    esp = esp - 0x4;
    sub_47d6ee(0x3c);
    ebx = ecx;
    if (arg_c == 0x0) {
            arg_c = *(sub_4715ba() + 0xc);
    }
    esi = *(sub_4715ba() + 0x3c);
    decomp_var_28 = esi;
    decomp_var_14 = 0x0;
    sub_476336(0x10);
    esp = esp - 0x8;
    sub_476336(0x7c000);
    if (esi != 0x0) {
            eax = *ebx;
            esp = esp - 0x4;
            eax = (eax[0x4b])(&decomp_var_48);
            if (eax == 0x0) {
                    eax = sub_47d75a();
            }
            else {
                    eax = *esi;
                    esp = esp - 0x8;
                    eax = (eax[0x5])(&decomp_var_48, arg_4);
                    esi = eax;
                    edi = 0x0;
                    if (esi != 0x0) {
                            sub_47020b();
                            sub_40b7d0();
                            decomp_var_18 = edi;
                            eax = sub_4790b0(esi, 0x1, &decomp_var_18);
                            esp = (esp - 0x10) + 0xc;
                            bool_28 = eax == edi;
                            eax = eax == edi ? 0x1 : 0x0;
                            if (!bool_28) {
                                    if (eax == edi) {
                                            esp = esp - 0x4;
                                            if (GetSystemMetrics(0x2a) != 0x0) {
                                                    esp = esp - 0x4;
                                                    eax = sub_470816();
                                                    bool_34 = eax == edi;
                                                    eax = eax == edi ? 0x1 : 0x0;
                                                    if (!bool_34) {
                                                            if (decomp_var_18 == 0x8) {
                                                                    decomp_var_18 = edi;
                                                            }
                                                            if (eax != edi) {
                                                                    sub_479079();
                                                                    esp = esp - 0x8;
                                                                    sub_478fd7(decomp_var_18);
                                                                    decomp_var_14 = sub_478d0f();
                                                                    sub_478d01();
                                                                    if (decomp_var_14 != edi) {
                                                                            esp = esp - 0x4;
                                                                            esi = GlobalLock(decomp_var_14);
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_479079();
                                            esp = esp - 0x8;
                                            sub_478fd7(decomp_var_18);
                                            decomp_var_14 = sub_478d0f();
                                            sub_478d01();
                                            if (decomp_var_14 != edi) {
                                                    esp = esp - 0x4;
                                                    esi = GlobalLock(decomp_var_14);
                                            }
                                    }
                            }
                            else {
                                    if (eax != edi) {
                                            sub_479079();
                                            esp = esp - 0x8;
                                            sub_478fd7(decomp_var_18);
                                            decomp_var_14 = sub_478d0f();
                                            sub_478d01();
                                            if (decomp_var_14 != edi) {
                                                    esp = esp - 0x4;
                                                    esi = GlobalLock(decomp_var_14);
                                            }
                                    }
                            }
                            ebx[0x11] = ebx[0x11] | 0xffffffff;
                            ebx[0xf] = ebx[0xf] | 0x10;
                            esp = esp - 0x4;
                            sub_47550c();
                            eax = arg_8;
                            if (eax == edi) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = eax[0x8];
                            }
                            esp = esp - 0x14;
                            esi = CreateDialogIndirectParamA(arg_c, esi, eax, 0x4702bc, edi);
                            sub_40b670();
                            ecx = decomp_var_28;
                            if (ecx != edi) {
                                    esp = esp - 0x4;
                                    (*(*ecx + 0x18))(&decomp_var_48);
                                    if (esi != edi) {
                                            esp = esp - 0x4;
                                            (*(*ebx + 0x12c))(edi);
                                    }
                            }
                            if (sub_473b96() == 0x0) {
                                    (*(*ebx + 0x114))();
                            }
                            if (esi != edi && (ebx[0x3c] & 0x10) == 0x0) {
                                    esp = esp - 0x4;
                                    DestroyWindow(esi);
                                    esi = 0x0;
                            }
                            if (decomp_var_14 != edi) {
                                    GlobalUnlock(decomp_var_14);
                                    GlobalFree(decomp_var_14);
                            }
                    }
                    eax = sub_47d75a();
            }
    }
    else {
            esi = arg_4;
            if (esi != 0x0) {
                    edi = 0x0;
                    sub_47020b();
                    sub_40b7d0();
                    decomp_var_18 = 0x0;
                    eax = sub_4790b0(esi, 0x1, &decomp_var_18);
                    esp = (esp - 0x10) + 0xc;
                    bool_2 = eax == 0x0;
                    eax = eax == 0x0 ? 0x1 : 0x0;
                    if (!bool_2) {
                            if (eax == edi) {
                                    esp = esp - 0x4;
                                    if (GetSystemMetrics(0x2a) != 0x0) {
                                            esp = esp - 0x4;
                                            eax = sub_470816();
                                            bool_6 = eax == edi;
                                            eax = eax == edi ? 0x1 : 0x0;
                                            if (!bool_6) {
                                                    if (decomp_var_18 == 0x8) {
                                                            decomp_var_18 = edi;
                                                    }
                                                    if (eax != edi) {
                                                            sub_479079();
                                                            esp = esp - 0x8;
                                                            sub_478fd7(decomp_var_18);
                                                            decomp_var_14 = sub_478d0f();
                                                            sub_478d01();
                                                            if (decomp_var_14 != edi) {
                                                                    esp = esp - 0x4;
                                                                    esi = GlobalLock(decomp_var_14);
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_479079();
                                    esp = esp - 0x8;
                                    sub_478fd7(decomp_var_18);
                                    decomp_var_14 = sub_478d0f();
                                    sub_478d01();
                                    if (decomp_var_14 != edi) {
                                            esp = esp - 0x4;
                                            esi = GlobalLock(decomp_var_14);
                                    }
                            }
                    }
                    else {
                            if (eax != edi) {
                                    sub_479079();
                                    esp = esp - 0x8;
                                    sub_478fd7(decomp_var_18);
                                    decomp_var_14 = sub_478d0f();
                                    sub_478d01();
                                    if (decomp_var_14 != edi) {
                                            esp = esp - 0x4;
                                            esi = GlobalLock(decomp_var_14);
                                    }
                            }
                    }
                    ebx[0x11] = ebx[0x11] | 0xffffffff;
                    ebx[0xf] = ebx[0xf] | 0x10;
                    esp = esp - 0x4;
                    sub_47550c();
                    eax = arg_8;
                    if (eax == edi) {
                            eax = 0x0;
                    }
                    else {
                            eax = eax[0x8];
                    }
                    esp = esp - 0x14;
                    esi = CreateDialogIndirectParamA(arg_c, esi, eax, 0x4702bc, edi);
                    sub_40b670();
                    ecx = decomp_var_28;
                    if (ecx != edi) {
                            esp = esp - 0x4;
                            (*(*ecx + 0x18))(&decomp_var_48);
                            if (esi != edi) {
                                    esp = esp - 0x4;
                                    (*(*ebx + 0x12c))(edi);
                            }
                    }
                    if (sub_473b96() == 0x0) {
                            (*(*ebx + 0x114))();
                    }
                    if (esi != edi && (ebx[0x3c] & 0x10) == 0x0) {
                            esp = esp - 0x4;
                            DestroyWindow(esi);
                            esi = 0x0;
                    }
                    if (decomp_var_14 != edi) {
                            GlobalUnlock(decomp_var_14);
                            GlobalFree(decomp_var_14);
                    }
            }
            eax = sub_47d75a();
    }
    return eax;
}
