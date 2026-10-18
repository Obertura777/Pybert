// sub_4896f8 @ 0x4896f8
// hopper name: sub_4896f8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4896f8() {
    ebp = &var_68;
    arg_5c = *dword_4c8db8 ^ ebp;
    eax = arg_68;
    decomp_var_9c = ebx;
    decomp_var_a0 = esi;
    esi = arg_78;
    esp = esp - 0xa0;
    decomp_var_a4 = edi;
    decomp_var_28 = eax;
    decomp_var_30 = esi;
    if (arg_6c == 0x1) {
            edi = &decomp_var_20;
            decomp_var_24 = 0x0;
            esi = sub_48f905(eax, arg_70, arg_74, edi, 0x80, 0x0);
            esp = (esp - 0x18) + 0x18;
            if (esi == 0x0) {
                    eax = GetLastError();
                    if (eax == 0x7a) {
                            ebx = 0x0;
                            eax = sub_48f905(decomp_var_28, arg_70, arg_74, 0x0, 0x0, 0x0);
                            esp = (esp - 0x18) + 0x18;
                            decomp_var_2c = eax;
                            if (eax != 0x0) {
                                    eax = sub_4812c0(eax, 0x1);
                                    edi = eax;
                                    esp = (esp - 0x8) + 0x8;
                                    if (edi != ebx) {
                                            decomp_var_24 = 0x1;
                                            esi = sub_48f905(decomp_var_28, arg_70, arg_74, edi, decomp_var_2c, ebx);
                                            esp = (esp - 0x18) + 0x18;
                                            if (esi != ebx) {
                                                    eax = sub_4812c0(esi, 0x1);
                                                    esp = (esp - 0x8) + 0x8;
                                                    *decomp_var_30 = eax;
                                                    if (eax == ebx) {
                                                            if (decomp_var_24 != ebx) {
                                                                    eax = sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            esp = (esp - 0x10) + 0x10;
                                                            if (sub_47f4a4(eax, esi, edi, esi - 0x1) != 0x0) {
                                                                    ebx = 0x0;
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            if (decomp_var_24 != ebx) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    eax = sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            eax = sub_47ad69();
                    }
            }
            else {
                    eax = sub_4812c0(esi, 0x1);
                    esp = (esp - 0x8) + 0x8;
                    *decomp_var_30 = eax;
                    if (eax == 0x0) {
                            if (decomp_var_24 != 0x0) {
                                    eax = sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    else {
                            esp = (esp - 0x10) + 0x10;
                            if (sub_47f4a4(eax, esi, edi, esi - 0x1) != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            if (decomp_var_24 != 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    eax = sub_47ad69();
            }
    }
    else {
            if (arg_6c == 0x0) {
                    ebx = 0x0;
                    edi = 0xbc6e3c;
                    eax = sub_48f78d(eax, arg_70, arg_74, 0xbc6e3c, 0x4, 0x0);
                    esp = (esp - 0x18) + 0x18;
                    if (eax != 0x0) {
                            *(int8_t *)esi = ebx;
                            while (true) {
                                    ebx = *(int8_t *)edi;
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_47d09a(ebx & 0xff) == 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    edi = edi + 0x2;
                                    *(int8_t *)esi = *(int8_t *)esi * 0xa + ebx - 0x30;
                                    if (edi < dword_bc6e44) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
            }
            eax = sub_47ad69();
    }
    return eax;
}
