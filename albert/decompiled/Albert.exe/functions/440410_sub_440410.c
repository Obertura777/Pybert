// sub_440410 @ 0x440410
// hopper name: sub_440410
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_440410() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = arg_4;
    esi = ecx;
    ebp = *esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    ebx = arg_8;
    if (ebx != ebp) goto .l4;
    goto loc_440437;

.l4:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40f6f0();
            esp = esp - 0xc;
            eax = sub_430fb0(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c);
            ebx = arg_8;
            edi = arg_4;
            continue;
    }
    break;

loc_440437:
    eax = arg_c;
    ebp = esi[0x1];
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (arg_10 != ebp) goto .l2;
    goto loc_440451;
    eax = arg_0;
    *eax = edi;
    eax[0x1] = ebx;
    return eax;

.l2:
    goto loc_440490;

loc_440451:
    sub_4312a0(*(esi[0x1] + 0x4));
    eax = esi[0x1];
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    eax = esi[0x1];
    eax[0x2] = eax;
    ecx = *esi[0x1];
    eax = arg_0;
    *eax = esi;
    eax[0x1] = ecx;
    return eax;

loc_440490:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40f6f0();
            esp = esp - 0xc;
            eax = sub_430fb0(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c);
            ebx = arg_8;
            edi = arg_4;
            continue;
    }
    break;
    eax = arg_0;
    *eax = edi;
    eax[0x1] = ebx;
    return eax;
}
