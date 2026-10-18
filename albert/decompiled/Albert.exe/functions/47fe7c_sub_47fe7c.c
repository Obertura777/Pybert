// sub_47fe7c @ 0x47fe7c
// hopper name: sub_47fe7c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47fe7c() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    if (TlsGetValue(*dword_4c8fc4) != 0x0) {
            if (*dword_4c8fc0 != 0xffffffff) {
                    eax = *dword_4c8fc0;
                    esp = esp - 0x8;
                    eax = TlsGetValue(*dword_4c8fc4, eax);
                    eax = (eax)();
                    if (eax != 0x0) {
                            eax = eax[0x7f];
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    arg_0 = (eax)(arg_0);
                            }
                            eax = arg_0;
                    }
                    else {
                            esp = esp - 0x4;
                            eax = GetModuleHandleA("KERNEL32.DLL");
                            if (eax != 0x0) {
                                    esp = esp - 0x8;
                                    eax = GetProcAddress(eax, "DecodePointer");
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            arg_0 = (eax)(arg_0);
                                    }
                                    eax = arg_0;
                            }
                            else {
                                    eax = arg_0;
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    eax = GetModuleHandleA("KERNEL32.DLL");
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            eax = GetProcAddress(eax, "DecodePointer");
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    arg_0 = (eax)(arg_0);
                            }
                            eax = arg_0;
                    }
                    else {
                            eax = arg_0;
                    }
            }
    }
    else {
            esp = esp - 0x4;
            eax = GetModuleHandleA("KERNEL32.DLL");
            if (eax != 0x0) {
                    esp = esp - 0x8;
                    eax = GetProcAddress(eax, "DecodePointer");
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            arg_0 = (eax)(arg_0);
                    }
                    eax = arg_0;
            }
            else {
                    eax = arg_0;
            }
    }
    return eax;
}
