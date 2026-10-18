// sub_404bc0 @ 0x404bc0
// hopper name: sub_404bc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_404bc0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_18 = ebx;
    ebx = arg_0;
    ebx[0xc] = 0x9;
    edi = ecx;
    esp = esp - 0x24;
    sub_401950(*(ebx[0xe] + 0x4));
    eax = *(ebx + 0x38);
    eax[0x1] = eax;
    eax = *(ebx + 0x38);
    *(ebx + 0x3c) = 0x0;
    *eax = eax;
    esi = *(ebx + 0x38);
    esi[0x2] = esi;
    ebx[0x10] = 0x0;
    ebx[0x59] = 0x1;
    ecx = edi[0x93b];
    eax = ecx[0x1];
    esi = edi + 0x24e8;
    if (eax[0x15] == 0x0) {
            edx = ebx[0x5];
            do {
                    if (eax[0x3] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x15] == 0x0);
    }
    edi = esi;
    var_8 = ecx;
    goto loc_404c3a;

loc_404c3a:
    var_C = edi;
    goto loc_404c40;

loc_404c40:
    ecx = esi[0x1];
    eax = ecx[0x1];
    var_10 = ecx;
    if (eax[0x15] == 0x0) {
            ecx = ebx[0x5];
            do {
                    if (ecx < eax[0x3]) {
                            var_10 = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
    }
    if (edi == 0x0 || edi != esi) {
            eax = sub_47a948();
    }
    if (var_4 == var_C) goto loc_404cd0;
    goto loc_404c80;

loc_404cd0:
    &var_C = ebp;
    return eax;

loc_404c80:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (var_4 == edi[0x1]) {
            sub_47a948();
    }
    eax = var_4;
    if (eax[0x4] != *ebx) {
            sub_40f400();
            edi = var_8;
            continue;
    }
    break;
    esp = esp - 0xc;
    eax = sub_402eb0(&saved_fp, edi, eax, decomp_var_18, decomp_var_14, var_10, var_C, var_8, var_4, saved_fp, arg_fffffffffffffffc, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18);
    edi = *eax;
    var_4 = eax[0x1];
    continue;
}
