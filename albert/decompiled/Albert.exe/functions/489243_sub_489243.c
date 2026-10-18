// sub_489243 @ 0x489243
// hopper name: sub_489243
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_489243() {
    var_8 = var_8 & 0x0;
    var_4 = var_4 & 0x0;
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    decomp_var_18 = edi;
    if (*dword_4c8db8 != 0xbb40e64e) {
            if ((0xffff0000 & *dword_4c8db8) != 0x0) {
                    eax = *dword_4c8db8;
                    eax = !eax;
                    *dword_4c8dbc = eax;
            }
            else {
                    GetSystemTimeAsFileTime(&var_8);
                    esi = var_4 ^ var_8 ^ GetCurrentProcessId();
                    esi = esi ^ GetCurrentThreadId();
                    esi = esi ^ GetTickCount();
                    esp = esp - 0xc;
                    QueryPerformanceCounter(&var_10);
                    eax = var_C ^ var_10;
                    esi = esi ^ eax;
                    if (esi == 0xbb40e64e) {
                            esi = 0xbb40e64f;
                    }
                    else {
                            if ((0xffff0000 & esi) == 0x0) {
                                    eax = esi << 0x10;
                                    esi = esi | eax;
                            }
                    }
                    *dword_4c8db8 = esi;
                    *dword_4c8dbc = !esi;
                    esp = esp + 0x4;
            }
    }
    else {
            GetSystemTimeAsFileTime(&var_8);
            esi = var_4 ^ var_8 ^ GetCurrentProcessId();
            esi = esi ^ GetCurrentThreadId();
            esi = esi ^ GetTickCount();
            esp = esp - 0xc;
            QueryPerformanceCounter(&var_10);
            eax = var_C ^ var_10;
            esi = esi ^ eax;
            if (esi == 0xbb40e64e) {
                    esi = 0xbb40e64f;
            }
            else {
                    if ((0xffff0000 & esi) == 0x0) {
                            eax = esi << 0x10;
                            esi = esi | eax;
                    }
            }
            *dword_4c8db8 = esi;
            *dword_4c8dbc = !esi;
            esp = esp + 0x4;
    }
    return eax;
}
