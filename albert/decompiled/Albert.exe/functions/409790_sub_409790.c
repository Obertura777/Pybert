// sub_409790 @ 0x409790
// hopper name: sub_409790
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_409790() {
    decomp_var_18 = ebx;
    esi = ecx;
    ecx = esi[0x93b];
    eax = ecx[0x1];
    ebp = ebp | 0xffffffff;
    esp = esp - 0x24;
    var_10 = esi;
    var_14 = ebp;
    if (eax[0x15] == 0x0) {
            edx = arg_0;
            if (eax[0x3] < edx) {
                    eax = eax[0x2];
            }
            else {
                    ecx = eax;
                    eax = *eax;
            }
            if (eax[0x15] == 0x0) {
                    continue;
            }
            break;
    }
    else {
            edx = arg_0;
    }
    ebx = esi + 0x24e8;
    edi = ecx;
    saved_fp = ebx;
    while (true) {
            ecx = esi[0x93b];
            eax = ecx[0x1];
            esi = ecx;
            if (eax[0x15] == 0x0) {
                    do {
                            if (edx < eax[0x3]) {
                                    esi = eax;
                                    eax = *eax;
                            }
                            else {
                                    eax = eax[0x2];
                            }
                    } while (eax[0x15] == 0x0);
            }
            if (ebx != 0x0) {
                    eax = var_4 + 0x24e8;
                    if (ebx != eax) {
                            eax = sub_47a948();
                    }
            }
            else {
                    eax = sub_47a948();
            }
            if (edi == esi) {
                    break;
            }
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            esi = edi + 0x10;
            esp = esp - 0x4;
            eax = sub_407720(esi);
            eax = eax[0xf];
            if (eax > ebp) {
                    var_8 = ebp;
                    ebp = eax;
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    saved_fp = *esi;
            }
            else {
                    if (eax > var_8) {
                            var_8 = eax;
                    }
            }
            sub_40f400();
            edi = arg_8;
            ebx = arg_4;
            edx = arg_10;
            esi = saved_fp;
    }
    esp = esp + 0x10;
    if (ebp <= var_8) {
            eax = eax | 0xffffffff;
    }
    else {
            eax = saved_fp;
    }
    return eax;
}
