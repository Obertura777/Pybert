// sub_46ff8f @ 0x46ff8f
// hopper name: sub_46ff8f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ff8f() {
    ebp = &var_A0;
    arg_94 = *dword_4c8db8 ^ ebp;
    decomp_var_124 = ebx;
    decomp_var_128 = esi;
    decomp_var_12c = edi;
    edi = arg_a0;
    decomp_var_80 = arg_a4;
    sub_46feb0(0x0);
    esp = (esp - 0x12c) + 0x4 - 0x8;
    eax = sub_46fee4(0x0, &decomp_var_70, decomp_var_12c, decomp_var_128);
    ebx = eax;
    decomp_var_7c = ebx;
    if (ebx != decomp_var_70) {
            esp = esp - 0x8;
            EnableWindow(ebx, 0x1);
    }
    esi = 0x0;
    decomp_var_78 = decomp_var_78 & 0x0;
    esp = esp - 0x8;
    eax = GetWindowThreadProcessId(ebx, &decomp_var_78);
    if (ebx != 0x0) {
            if (decomp_var_78 == GetCurrentProcessId()) {
                    esp = esp - 0x10;
                    eax = SendMessageA(ebx, 0x376, 0x0, 0x0);
                    if (eax != 0x0) {
                            esi = eax;
                    }
                    else {
                            if (edi != 0x0) {
                                    esi = edi + 0x78;
                            }
                    }
            }
            else {
                    if (edi != 0x0) {
                            esi = edi + 0x78;
                    }
            }
    }
    else {
            if (edi != 0x0) {
                    esi = edi + 0x78;
            }
    }
    decomp_var_74 = decomp_var_74 & 0x0;
    if (esi != 0x0) {
            decomp_var_74 = *esi;
            eax = arg_ac;
            if (eax != 0x0) {
                    *esi = eax + 0x30000;
            }
    }
    if ((arg_a8 & 0xf0) == 0x0) {
            eax = arg_a8 & 0xf;
            if (eax > 0x1) {
                    if (eax <= 0x4) {
                            arg_a8 = arg_a8 | 0x20;
                    }
            }
            else {
                    arg_a8 = arg_a8 | 0x30;
            }
    }
    decomp_var_6c = 0x0;
    if (edi != 0x0) {
            ebx = edi[0x14];
    }
    else {
            ebx = &decomp_var_6c;
            esp = esp - 0xc;
            GetModuleFileNameA(0x0, ebx, 0x104) != 0x104;
    }
    decomp_var_130 = arg_a8;
    esp = (esp - 0x10) + 0x10;
    edi = sub_46fe19();
    if (esi != 0x0) {
            *esi = decomp_var_74;
    }
    if (decomp_var_70 != 0x0) {
            esp = esp - 0x8;
            EnableWindow(decomp_var_70, 0x1);
    }
    sub_46feb0(0x1);
    eax = sub_47ad69();
    return eax;
}
