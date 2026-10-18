// SetOwnPower @ 0x460de0
// hopper name: sub_460de0
// pybert name: SetOwnPower
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

SetOwnPower() {
    decomp_var_28 = ebx;
    ebx = arg_0;
    decomp_var_2c = ebp;
    decomp_var_30 = edi;
    edi = ecx;
    edi[0x1212] = ebx;
    ebp = edi + 0x243c;
    esp = esp - 0x34;
    sub_401950(*(edi[0x910] + 0x4));
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    eax = arg_0;
    eax[0x2] = eax;
    if (HIBYTE(ebx) != 0x41) goto loc_460ea1;
    goto loc_460e28;

loc_460ea1:
    edi[0x2448] = 0x1;
    return eax;

loc_460e28:
    edx = ebx & 0xff;
    ebx = 0x0;
    var_24 = edx;
    arg_0 = 0x0;
    if (edi[0x900] <= 0x0) goto loc_460ea1;
    goto loc_460e3d;

loc_460e3d:
    esp = esp - 0x4;
    decomp_var_34 = esi;
    goto loc_460e40;

loc_460e40:
    esi = edi + (ebx + ebx * 0x8) * 0x4 + 0x14;
    var_18 = *(edi + (ebx + ebx * 0x8) * 0x4 + 0x18);
    esp = esp - 0x8;
    eax = sub_401ff0(&var_14, &var_24, decomp_var_34, decomp_var_30, decomp_var_2c);
    ecx = *eax;
    var_20 = eax;
    if (ecx == 0x0 || ecx != esi) {
            sub_47a948();
            eax = var_20;
    }
    if (eax[0x1] != var_18) {
            esp = esp - 0x8;
            eax = sub_404ce0(&var_C, &arg_0, decomp_var_34);
    }
    ebx = ebx + 0x1;
    arg_0 = ebx;
    if (ebx < edi[0x900]) {
            continue;
    }
    break;
    esp = esp + 0x4;
    goto loc_460ea1;
}
