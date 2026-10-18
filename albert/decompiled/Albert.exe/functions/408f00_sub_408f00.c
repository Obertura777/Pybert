// sub_408f00 @ 0x408f00
// hopper name: sub_408f00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_408f00() {

sub_408f00:
    edi = arg_24e8;
    eax = &arg_24e4;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (arg_20 == edi) goto loc_4090bc;
    goto loc_408f23;

loc_4090bc:
    &arg_c = arg_4;
    return eax;

loc_408f23:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (arg_20 == esi[0x1]) {
            sub_47a948();
    }
    edi = &arg_244c;
    esp = esp - 0x4;
    esi = sub_407720(arg_20 + 0x10);
    arg_18 = ebx;
    arg_c = 0xffffffff;
    goto loc_408f60;

loc_408f60:
    if (esi[0x12] != 0xffffffff) goto loc_408fd7;
    goto loc_408f66;

loc_408fd7:
    eax = esi[0x12];
    if (eax >= arg_18) {
            if (ebx - eax < 0x3 && arg_c < eax) {
                    esp = esp - 0x4;
                    eax = sub_407720(esi + 0x14);
                    if (esi[0x10] > eax[0xf]) {
                            esp = esp - 0x8;
                            eax = sub_404ce0(&arg_2c, esi, saved_fp);
                            sub_40f400();
                            esi = arg_1c;
                    }
                    else {
                            if (eax[0x10] > esi[0xf]) {
                                    esp = esp - 0x8;
                                    eax = sub_404ce0(&arg_38, eax, saved_fp);
                                    sub_40f400();
                                    esi = arg_1c;
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_404ce0(&arg_44, esi, saved_fp);
                                    sub_40f400();
                                    esi = arg_1c;
                            }
                    }
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_404ce0(&arg_50, esi, saved_fp);
                    sub_40f400();
                    esi = arg_1c;
            }
    }
    else {
            sub_40f400();
            esi = arg_1c;
    }
    goto sub_408f00;

loc_408f66:
    eax = esi[0xc];
    if (eax == 0x2 || eax == 0x6) goto loc_408f77;
    goto loc_4090aa;

loc_408f77:
    esi[0x12] = ebx;
    if (eax == 0x6) {
            arg_c = ebx;
    }
    esp = esp - 0x8;
    arg_10 = ebx + 0x1;
    eax = sub_402060(&arg_24, esi + 0x14, saved_fp, arg_0, arg_4);
    esi = *eax;
    ebx = eax[0x1];
    ebp = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (ebx == ebp) goto loc_4090a2;
    goto loc_408fb7;

loc_4090aa:
    sub_40f400();
    esi = arg_1c;
    goto sub_408f00;

loc_4090a2:
    ebx = arg_10;
    goto loc_4090aa;

loc_408fb7:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    esi = ebx + 0x10;
    ebx = arg_10;
    goto loc_408f60;
}
