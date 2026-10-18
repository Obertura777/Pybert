// sub_409640 @ 0x409640
// hopper name: sub_409640
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_409640() {
    edx = ecx;
    ecx = edx[0x93b];
    eax = ecx[0x1];
    ebp = ebp | 0xffffffff;
    esp = esp - 0x28;
    var_14 = edx;
    var_10 = ebp;
    var_18 = ebp;
    if (eax[0x15] == 0x0) {
            if (eax[0x3] < arg_0) {
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
    ebx = edx + 0x24e8;
    edi = ecx;
    saved_fp = ebx;
    arg_0 = edi;
    goto loc_409690;

loc_409690:
    ecx = edx[0x93b];
    eax = ecx[0x1];
    esi = ecx;
    if (eax[0x15] == 0x0) {
            do {
                    if (arg_8 < eax[0x3]) {
                            esi = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
    }
    if (ebx == 0x0 || ebx != edx + 0x24e8) {
            sub_47a948();
            edx = var_4;
    }
    if (edi != esi) {
            if (ebx == 0x0) {
                    sub_47a948();
                    edx = var_4;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
                    edx = var_4;
            }
            esi = edi + 0x10;
            esp = esp - 0x4;
            eax = sub_407720(esi);
            ecx = eax[0xf];
            if (ecx > ebp) {
                    bool_10 = edi != ebx[0x1];
                    var_8 = ebp;
                    ebp = ecx;
                    saved_fp = eax[0x10];
                    if (!bool_10) {
                            sub_47a948();
                    }
                    arg_0 = *esi;
            }
            else {
                    if (ecx > var_8) {
                            var_8 = ecx;
                    }
            }
            sub_40f400();
            edi = arg_10;
            ebx = arg_c;
            edx = arg_0;
            continue;
    }
    break;
    esp = esp + 0x10;
    if (arg_14 == 0x0) {
            esp = esp - 0x4;
            eax = sub_407720(&arg_10);
            eax = eax[0xf];
            if (eax > var_8) {
                    var_8 = eax;
            }
    }
    eax = saved_fp;
    if (eax > var_8 && eax > 0x0) {
            eax = arg_0;
    }
    else {
            eax = eax | 0xffffffff;
    }
    return eax;
}
