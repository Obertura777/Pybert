// sub_405120 @ 0x405120
// hopper name: sub_405120
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_405120() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_c = ebp;
    ebp = arg_4;
    esp = esp - 0x10;
    esi = edx;
    var_8 = 0x1;
    if (eax[0x15] == 0x0) {
            esp = esp - 0x4;
            edi = *ebp;
            do {
                    bool_3 = edi < eax[0x3];
                    esi = eax;
                    var_8 = bool_3 ? 0x1 : 0x0;
                    if ((bool_3 ? 0x1 : 0x0) != 0x0) {
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
            esp = esp + 0x4;
    }
    eax = sub_403f60(&saved_fp, saved_fp, esi, ebp, var_8, decomp_var_4, saved_fp, arg_0, arg_4);
    ecx = eax;
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    eax[0x8] = 0x1;
    return eax;
}
