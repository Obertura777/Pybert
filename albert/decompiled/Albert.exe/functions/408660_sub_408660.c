// sub_408660 @ 0x408660
// hopper name: sub_408660
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_408660() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_34 = ebx;
    decomp_var_38 = ebp;
    decomp_var_3c = esi;
    esi = ecx;
    ebp = *esi[0x93e];
    ebx = esi + 0x24f4;
    esp = esp - 0x40;
    var_40 = edi;
    var_28 = esi;
    var_24 = ebx;
    var_20 = ebp;
    &var_40 = &var_40;
    goto loc_408690;

loc_408690:
    edi = esi[0x93e];
    eax = esi + 0x24f4;
    if (ebx == 0x0 || ebx != eax) {
            eax = sub_47a948();
    }
    if (ebp != edi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (ebp == ebx[0x1]) {
                    sub_47a948();
            }
            ebp = &arg_4;
            esi = esi + 0x2450;
            edi = sub_407720(ebp);
            esp = esp - 0x8;
            var_2C = sub_407720(edi + 0x1c);
            if (var_20 == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&var_C, ebp, var_40);
            if (edi[0xc] != 0x4) {
                    sub_401520();
                    ebx = var_24;
                    ebp = var_20;
                    esi = var_28;
                    continue;
            }
            esp = esp - 0x8;
            eax = sub_402060(&var_14, edi + 0x20, var_40, decomp_var_3c, decomp_var_38);
            ebp = *eax;
            ebx = eax[0x1];
            var_18 = esi[0x1];
            if (ebp == 0x0 || ebp != esi) {
                    sub_47a948();
            }
            if (ebx == var_18) {
                    eax = var_2C;
                    edi[0x44] = 0x1;
                    eax[0x10] = eax[0x10] + 0x1;
            }
            else {
                    if (ebp == 0x0) {
                            sub_47a948();
                    }
                    if (ebx == ret_addr) {
                            sub_47a948();
                    }
                    ebx = ebx[0x6];
                    if (edi[0x2] != ebx) {
                            eax = var_2C;
                            if (eax[0x2] != ebx) {
                                    edi[0x44] = 0x1;
                                    eax[0x10] = eax[0x10] + 0x1;
                            }
                    }
            }
            sub_401520();
            ebx = var_24;
            ebp = var_20;
            esi = var_28;
            continue;
    }
    break;
    &decomp_var_30 = decomp_var_38;
    return eax;
}
