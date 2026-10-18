// sub_409250 @ 0x409250
// hopper name: sub_409250
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_409250() {
    decomp_var_20 = ebx;
    decomp_var_24 = ebp;
    esp = esp - 0x30;
    decomp_var_18 = ecx + 0x2450;
    eax = sub_407720(&arg_0);
    edx = eax[0x5];
    esi = ecx + 0x24e8;
    eax[0x5b] = 0x1;
    ecx = esi[0x1];
    eax = ecx[0x1];
    decomp_var_1c = edx;
    decomp_var_14 = esi;
    if (eax[0x15] == 0x0) {
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
    ebx = esi;
    ebp = ecx;
    decomp_var_c = ebx;
    decomp_var_8 = ebp;
    goto loc_4092b0;

loc_4092b0:
    ecx = esi[0x1];
    eax = ecx[0x1];
    edi = ecx;
    if (eax[0x15] == 0x0) {
            do {
                    if (edx < eax[0x3]) {
                            edi = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
    }
    if (ebx == 0x0 || ebx != esi) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (ebp == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_407720(&arg_c);
            ebx = eax;
            if (*ebx != arg_8) {
                    ebx[0xc] = 0x9;
                    esi = ebx + 0x34;
                    if (arg_d == 0x0) {
                            sub_409330();
                    }
                    eax = esi[0x1];
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    esi = decomp_var_c;
                    ebx[0x10] = 0x0;
                    ebx[0x59] = 0x1;
                    sub_40f400();
                    ebp = decomp_var_4;
                    ebx = decomp_var_8;
                    edx = decomp_var_14;
                    continue;
            }
            sub_40f400();
            ebp = decomp_var_4;
            ebx = decomp_var_8;
            edx = decomp_var_14;
            continue;
    }
    sub_401990(&decomp_var_8, &decomp_var_14, decomp_var_24, decomp_var_20, decomp_var_1c);
    arg_8 = 0x0;
    sub_401f40(decomp_var_8, decomp_var_4, saved_fp, arg_0, &arg_8);
    sub_403b00(&decomp_var_8, decomp_var_8, decomp_var_4, saved_fp, arg_0);
    break;
    return;
}
