// sub_4093f0 @ 0x4093f0
// hopper name: sub_4093f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4093f0() {
    var_18 = ebx;
    esi = ecx;
    ecx = esi[0x93b];
    eax = ecx[0x1];
    esp = esp - 0x24;
    var_24 = edi;
    var_14 = esi;
    if (eax[0x15] == 0x0) {
            &var_24 = &var_24;
            do {
                    edx = arg_0;
                    if (eax[0x3] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x15] == 0x0);
    }
    else {
            edx = arg_0;
    }
    ebp = esi + 0x24e8;
    ebx = ecx;
    var_8 = ebp;
    var_4 = ebx;
    goto loc_409440;

loc_409440:
    ecx = esi[0x93b];
    eax = ecx[0x1];
    edi = ecx;
    if (eax[0x15] == 0x0) {
            if (edx < eax[0x3]) {
                    edi = eax;
                    eax = *eax;
            }
            else {
                    eax = eax[0x2];
            }
            if (eax[0x15] == 0x0) {
                    continue;
            }
            break;
    }
    if (ebp == 0x0 || ebp != esi + 0x24e8) {
            sub_47a948();
    }
    if (ebx != edi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            ebx = sub_407720(ebx + 0x10);
            ebx[0xc] = 0x9;
            ebp = *(ebx[0xe] + 0x4);
            esi = ebx + 0x34;
            edi = ebp;
            if (arg_d != 0x0) {
                    eax = esi[0x1];
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    ebx[0x10] = 0x0;
                    ebx[0x59] = 0x1;
                    sub_40f400();
                    ebx = saved_fp;
                    ebp = var_4;
                    edx = arg_c;
                    esi = var_8;
                    continue;
            }
            &var_18 = &var_18;
            do {
                    sub_401950(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x11] == 0x0);
            eax = esi[0x1];
            eax[0x1] = eax;
            eax = esi[0x1];
            esi[0x2] = 0x0;
            *eax = eax;
            esi = esi[0x1];
            esi[0x2] = esi;
            ebx[0x10] = 0x0;
            ebx[0x59] = 0x1;
            sub_40f400();
            ebx = saved_fp;
            ebp = var_4;
            edx = arg_c;
            esi = var_8;
            continue;
    }
    break;
    sub_401990(&var_4, &arg_c, var_18, var_14, decomp_var_10);
    var_8 = 0x0;
    sub_401f40(var_4, saved_fp, arg_0, arg_4, &var_8);
    sub_403b00(&var_4, var_4, saved_fp, arg_0, arg_4);
    eax = sub_404ce0(&var_4, &arg_c, var_18);
    return eax;
}
