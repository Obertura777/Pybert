// sub_4090d0 @ 0x4090d0
// hopper name: sub_4090d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4090d0() {
    esi = ecx;
    ecx = esi[0x93b];
    eax = ecx[0x1];
    ebp = ebp | 0xffffffff;
    esp = esp - 0x28;
    if (eax[0x15] == 0x0) {
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
    ebx = esi + 0x24e8;
    edi = ecx;
    arg_4 = ebx;
    arg_8 = edi;
    goto loc_409130;

loc_409130:
    ecx = esi[0x93b];
    eax = ecx[0x1];
    esi = ecx;
    if (eax[0x15] == 0x0) {
            if (edx < eax[0x3]) {
                    esi = eax;
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
    if (ebx == 0x0 || ebx != arg_8 + 0x24e8) {
            sub_47a948();
    }
    if (edi != esi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            esi = edi + 0x10;
            esp = esp - 0x4;
            eax = sub_407720(esi);
            ecx = eax[0xf];
            if (ecx > ebp) {
                    bool_11 = edi != ebx[0x1];
                    arg_4 = ebp;
                    ebp = ecx;
                    arg_c = eax[0x10];
                    if (!bool_11) {
                            sub_47a948();
                    }
                    arg_10 = *esi;
            }
            else {
                    if (ecx > arg_4) {
                            arg_4 = ecx;
                    }
            }
            sub_40f400();
            edi = arg_20;
            ebx = arg_1c;
            edx = arg_28;
            esi = arg_10;
            continue;
    }
    break;
    eax = arg_4;
    esp = esp + 0x10;
    if (ebp == eax) {
            eax = 0x2;
    }
    else {
            ecx = arg_c;
            if (arg_10 == arg_24) {
                    if (ecx > 0x0) {
                            if (ecx > eax) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = 0x1;
                            }
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    if (ecx > 0x0) {
                            bool_5 = ecx > eax;
                            eax = 0x4;
                            if (!bool_5) {
                                    eax = 0x3;
                            }
                    }
                    else {
                            eax = 0x3;
                    }
            }
    }
    return eax;
}
