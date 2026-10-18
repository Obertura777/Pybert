// sub_47c836 @ 0x47c836
// hopper name: sub_47c836
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c836() {
    ebp = arg_0;
    if (ebp <= 0xffffffe0) {
            decomp_var_8 = ebx;
            decomp_var_c = esi;
            esp = esp - 0xc;
            decomp_var_10 = edi;
            while (true) {
                    esi = 0x0;
                    edi = ebp;
                    if (*dword_bc69f4 == 0x0) {
                            sub_488a85();
                            decomp_var_14 = 0x1e;
                            sub_4888e5(0x1e);
                            esp = esp - 0x8;
                            sub_47d8a0(0xff);
                    }
                    if (*dword_bc720c == 0x1) {
                            if (ebp != 0x0) {
                                    eax = ebp;
                            }
                            else {
                                    eax = 0x1;
                            }
                            esp = esp - 0x4;
                            decomp_var_14 = eax;
                            esp = esp - 0x8;
                            eax = HeapAlloc(*dword_bc69f4, 0x0, decomp_var_14);
                    }
                    else {
                            if (*dword_bc720c == 0x3) {
                                    decomp_var_14 = ebp;
                                    eax = sub_47c7e7();
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax == 0x0) {
                                            if (ebp == 0x0) {
                                                    edi = 0x1;
                                            }
                                            edi = edi + 0xf & 0xfffffff0;
                                            esp = esp - 0x4;
                                            decomp_var_14 = edi;
                                            esp = esp - 0x8;
                                            eax = HeapAlloc(*dword_bc69f4, 0x0, decomp_var_14);
                                    }
                            }
                            else {
                                    if (ebp == 0x0) {
                                            edi = 0x1;
                                    }
                                    edi = edi + 0xf & 0xfffffff0;
                                    esp = esp - 0x4;
                                    decomp_var_14 = edi;
                                    esp = esp - 0x8;
                                    eax = HeapAlloc(*dword_bc69f4, 0x0, decomp_var_14);
                            }
                    }
                    esi = eax;
                    if (esi != 0x0) {
                            temp_0 = 0x2;
                            break;
                    }
                    edi = 0xc;
                    esp = (esp - 0x4) + 0x4;
                    if (*dword_bc6d10 == eax) {
                            edi = 0xc;
                            *sub_47d812() = 0xc;
                            temp_0 = 0x1;
                            break;
                    }
                    esp = (esp - 0x4) + 0x4;
                    if (sub_488ac8(ebp) != 0x0) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
            if (temp_0 != 0x0 && temp_0 == 0x1) {
                    *sub_47d812() = edi;
            }
    }
    else {
            sub_488ac8(ebp);
            *sub_47d812() = 0xc;
    }
    return;
}
