// sub_40afa0 @ 0x40afa0
// hopper name: sub_40afa0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40afa0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_44 = ebx;
    decomp_var_48 = ebp;
    decomp_var_4c = esi;
    esp = esp - 0x50;
    decomp_var_50 = edi;
    edi = ecx;
    ebx = *edi[0x947];
    eax = edi + 0x2518;
    var_38 = edi;
    var_39 = 0x0;
    var_14 = ebx;
    goto loc_40afd0;

loc_40afd0:
    esi = eax[0x1];
    ebp = eax;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (ebx != esi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == ret_addr) {
                    sub_47a948();
            }
            var_2C = ebx[0x3];
            if (ebx == ret_addr) {
                    sub_47a948();
            }
            if (ebx[0x4] == 0xffffffff) {
                    ecx = edi[0x947];
                    eax = ecx[0x1];
                    if (eax[0x1d] != 0x0) {
                            eax = edi + 0x2518;
                            var_14 = ecx;
                            ebx = ecx;
                            continue;
                    }
                    edx = var_2C;
                    do {
                            if (edx < eax[0x3]) {
                                    ecx = eax;
                                    eax = *eax;
                            }
                            else {
                                    eax = eax[0x2];
                            }
                    } while (eax[0x1d] == 0x0);
                    eax = edi + 0x2518;
                    var_14 = ecx;
                    ebx = ecx;
                    continue;
            }
            edi = edi + 0x2450;
            eax = sub_407720(&var_2C);
            esp = esp - 0x8;
            eax = sub_407720(eax + 0x14);
            if (eax[0xc] == 0x3) {
                    var_30 = eax[0x7];
                    temp_0 = 0x1;
            }
            else {
                    var_30 = eax[0x8];
                    temp_0 = 0x1;
            }
            break;
    }
    else {
            eax = var_39;
            edi = decomp_var_50;
            ebx = decomp_var_44;
            &decomp_var_40 = decomp_var_48;
            esp = esp + 0x14;
            temp_0 = 0x0;
            break;
    }
    goto .l2;

.l2:
    if (temp_0 != 0x0) {
            if (ebx == ret_addr) {
                    sub_47a948();
            }
            var_34 = ebx[0x4];
            eax = sub_407720(&var_34);
            eax = sub_40b080(decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, var_38, var_34, var_30, var_2C, decomp_var_28, eax, decomp_var_20, decomp_var_1c, decomp_var_18, var_14, decomp_var_10, decomp_var_c);
    }
    return eax;
}
