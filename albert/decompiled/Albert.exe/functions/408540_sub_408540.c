// sub_408540 @ 0x408540
// hopper name: sub_408540
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_408540() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_24 = ebx;
    decomp_var_28 = ebp;
    decomp_var_2c = esi;
    esi = ecx;
    ebx = esi + 0x24e8;
    esp = esp - 0x30;
    var_30 = edi;
    edi = *esi[0x93b];
    var_1C = esi;
    var_18 = ebx;
    var_14 = edi;
    &var_30 = &var_30;
    goto loc_408570;

loc_408570:
    ebp = esi[0x93b];
    eax = esi + 0x24e8;
    if (ebx == 0x0 || ebx != eax) {
            eax = sub_47a948();
    }
    if (edi != ebp) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            esi = esi + 0x2450;
            ebp = sub_407720(edi + 0x10);
            esp = esp - 0xc;
            eax = sub_402060(&var_8, &arg_c, var_30, decomp_var_2c, decomp_var_28);
            edi = *eax;
            ebx = eax[0x1];
            var_C = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebx == var_C) {
                    sub_40f400();
                    edi = var_14;
                    ebx = var_18;
                    esi = var_1C;
                    continue;
            }
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx + 0x10;
            if (ebx[0x6] != arg_0) {
                    ecx = eax[0xc];
                    if (ecx == 0x3 || ecx == 0x4 && eax[0x8] != *ebp) {
                            esp = esp - 0x4;
                            eax[0x58] = 0x1;
                            eax[0xc] = 0x1;
                            sub_404da0(eax);
                    }
            }
            sub_40f400();
            edi = var_14;
            ebx = var_18;
            esi = var_1C;
            continue;
    }
    break;
    &decomp_var_20 = decomp_var_28;
    return eax;
}
