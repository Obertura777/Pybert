// sub_41a950 @ 0x41a950
// hopper name: sub_41a950
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41a950() {
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
    goto loc_41a977;

.l4:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40e680();
            esp = esp - 0xc;
            eax = sub_4179f0(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c);
            ebx = arg_8;
            edi = arg_4;
            continue;
    }
    break;

loc_41a977:
    eax = arg_c;
    ebp = esi[0x1];
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (arg_10 != ebp) goto .l2;
    goto loc_41a991;
    eax = arg_0;
    *eax = edi;
    eax[0x1] = ebx;
    return eax;

.l2:
    goto loc_41a9d0;

loc_41a991:
    sub_40fb70(*(esi[0x1] + 0x4));
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

loc_41a9d0:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40e680();
            esp = esp - 0xc;
            eax = sub_4179f0(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c);
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
