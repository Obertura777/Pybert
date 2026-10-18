// sub_470d40 @ 0x470d40
// hopper name: sub_470d40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470d40() {
    if (*dword_bc470c == 0x0) {
            esp = esp - 0x4;
            eax = GetModuleHandleA("KERNEL32");
            *dword_bc470c = eax;
            if (eax == 0x0) {
                    sub_46dedc();
            }
            eax = GetProcAddress(eax, "CreateActCtxW");
            decomp_var_8 = *dword_bc470c;
            *dword_bc46fc = eax;
            eax = GetProcAddress(decomp_var_8, "ReleaseActCtx");
            decomp_var_8 = *dword_bc470c;
            *dword_bc4700 = eax;
            eax = GetProcAddress(decomp_var_8, "ActivateActCtx");
            decomp_var_8 = *dword_bc470c;
            *dword_bc4704 = eax;
            *dword_bc4708 = GetProcAddress(decomp_var_8, "DeactivateActCtx");
    }
    return;
}
