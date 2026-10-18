// sub_40c4c0 @ 0x40c4c0
// hopper name: sub_40c4c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c4c0() {
    decomp_var_8 = 0x4946d9;
    decomp_var_c = *0x0;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    *0x0 = &decomp_var_c;
    edi = arg_8;
    ecx = *(*edi - 0x10);
    if (ecx != 0x0) {
            eax = *(*ecx + 0x10);
            eax = (eax)();
            if (eax == 0x0) {
                    eax = sub_47020b();
                    eax = *(*eax + 0x10);
                    eax = (eax)();
            }
    }
    else {
            eax = sub_47020b();
            eax = *(*eax + 0x10);
            eax = (eax)();
    }
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            *arg_0 = (*(*eax + 0xc))() + 0x10;
            edi = arg_4;
            decomp_var_4 = 0x0;
            decomp_var_10 = 0x1;
            if (edi == 0x0) {
                    eax = sub_40c57d(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
            }
            else {
                    eax = sub_40c570(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4);
            }
    }
    return eax;
}
