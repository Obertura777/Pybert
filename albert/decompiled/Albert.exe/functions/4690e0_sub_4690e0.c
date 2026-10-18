// sub_4690e0 @ 0x4690e0
// hopper name: sub_4690e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4690e0() {
    var_C = *0x0;
    decomp_var_28 = ebx;
    decomp_var_2c = esi;
    decomp_var_30 = edi;
    decomp_var_34 = *dword_4c8db8 ^ &decomp_var_30;
    *0x0 = &var_C;
    esp = esp - 0x38;
    sub_4931ea(0x0);
    bool_0 = *dword_bc46a0 != 0x0;
    var_24 = *dword_bc4698;
    if (!bool_0) {
            esp = esp - 0x4;
            sub_4931ea(0x0);
            if (*dword_bc46a0 == 0x0) {
                    eax = *dword_bc6fe8;
                    *dword_bc6fe8 = eax + 0x1;
                    *dword_bc46a0 = eax + 0x1;
            }
            sub_49320b();
    }
    edi = *dword_bc46a0;
    eax = *arg_0;
    if (edi < eax[0x3]) {
            esi = *(eax[0x2] + *dword_bc46a0 * 0x4);
            if (esi == 0x0) {
                    if (eax[0x14] != 0x0) {
                            edi = *dword_bc46a0;
                            eax = sub_493278();
                            if (edi < eax[0x3]) {
                                    esi = *(eax[0x2] + *dword_bc46a0 * 0x4);
                                    if (esi == 0x0) {
                                            if (*dword_bc4698 != 0x0) {
                                                    esi = *dword_bc4698;
                                            }
                                            else {
                                                    eax = sub_468ec0(&var_24);
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax == 0xffffffff) {
                                                            sub_47a75f("bad cast");
                                                            esp = esp - 0xc;
                                                            sub_47a958(&var_18, 0x4c1628);
                                                    }
                                                    esi = var_24;
                                                    *dword_bc4698 = esi;
                                                    sub_465710();
                                                    sub_493346(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            sub_49320b();
                                            eax = esi;
                                            *0x0 = var_C;
                                    }
                                    else {
                                            sub_49320b();
                                            eax = esi;
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    if (*dword_bc4698 != 0x0) {
                                            esi = *dword_bc4698;
                                    }
                                    else {
                                            eax = sub_468ec0(&var_24);
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax == 0xffffffff) {
                                                    sub_47a75f("bad cast");
                                                    esp = esp - 0xc;
                                                    sub_47a958(&var_18, 0x4c1628);
                                            }
                                            esi = var_24;
                                            *dword_bc4698 = esi;
                                            sub_465710();
                                            sub_493346(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    sub_49320b();
                                    eax = esi;
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            if (esi == 0x0) {
                                    if (*dword_bc4698 != 0x0) {
                                            esi = *dword_bc4698;
                                    }
                                    else {
                                            eax = sub_468ec0(&var_24);
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax == 0xffffffff) {
                                                    sub_47a75f("bad cast");
                                                    esp = esp - 0xc;
                                                    sub_47a958(&var_18, 0x4c1628);
                                            }
                                            esi = var_24;
                                            *dword_bc4698 = esi;
                                            sub_465710();
                                            sub_493346(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    sub_49320b();
                                    eax = esi;
                                    *0x0 = var_C;
                            }
                            else {
                                    sub_49320b();
                                    eax = esi;
                                    *0x0 = var_C;
                            }
                    }
            }
            else {
                    sub_49320b();
                    eax = esi;
                    *0x0 = var_C;
            }
    }
    else {
            if (eax[0x14] != 0x0) {
                    edi = *dword_bc46a0;
                    eax = sub_493278();
                    if (edi < eax[0x3]) {
                            esi = *(eax[0x2] + *dword_bc46a0 * 0x4);
                            if (esi == 0x0) {
                                    if (*dword_bc4698 != 0x0) {
                                            esi = *dword_bc4698;
                                    }
                                    else {
                                            eax = sub_468ec0(&var_24);
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax == 0xffffffff) {
                                                    sub_47a75f("bad cast");
                                                    esp = esp - 0xc;
                                                    sub_47a958(&var_18, 0x4c1628);
                                            }
                                            esi = var_24;
                                            *dword_bc4698 = esi;
                                            sub_465710();
                                            sub_493346(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    sub_49320b();
                                    eax = esi;
                                    *0x0 = var_C;
                            }
                            else {
                                    sub_49320b();
                                    eax = esi;
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            if (*dword_bc4698 != 0x0) {
                                    esi = *dword_bc4698;
                            }
                            else {
                                    eax = sub_468ec0(&var_24);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax == 0xffffffff) {
                                            sub_47a75f("bad cast");
                                            esp = esp - 0xc;
                                            sub_47a958(&var_18, 0x4c1628);
                                    }
                                    esi = var_24;
                                    *dword_bc4698 = esi;
                                    sub_465710();
                                    sub_493346(esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            sub_49320b();
                            eax = esi;
                            *0x0 = var_C;
                    }
            }
            else {
                    if (0x0 == 0x0) {
                            if (*dword_bc4698 != 0x0) {
                                    esi = *dword_bc4698;
                            }
                            else {
                                    eax = sub_468ec0(&var_24);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax == 0xffffffff) {
                                            sub_47a75f("bad cast");
                                            esp = esp - 0xc;
                                            sub_47a958(&var_18, 0x4c1628);
                                    }
                                    esi = var_24;
                                    *dword_bc4698 = esi;
                                    sub_465710();
                                    sub_493346(esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            sub_49320b();
                            eax = esi;
                            *0x0 = var_C;
                    }
                    else {
                            sub_49320b();
                            eax = 0x0;
                            *0x0 = var_C;
                    }
            }
    }
    return eax;
}
