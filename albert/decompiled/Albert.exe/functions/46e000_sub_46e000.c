// sub_46e000 @ 0x46e000
// hopper name: sub_46e000
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e000() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    ebp = ecx;
    *ebp = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (*(int8_t *)byte_bc46e0 == 0x0) {
            esp = esp - 0x4;
            edi = GetModuleHandleA("KERNEL32");
            if (edi == 0x0) {
                    sub_46dedc();
            }
            ebx = 0x0;
            *dword_bc46d0 = GetProcAddress(edi, "CreateActCtxA");
            *dword_bc46d4 = GetProcAddress(edi, "ReleaseActCtx");
            *dword_bc46d8 = GetProcAddress(edi, "ActivateActCtx");
            eax = GetProcAddress(edi, "DeactivateActCtx");
            bool_2 = *dword_bc46d0 == 0x0;
            *dword_bc46dc = eax;
            esp = (esp - 0x24) + 0x4;
            if (!bool_2) {
                    if (*dword_bc46d4 == ebx) {
                            sub_46dedc();
                    }
                    if (*dword_bc46d8 == ebx) {
                            sub_46dedc();
                    }
                    if (eax == ebx) {
                            sub_46dedc();
                    }
                    *(int8_t *)byte_bc46e0 = 0x1;
                    eax = ebp;
            }
            else {
                    if (*dword_bc46d4 != ebx) {
                            sub_46dedc();
                    }
                    if (*dword_bc46d8 != ebx) {
                            sub_46dedc();
                    }
                    if (eax != ebx) {
                            sub_46dedc();
                    }
                    *(int8_t *)byte_bc46e0 = 0x1;
                    eax = ebp;
            }
    }
    else {
            eax = ebp;
    }
    return eax;
}
