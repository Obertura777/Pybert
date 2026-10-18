// sub_40b080 @ 0x40b080
// hopper name: sub_40b080
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b080() {

sub_40b080:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (ebp == esi) goto loc_40b127;
    goto loc_40b098;

loc_40b127:
    if (arg_12 != 0x1) goto loc_40b2f9;
    goto loc_40b132;

loc_40b098:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    if (arg_4 != arg_1c) {
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            arg_24 = arg_4;
            esi = sub_409640(arg_4, 0x0, saved_fp, arg_0, arg_4, arg_8);
            esp = esp - 0xc;
            decomp_var_4 = arg_4;
            if (esi == 0xffffffff) {
                    sub_4093f0(decomp_var_4, saved_fp, arg_0, arg_4);
            }
            else {
                    sub_4095a0(decomp_var_4);
                    sub_409250(esi);
                    esp = esp - 0x8;
                    eax = sub_407720(&arg_24);
                    eax[0x5a] = 0x1;
                    eax[0x14] = esi;
                    arg_12 = 0x1;
            }
    }
    edi = ebx;
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    ebp = *ebp;
    goto sub_40b080;

loc_40b2f9:
    eax = loc_40b2fd();
    return eax;

loc_40b132:
    edi = *ebx[0x1];
    esi = ebx;
    &saved_fp = &saved_fp;
    goto loc_40b140;

loc_40b140:
    ebp = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi == ebp) goto loc_40b18f;
    goto loc_40b154;

loc_40b18f:
    ebx = arg_28;
    ebx[0xc] = 0x9;
    ebx[0x56] = 0x1;
    ebp = *(ebx[0xe] + 0x4);
    esi = ebx + 0x34;
    edi = ebp;
    if (arg_d != 0x0) goto loc_40b1ce;
    goto loc_40b1af;

loc_40b154:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    *(sub_407720(edi + 0x8) + 0x30) = 0x1;
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    edi = *edi;
    goto loc_40b140;

loc_40b1ce:
    eax = esi[0x1];
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    esi = esi[0x1];
    edi = arg_14 + 0x2518;
    esi[0x2] = esi;
    ebx[0x10] = 0x0;
    eax = sub_405c60(&arg_18);
    esp = esp - 0xc;
    eax = sub_4020d0(&arg_3c, eax, saved_fp, arg_0, arg_4);
    esi = *eax;
    ebx = eax[0x1];
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    esi = arg_38;
    ebx[0x5] = 0x0;
    ebx[0x6] = 0x0;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi[0x4] = 0xffffffff;
    edi = edi[0x1];
    if (*(int8_t *)(edi[0x1] + 0x1d) != 0x0) goto loc_40b26a;
    goto loc_40b24b;

loc_40b1af:
    goto loc_40b1b0;

loc_40b26a:
    edx = arg_18;
    ecx = arg_14[0x947];
    eax = ecx[0x1];
    esi = ecx;
    if (eax[0x1d] != 0x0) goto loc_40b29c;
    goto loc_40b288;

loc_40b24b:
    eax = sub_40b250(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14);
    return eax;

loc_40b1b0:
    sub_401950(edi[0x2]);
    edi = *edi;
    sub_47c8f9();
    esp = (esp - 0x8) + 0x4;
    ebp = edi;
    if (edi[0x11] == 0x0) goto loc_40b1b0;
    goto loc_40b1ce;

loc_40b29c:
    eax = arg_14 + 0x2518;
    arg_2c = eax;
    arg_30 = esi;
    goto loc_40b2b0;

loc_40b288:
    if (eax[0x3] < edx) {
            eax = eax[0x2];
    }
    else {
            esi = eax;
            eax = *eax;
    }
    if (eax[0x1d] == 0x0) goto loc_40b288;
    goto loc_40b29c;

loc_40b2b0:
    if (eax == 0x0 || eax != arg_14 + 0x2518) {
            sub_47a948();
    }
    if (arg_30 == edi) goto loc_40b2dc;
    goto loc_40b2cd;

loc_40b2dc:
    sub_403bd0(&arg_44, arg_14 + 0x2518, esi, arg_14 + 0x2518, edi);
    goto loc_40b2f9;

loc_40b2cd:
    sub_401590();
    eax = arg_2c;
    goto loc_40b2b0;
}
