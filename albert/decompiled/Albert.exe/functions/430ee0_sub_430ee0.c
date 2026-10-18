// sub_430ee0 @ 0x430ee0
// hopper name: sub_430ee0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_430ee0() {
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
    if (ebx != ebp) goto loc_430f60;
    goto loc_430f07;

loc_430f60:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40f470();
            esp = esp - 0xc;
            eax = sub_42ea00(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24);
            ebx = arg_8;
            edi = arg_4;
            continue;
    }
    break;

loc_430f07:
    eax = arg_c;
    ebp = esi[0x1];
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (arg_10 != ebp) goto .l2;
    goto loc_430f21;
    eax = arg_0;
    *eax = edi;
    eax[0x1] = ebx;
    return eax;

.l2:
    goto .l4;

loc_430f21:
    sub_430500(*(esi[0x1] + 0x4));
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

.l4:
    if (edi == 0x0 || edi != arg_c) {
            sub_47a948();
    }
    if (ebx != arg_10) {
            sub_40f470();
            esp = esp - 0xc;
            eax = sub_42ea00(&var_8, edi, ebx, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24);
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
