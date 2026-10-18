// sub_437510 @ 0x437510
// hopper name: sub_437510
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_437510() {
    eax = ecx[0x2] + (arg_4 + arg_4 * 0x8) * 0x4;
    esp = esp - 0x8;
    if (eax[0x4] != 0x0) goto .l1;
    goto loc_43752a;

.l1:
    return eax;

loc_43752a:
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    decomp_var_14 = edi;
    eax = sub_4075b0(word_4c6c0c, decomp_var_14);
    ebp = eax;
    esi = *arg_0;
    edi = ebp;
    var_8 = edi;
    var_4 = esi;
    esp = esp - 0x14;
    var_18 = ebx;
    &var_18 = &var_18;
    goto loc_437550;

loc_437550:
    ebx = arg_0;
    if (edi == 0x0 || edi != ebp) {
            eax = sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (*(esi[0x3] * 0x4 + 0xba3f70) <= 0x0) {
                    eax = sub_40f400();
                    esi = var_4;
                    edi = var_8;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
            }
            eax = (arg_0 << 0x8) + esi[0x3];
            bool_6 = *(eax * 0x8 + 0x5ee8ec) > 0x0;
            if (*(eax * 0x8 + 0x5ee8ec) < 0x0) {
                    eax = sub_40f400();
                    esi = var_4;
                    edi = var_8;
                    continue;
            }
            if (!bool_6) {
                    if (*(eax * 0x8 + 0x5ee8e8) >= 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            *(esi[0x3] * 0x4 + 0xba3b70) = 0x1;
                    }
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    *(esi[0x3] * 0x4 + 0xba3b70) = 0x1;
            }
            eax = sub_40f400();
            esi = var_4;
            edi = var_8;
            continue;
    }
    break;
    esp = esp + 0x10;
    return eax;
}
