// sub_48fe22 @ 0x48fe22
// hopper name: sub_48fe22
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fe22() {
    esi = ecx;
    if (esi != 0x0) goto loc_48fe4e;
    goto loc_48fe30;

loc_48fe4e:
    esp = esp - 0x4;
    if (arg_0 > 0x0) goto loc_48fe72;
    goto .l2;

loc_48fe30:
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
    eax = 0x16;
    return eax;

loc_48fe72:
    ebx = 0x0;
    *(int8_t *)esi = 0x0;
    if (arg_0 > (arg_8 != 0x0 ? 0x1 : 0x0) + 0x1) goto loc_48fe8b;
    goto loc_48fe82;

.l2:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_14 = 0x16;
    *eax = decomp_var_14;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    eax = decomp_var_14;
    esp = esp + 0x4;
    return eax;

loc_48fe8b:
    if (arg_4 > 0x24) goto loc_48fe54;
    goto loc_48fe96;

loc_48fe82:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_14 = 0x22;
    *eax = decomp_var_14;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    eax = decomp_var_14;
    esp = esp + 0x4;
    return eax;

loc_48fe54:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_14 = 0x16;
    *eax = decomp_var_14;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    eax = decomp_var_14;
    esp = esp + 0x4;
    return eax;

loc_48fe96:
    var_4 = ebx;
    ecx = esi;
    if (arg_8 != ebx) {
            *(int8_t *)esi = 0x2d;
            ecx = esi + 0x1;
            var_4 = 0x1;
            eax = -eax;
    }
    edi = ecx;
    goto loc_48feb1;

loc_48feb1:
    temp_1 = eax % arg_4;
    eax = eax / arg_4;
    edx = temp_1;
    if (edx > 0x9) {
            edx = edx + 0x57;
    }
    else {
            edx = edx + 0x30;
    }
    *(int8_t *)ecx = edx;
    ecx = ecx + 0x1;
    var_4 = var_4 + 0x1;
    if (eax > 0x0 && var_4 < arg_0) {
            continue;
    }
    break;
    if (var_4 >= arg_0) {
            *(int8_t *)esi = 0x0;
            eax = sub_47d812();
            esp = esp - 0x4;
            decomp_var_14 = 0x22;
            *eax = decomp_var_14;
            sub_47a924();
            esp = (esp + 0x4 - 0x14) + 0x14;
            eax = decomp_var_14;
            esp = esp + 0x4;
    }
    else {
            *(int8_t *)ecx = 0x0;
            ecx = ecx - 0x1;
            do {
                    edx = *(int8_t *)edi;
                    eax = *(int8_t *)ecx;
                    *(int8_t *)ecx = edx;
                    ecx = ecx - 0x1;
                    *(int8_t *)edi = eax;
                    edi = edi + 0x1;
            } while (edi < ecx);
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;
}
