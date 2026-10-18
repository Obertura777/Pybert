// sub_48fbb3 @ 0x48fbb3
// hopper name: sub_48fbb3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fbb3() {
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    if (arg_0 != 0x0) goto loc_48fbfa;
    goto loc_48fbcc;

loc_48fbfa:
    esp = esp - 0x4;
    decomp_var_18 = edi;
    edi = arg_4;
    if (edi != 0x0) goto loc_48fc2d;
    goto loc_48fc02;

loc_48fbcc:
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = (esp - 0x14) + 0x14;
    if (var_4 != 0x0) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    eax = 0x7fffffff;
    return eax;

loc_48fc2d:
    ebx = 0x0;
    if (var_10[0x5] != 0x0) goto loc_48fc42;
    goto loc_48fc35;

loc_48fc02:
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = (esp - 0x14) + 0x14;
    if (var_4 != 0x0) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    eax = 0x7fffffff;
    goto loc_48fc82;

loc_48fc42:
    esp = esp - 0x4;
    decomp_var_1c = esi;
    goto loc_48fc43;

loc_48fc35:
    eax = sub_48fb7e(arg_0, edi);
    esp = (esp - 0x8) + 0x8;
    goto loc_48fc76;

loc_48fc82:
    esp = esp + 0x4;
    return eax;

loc_48fc43:
    eax = *(int8_t *)arg_0 & 0xff;
    eax = sub_47c6a9(eax, &var_10);
    arg_0 = arg_0 + 0x1;
    esi = eax;
    eax = *(int8_t *)edi & 0xff;
    eax = sub_47c6a9(eax, &var_10);
    esp = (esp - 0x10) + 0x10;
    edi = edi + 0x1;
    if (esi != ebx && esi == eax) {
            continue;
    }
    break;

loc_48fc76:
    if (var_4 != ebx) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    goto loc_48fc82;
    eax = esi - eax;
    esp = esp + 0x4;
    goto loc_48fc76;
}
