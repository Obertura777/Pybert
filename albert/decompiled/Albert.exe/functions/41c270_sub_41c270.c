// sub_41c270 @ 0x41c270
// hopper name: sub_41c270
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c270() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_170 = ebx;
    decomp_var_174 = esi;
    esi = arg_0;
    decomp_var_178 = edi;
    edi = ecx;
    esp = esp - 0x17c;
    var_160 = edi;
    ebx = sub_40ece0(esi);
    if (edi == 0x0) {
            sub_47a948();
    }
    bool_1 = true;
    var_168 = edi;
    if (ebx != edi[0x1]) {
            eax = *esi;
            ecx = ebx[0x3];
            bool_17 = true;
            bool_16 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_16) {
                            eax = esi[0x2];
                            bool_6 = true;
                            if (eax < ebx[0x8]) {
                                    sub_47ba40(&var_A8, 0x0, 0xa8);
                                    var_158 = *esi;
                                    var_150 = var_A8;
                                    esp = (esp - 0xc) + 0xc - 0x10;
                                    eax = sub_419870(&var_160, var_168, ebx, &var_158);
                                    ecx = *eax;
                                    ebx = eax[0x1];
                                    edi = ecx;
                                    if (edi == 0x0) {
                                            sub_47a948();
                                    }
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = ebx + 0x14;
                                    &decomp_var_16c = ebp;
                            }
                            else {
                                    if (edi == 0x0) {
                                            sub_47a948();
                                    }
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = ebx + 0x14;
                                    &decomp_var_16c = ebp;
                            }
                    }
                    else {
                            if (edi == 0x0) {
                                    sub_47a948();
                            }
                            if (ebx == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = ebx + 0x14;
                            &decomp_var_16c = ebp;
                    }
            }
            else {
                    sub_47ba40(&var_A8, 0x0, 0xa8);
                    var_158 = *esi;
                    var_150 = var_A8;
                    esp = (esp - 0xc) + 0xc - 0x10;
                    eax = sub_419870(&var_160, var_168, ebx, &var_158);
                    ecx = *eax;
                    ebx = eax[0x1];
                    edi = ecx;
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx + 0x14;
                    &decomp_var_16c = ebp;
            }
    }
    else {
            sub_47ba40(&var_A8, 0x0, 0xa8);
            var_158 = *esi;
            var_150 = var_A8;
            esp = (esp - 0xc) + 0xc - 0x10;
            eax = sub_419870(&var_160, var_168, ebx, &var_158);
            ecx = *eax;
            ebx = eax[0x1];
            edi = ecx;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx + 0x14;
            &decomp_var_16c = ebp;
    }
    return eax;
}
