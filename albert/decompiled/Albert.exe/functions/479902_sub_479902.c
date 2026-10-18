// sub_479902 @ 0x479902
// hopper name: sub_479902
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479902() {
    ebp = &decomp_var_294;
    arg_288 = *dword_4c8db8 ^ ebp;
    decomp_var_31c = esi;
    decomp_var_320 = edi;
    esi = ecx;
    edi = sub_4715ba(decomp_var_320, decomp_var_31c, ebx);
    edi[0x2] = esi[0x11];
    edi[0x3] = esi[0x11];
    decomp_var_324 = 0x104;
    decomp_var_328 = &arg_184;
    esp = esp - 0x328;
    eax = GetModuleFileNameA(esi[0x11], decomp_var_328, 0x104);
    if (eax == 0x0) {
            sub_476ac2();
    }
    if (eax == 0x104) {
            sub_476ac2();
    }
    esp = esp - 0x4;
    eax = PathFindExtensionA(&arg_184);
    decomp_var_80 = eax;
    if (eax == 0x0) {
            sub_476ac2();
    }
    ebx = 0x104;
    *(int8_t *)decomp_var_80 = 0x0;
    esp = esp - 0xc;
    if (sub_4798c4() != 0x0) {
            sub_476ac2();
    }
    if (esi[0x18] == 0x0) {
            decomp_var_320 = &arg_80;
            eax = sub_47dc4a(decomp_var_320);
            esp = (esp - 0x4) + 0x4;
            esi[0x18] = eax;
            if (eax == 0x0) {
                    sub_46dea8();
            }
            eax = esi[0x14];
            if (eax == 0x0) {
                    decomp_var_320 = 0x100;
                    decomp_var_324 = &decomp_var_7c;
                    esp = esp - 0xc;
                    decomp_var_328 = 0xe000;
                    if (sub_470188() != 0x0) {
                            esp = esp - 0x4;
                            decomp_var_32c = &decomp_var_7c;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_32c = esi[0x18];
                    }
                    eax = sub_47dc4a(decomp_var_32c);
                    esi[0x14] = eax;
                    esp = esp + 0x4;
                    if (eax == 0x0) {
                            sub_46dea8();
                    }
                    edi[0x4] = eax;
                    if (esi[0x19] == 0x0) {
                            eax = &arg_288 - decomp_var_80;
                            if (esi[0x1b] == 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b3874;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b386c;
                            }
                            sub_46e5ba(decomp_var_80, eax, decomp_var_32c);
                            eax = sub_47dc4a(&arg_184);
                            esp = ((esp - 0x8) + 0xc - 0x4) + 0x4;
                            esi[0x19] = eax;
                            if (eax == 0x0) {
                                    sub_46dea8();
                            }
                            *(int8_t *)decomp_var_80 = 0x0;
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
                    else {
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, 0x104, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
            }
            else {
                    edi[0x4] = eax;
                    if (esi[0x19] == 0x0) {
                            eax = &arg_288 - decomp_var_80;
                            if (esi[0x1b] == 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b3874;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b386c;
                            }
                            sub_46e5ba(decomp_var_80, eax, decomp_var_32c);
                            eax = sub_47dc4a(&arg_184);
                            esp = ((esp - 0x8) + 0xc - 0x4) + 0x4;
                            esi[0x19] = eax;
                            if (eax == 0x0) {
                                    sub_46dea8();
                            }
                            *(int8_t *)decomp_var_80 = 0x0;
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
                    else {
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, 0x104, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
            }
    }
    else {
            eax = esi[0x14];
            if (eax == 0x0) {
                    decomp_var_320 = 0x100;
                    decomp_var_324 = &decomp_var_7c;
                    esp = esp - 0xc;
                    decomp_var_328 = 0xe000;
                    if (sub_470188() != 0x0) {
                            esp = esp - 0x4;
                            decomp_var_32c = &decomp_var_7c;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_32c = esi[0x18];
                    }
                    eax = sub_47dc4a(decomp_var_32c);
                    esi[0x14] = eax;
                    esp = esp + 0x4;
                    if (eax == 0x0) {
                            sub_46dea8();
                    }
                    edi[0x4] = eax;
                    if (esi[0x19] == 0x0) {
                            eax = &arg_288 - decomp_var_80;
                            if (esi[0x1b] == 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b3874;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b386c;
                            }
                            sub_46e5ba(decomp_var_80, eax, decomp_var_32c);
                            eax = sub_47dc4a(&arg_184);
                            esp = ((esp - 0x8) + 0xc - 0x4) + 0x4;
                            esi[0x19] = eax;
                            if (eax == 0x0) {
                                    sub_46dea8();
                            }
                            *(int8_t *)decomp_var_80 = 0x0;
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
                    else {
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
            }
            else {
                    edi[0x4] = eax;
                    if (esi[0x19] == 0x0) {
                            eax = &arg_288 - decomp_var_80;
                            if (esi[0x1b] == 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b3874;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_32c = 0x4b386c;
                            }
                            sub_46e5ba(decomp_var_80, eax, decomp_var_32c);
                            eax = sub_47dc4a(&arg_184);
                            esp = ((esp - 0x8) + 0xc - 0x4) + 0x4;
                            esi[0x19] = eax;
                            if (eax == 0x0) {
                                    sub_46dea8();
                            }
                            *(int8_t *)decomp_var_80 = 0x0;
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
                    else {
                            if (esi[0x1a] == 0x0) {
                                    sub_47f557(&arg_80, ebx, 0x4b3864);
                                    sub_40bd00();
                                    eax = sub_47dc4a(&arg_80);
                                    esp = (esp - 0x14) + 0x14;
                                    esi[0x1a] = eax;
                                    if (eax == 0x0) {
                                            sub_46dea8();
                                    }
                                    sub_47ad69();
                            }
                            else {
                                    sub_47ad69();
                            }
                    }
            }
    }
    return;
}
