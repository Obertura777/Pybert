// sub_46fee4 @ 0x46fee4
// hopper name: sub_46fee4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46fee4() {
    ebp = arg_0;
    esp = esp - 0x10;
    esi = ebp;
    if (ebp == 0x0) {
            eax = sub_46fe0d();
            if (eax == 0x0) {
                    eax = sub_46e5d5();
                    if (eax == 0x0) {
                            esi = 0x0;
                    }
                    else {
                            esi = eax[0x8];
                            if (esi != 0x0) {
                                    while (true) {
                                            esp = esp - 0x8;
                                            if ((GetWindowLongA(esi, 0xfffffff0) & 0x40000000) == 0x0) {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            esp = esp - 0x4;
                                            esi = GetParent(esi);
                                            if (esi != 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                    }
            }
            else {
                    esi = eax[0x8];
                    if (esi != 0x0) {
                            while (true) {
                                    esp = esp - 0x8;
                                    if ((GetWindowLongA(esi, 0xfffffff0) & 0x40000000) == 0x0) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    esi = GetParent(esi);
                                    if (esi != 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
            }
    }
    else {
            while (true) {
                    esp = esp - 0x8;
                    if ((GetWindowLongA(esi, 0xfffffff0) & 0x40000000) == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esp = esp - 0x4;
                    esi = GetParent(esi);
                    if (esi != 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
    }
    edi = esi;
    eax = esi;
    if (esi != 0x0) {
            do {
                    esp = esp - 0x4;
                    edi = eax;
                    eax = GetParent(eax);
            } while (eax != 0x0);
    }
    if (ebp == 0x0 && esi != 0x0) {
            esp = esp - 0x4;
            esi = GetLastActivePopup(esi);
    }
    ebx = arg_c;
    if (ebx != 0x0) {
            if (edi != 0x0) {
                    esp = esp - 0x4;
                    if (IsWindowEnabled(edi) != 0x0) {
                            if (edi != esi) {
                                    esp = esp - 0x8;
                                    *ebx = edi;
                                    EnableWindow(edi, 0x0);
                            }
                            else {
                                    *ebx = *ebx & 0x0;
                            }
                    }
                    else {
                            *ebx = *ebx & 0x0;
                    }
            }
            else {
                    *ebx = *ebx & 0x0;
            }
    }
    eax = esi;
    return eax;
}
