// sub_48f46e @ 0x48f46e
// hopper name: sub_48f46e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f46e() {
    decomp_var_24 = ebx;
    decomp_var_28 = esi;
    esp = esp - 0xc;
    decomp_var_2c = edi;
    var_10 = sub_47fe73();
    var_4 = 0x0;
    var_8 = 0x0;
    var_C = 0x0;
    if (*dword_bc6f58 == 0x0) {
            esp = esp - 0x4;
            edi = LoadLibraryA("USER32.DLL");
            if (edi == 0x0) {
                    eax = 0x0;
            }
            else {
                    ebx = 0x0;
                    esp = esp - 0x8;
                    eax = GetProcAddress(edi, "MessageBoxA");
                    if (eax != 0x0) {
                            *dword_bc6f58 = sub_47fe10(eax);
                            *dword_bc6f5c = sub_47fe10(GetProcAddress(edi, "GetActiveWindow"));
                            *dword_bc6f60 = sub_47fe10(GetProcAddress(edi, "GetLastActivePopup"));
                            eax = sub_47d8ff(&var_8);
                            esp = (esp - 0x18) + 0x8;
                            if (eax != 0x0) {
                                    ebx = 0x0;
                                    decomp_var_38 = 0x0;
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            if (var_8 == 0x2) {
                                    ebx = 0x0;
                                    eax = GetProcAddress(edi, "GetUserObjectInformationA");
                                    eax = sub_47fe10(eax);
                                    esp = (esp - 0xc) + 0x4;
                                    *dword_bc6f68 = eax;
                                    if (eax != 0x0) {
                                            esp = (esp - 0xc) + 0x4;
                                            *dword_bc6f64 = sub_47fe10(GetProcAddress(edi, "GetProcessWindowStation"));
                                    }
                            }
                            esi = var_10;
                            if (*dword_bc6f64 != esi) {
                                    if (*dword_bc6f68 != esi) {
                                            eax = *dword_bc6f64;
                                            eax = sub_47fe7c(eax);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = (eax)();
                                            if (eax != ebx) {
                                                    esp = (esp - 0x18) + 0x4;
                                                    if ((sub_47fe7c(*dword_bc6f68))() != 0x0) {
                                                            if ((var_18 & 0x1) == 0x0) {
                                                                    eax = sub_47d936(&var_C);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax != 0x0) {
                                                                            decomp_var_64 = ebx;
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    if (var_C >= 0x4) {
                                                                            arg_8 = arg_8 | 0x200000;
                                                                    }
                                                                    else {
                                                                            arg_8 = arg_8 | 0x40000;
                                                                    }
                                                                    eax = sub_47fe7c(*dword_bc6f58);
                                                                    esp = (esp - 0x14) + 0x4;
                                                                    eax = (eax)();
                                                            }
                                                            else {
                                                                    if (*dword_bc6f5c != esi) {
                                                                            eax = *dword_bc6f5c;
                                                                            eax = sub_47fe7c(eax);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = (eax)();
                                                                            var_4 = eax;
                                                                            if (eax != ebx) {
                                                                                    if (*dword_bc6f60 != esi) {
                                                                                            esp = (esp - 0x8) + 0x4;
                                                                                            var_4 = (sub_47fe7c(*dword_bc6f60))();
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = sub_47fe7c(*dword_bc6f58);
                                                                    esp = (esp - 0x14) + 0x4;
                                                                    eax = (eax)();
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47d936(&var_C);
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != 0x0) {
                                                                    decomp_var_64 = ebx;
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            if (var_C >= 0x4) {
                                                                    arg_8 = arg_8 | 0x200000;
                                                            }
                                                            else {
                                                                    arg_8 = arg_8 | 0x40000;
                                                            }
                                                            eax = sub_47fe7c(*dword_bc6f58);
                                                            esp = (esp - 0x14) + 0x4;
                                                            eax = (eax)();
                                                    }
                                            }
                                            else {
                                                    eax = sub_47d936(&var_C);
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax != 0x0) {
                                                            decomp_var_64 = ebx;
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    if (var_C >= 0x4) {
                                                            arg_8 = arg_8 | 0x200000;
                                                    }
                                                    else {
                                                            arg_8 = arg_8 | 0x40000;
                                                    }
                                                    eax = sub_47fe7c(*dword_bc6f58);
                                                    esp = (esp - 0x14) + 0x4;
                                                    eax = (eax)();
                                            }
                                    }
                                    else {
                                            if (*dword_bc6f5c != esi) {
                                                    eax = *dword_bc6f5c;
                                                    eax = sub_47fe7c(eax);
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = (eax)();
                                                    var_4 = eax;
                                                    if (eax != ebx) {
                                                            if (*dword_bc6f60 != esi) {
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    var_4 = (sub_47fe7c(*dword_bc6f60))();
                                                            }
                                                    }
                                            }
                                            eax = sub_47fe7c(*dword_bc6f58);
                                            esp = (esp - 0x14) + 0x4;
                                            eax = (eax)();
                                    }
                            }
                            else {
                                    if (*dword_bc6f5c != esi) {
                                            eax = *dword_bc6f5c;
                                            eax = sub_47fe7c(eax);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = (eax)();
                                            var_4 = eax;
                                            if (eax != 0x0) {
                                                    if (*dword_bc6f60 != esi) {
                                                            esp = (esp - 0x8) + 0x4;
                                                            var_4 = (sub_47fe7c(*dword_bc6f60))();
                                                    }
                                            }
                                    }
                                    eax = sub_47fe7c(*dword_bc6f58);
                                    esp = (esp - 0x14) + 0x4;
                                    eax = (eax)();
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    else {
            esi = var_10;
            if (*dword_bc6f64 != esi) {
                    if (*dword_bc6f68 != esi) {
                            eax = *dword_bc6f64;
                            eax = sub_47fe7c(eax);
                            esp = (esp - 0x4) + 0x4;
                            eax = (eax)();
                            if (eax != 0x0) {
                                    esp = (esp - 0x18) + 0x4;
                                    if ((sub_47fe7c(*dword_bc6f68))() != 0x0) {
                                            if ((var_18 & 0x1) == 0x0) {
                                                    eax = sub_47d936(&var_C);
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax != 0x0) {
                                                            decomp_var_64 = 0x0;
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    if (var_C >= 0x4) {
                                                            arg_8 = arg_8 | 0x200000;
                                                    }
                                                    else {
                                                            arg_8 = arg_8 | 0x40000;
                                                    }
                                                    eax = sub_47fe7c(*dword_bc6f58);
                                                    esp = (esp - 0x14) + 0x4;
                                                    eax = (eax)();
                                            }
                                            else {
                                                    if (*dword_bc6f5c != esi) {
                                                            eax = *dword_bc6f5c;
                                                            eax = sub_47fe7c(eax);
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = (eax)();
                                                            var_4 = eax;
                                                            if (eax != 0x0) {
                                                                    if (*dword_bc6f60 != esi) {
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            var_4 = (sub_47fe7c(*dword_bc6f60))();
                                                                    }
                                                            }
                                                    }
                                                    eax = sub_47fe7c(*dword_bc6f58);
                                                    esp = (esp - 0x14) + 0x4;
                                                    eax = (eax)();
                                            }
                                    }
                                    else {
                                            eax = sub_47d936(&var_C);
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax != 0x0) {
                                                    decomp_var_64 = 0x0;
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            if (var_C >= 0x4) {
                                                    arg_8 = arg_8 | 0x200000;
                                            }
                                            else {
                                                    arg_8 = arg_8 | 0x40000;
                                            }
                                            eax = sub_47fe7c(*dword_bc6f58);
                                            esp = (esp - 0x14) + 0x4;
                                            eax = (eax)();
                                    }
                            }
                            else {
                                    eax = sub_47d936(&var_C);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax != 0x0) {
                                            decomp_var_64 = 0x0;
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    if (var_C >= 0x4) {
                                            arg_8 = arg_8 | 0x200000;
                                    }
                                    else {
                                            arg_8 = arg_8 | 0x40000;
                                    }
                                    eax = sub_47fe7c(*dword_bc6f58);
                                    esp = (esp - 0x14) + 0x4;
                                    eax = (eax)();
                            }
                    }
                    else {
                            if (*dword_bc6f5c != esi) {
                                    eax = *dword_bc6f5c;
                                    eax = sub_47fe7c(eax);
                                    esp = (esp - 0x4) + 0x4;
                                    eax = (eax)();
                                    var_4 = eax;
                                    if (eax != 0x0) {
                                            if (*dword_bc6f60 != esi) {
                                                    esp = (esp - 0x8) + 0x4;
                                                    var_4 = (sub_47fe7c(*dword_bc6f60))();
                                            }
                                    }
                            }
                            eax = sub_47fe7c(*dword_bc6f58);
                            esp = (esp - 0x14) + 0x4;
                            eax = (eax)();
                    }
            }
            else {
                    if (*dword_bc6f5c != esi) {
                            eax = *dword_bc6f5c;
                            eax = sub_47fe7c(eax);
                            esp = (esp - 0x4) + 0x4;
                            eax = (eax)();
                            var_4 = eax;
                            if (eax != 0x0) {
                                    if (*dword_bc6f60 != esi) {
                                            esp = (esp - 0x8) + 0x4;
                                            var_4 = (sub_47fe7c(*dword_bc6f60))();
                                    }
                            }
                    }
                    eax = sub_47fe7c(*dword_bc6f58);
                    esp = (esp - 0x14) + 0x4;
                    eax = (eax)();
            }
    }
    return eax;
}
