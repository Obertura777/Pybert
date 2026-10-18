// sub_492370 @ 0x492370
// hopper name: sub_492370
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492370() {
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    var_10 = 0x0;
    var_C = 0x0;
    eax = sub_48df70(arg_0, 0x0, 0x0, 0x1);
    var_18 = eax;
    esp = (esp - 0x1c) + 0x10;
    var_14 = edx;
    if ((eax & edx) == 0xffffffff) goto .l3;
    goto loc_49239d;

.l3:
    eax = sub_47d812();
    eax = *eax;
    return eax;

loc_49239d:
    eax = sub_48df70(arg_0, 0x0, 0x0, 0x2);
    esp = (esp - 0x10) + 0x10;
    if ((eax & edx) == 0xffffffff) goto .l7;
    goto loc_4923b5;

.l7:
    eax = sub_47d812();
    eax = *eax;
    return eax;

loc_4923b5:
    esi = arg_4 - eax;
    edi = arg_8 - edx + CARRY(EFLAGS(cf));
    bool_30 = edi > 0x0;
    if (edi < 0x0) goto loc_49248b;
    goto loc_4923c5;

loc_49248b:
    bool_10 = edi < 0x0;
    if (edi <= 0x0) {
            if (!bool_10) {
                    ebx = 0x0;
                    if (esi < 0x0) {
                            esp = (esp - 0x10) + 0x10;
                            if ((sub_48df70(arg_0, arg_4, arg_8, ebx) & edx) != 0xffffffff) {
                                    eax = sub_48e43c(arg_0);
                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                    eax = SetEndOfFile(eax);
                                    edx = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & 0x80000000 ? 0xffffffff : 0x0;
                                    var_10 = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1;
                                    var_C = edx;
                                    if ((-(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & edx) == 0xffffffff) {
                                            *sub_47d812() = 0xd;
                                            *sub_47d825() = GetLastError();
                                            esi = var_10;
                                            if ((esi & var_C) != 0xffffffff) {
                                                    esp = (esp - 0x10) + 0x10;
                                                    if ((sub_48df70(arg_0, var_18, var_14, ebx) & edx) != 0xffffffff) {
                                                            eax = 0x0;
                                                    }
                                                    else {
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                    }
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x10) + 0x10;
                                            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                            }
                            else {
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
                    else {
                            esp = (esp - 0x10) + 0x10;
                            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    esp = (esp - 0x10) + 0x10;
                    if ((sub_48df70(arg_0, arg_4, arg_8, 0x0) & edx) != 0xffffffff) {
                            eax = sub_48e43c(arg_0);
                            esp = (esp - 0x4) + 0x4 - 0x4;
                            eax = SetEndOfFile(eax);
                            edx = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & 0x80000000 ? 0xffffffff : 0x0;
                            var_10 = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1;
                            var_C = edx;
                            if ((-(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & edx) == 0xffffffff) {
                                    *sub_47d812() = 0xd;
                                    *sub_47d825() = GetLastError();
                                    esi = var_10;
                                    if ((esi & var_C) != 0xffffffff) {
                                            esp = (esp - 0x10) + 0x10;
                                            if ((sub_48df70(arg_0, var_18, var_14, ebx) & edx) != 0xffffffff) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                                    else {
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                            }
                            else {
                                    esp = (esp - 0x10) + 0x10;
                                    if ((sub_48df70(arg_0, var_18, var_14, ebx) & edx) != 0xffffffff) {
                                            eax = 0x0;
                                    }
                                    else {
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                            }
                    }
                    else {
                            eax = sub_47d812();
                            eax = *eax;
                    }
            }
    }
    else {
            esp = (esp - 0x10) + 0x10;
            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                    eax = 0x0;
            }
            else {
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    return eax;

loc_4923c5:
    if (bool_30) goto .l2;
    goto loc_4923c7;

.l2:
    decomp_var_28 = 0x1000;
    decomp_var_2c = 0x8;
    eax = GetProcessHeap();
    esp = esp - 0xc;
    eax = HeapAlloc(eax, decomp_var_24, decomp_var_20);
    var_4 = eax;
    if (eax != 0x0) goto .l5;
    goto loc_4923eb;

loc_4923c7:
    if (esi <= 0x0) goto .l4;
    goto loc_4923cf;

.l5:
    esp = (esp - 0x8) + 0x8;
    var_8 = sub_492c14(arg_0, 0x8000);
    goto loc_492414;

loc_4923eb:
    *sub_47d812() = 0xc;
    eax = sub_47d812();
    eax = *eax;
    return eax;

.l4:
    bool_32 = edi < 0x0;
    if (edi <= 0x0) {
            if (!bool_32) {
                    if (esi < 0x0) {
                            esp = (esp - 0x10) + 0x10;
                            if ((sub_48df70(arg_0, arg_4, arg_8, 0x0) & edx) != 0xffffffff) {
                                    eax = sub_48e43c(arg_0);
                                    esp = (esp - 0x4) + 0x4 - 0x4;
                                    eax = SetEndOfFile(eax);
                                    edx = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & 0x80000000 ? 0xffffffff : 0x0;
                                    var_10 = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1;
                                    var_C = edx;
                                    if ((-(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & edx) == 0xffffffff) {
                                            *sub_47d812() = 0xd;
                                            *sub_47d825() = GetLastError();
                                            esi = var_10;
                                            if ((esi & var_C) != 0xffffffff) {
                                                    esp = (esp - 0x10) + 0x10;
                                                    if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                                            eax = 0x0;
                                                    }
                                                    else {
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                    }
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x10) + 0x10;
                                            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                            }
                            else {
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
                    else {
                            esp = (esp - 0x10) + 0x10;
                            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
            }
            else {
                    esp = (esp - 0x10) + 0x10;
                    if ((sub_48df70(arg_0, arg_4, arg_8, 0x0) & edx) != 0xffffffff) {
                            eax = sub_48e43c(arg_0);
                            esp = (esp - 0x4) + 0x4 - 0x4;
                            eax = SetEndOfFile(eax);
                            edx = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & 0x80000000 ? 0xffffffff : 0x0;
                            var_10 = -(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1;
                            var_C = edx;
                            if ((-(-eax - -eax + CARRY(EFLAGS(cf))) - 0x1 & edx) == 0xffffffff) {
                                    *sub_47d812() = 0xd;
                                    *sub_47d825() = GetLastError();
                                    esi = var_10;
                                    if ((esi & var_C) != 0xffffffff) {
                                            esp = (esp - 0x10) + 0x10;
                                            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                                    else {
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                            }
                            else {
                                    esp = (esp - 0x10) + 0x10;
                                    if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                                            eax = 0x0;
                                    }
                                    else {
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                            }
                    }
                    else {
                            eax = sub_47d812();
                            eax = *eax;
                    }
            }
    }
    else {
            esp = (esp - 0x10) + 0x10;
            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                    eax = 0x0;
            }
            else {
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    return eax;

loc_4923cf:
    decomp_var_28 = 0x1000;
    decomp_var_2c = 0x8;
    eax = GetProcessHeap();
    esp = esp - 0xc;
    eax = HeapAlloc(eax, decomp_var_24, decomp_var_20);
    var_4 = eax;
    if (eax != 0x0) goto loc_492402;
    goto .l6;

loc_492414:
    bool_54 = edi > 0x0;
    if (edi >= 0x0 && (bool_54 || esi >= 0x1000)) {
            eax = 0x1000;
    }
    else {
            eax = esi;
    }
    decomp_var_28 = eax;
    decomp_var_2c = var_4;
    eax = sub_48730d();
    esp = (esp - 0xc) + 0xc;
    if (eax != 0xffffffff) {
            edx = eax & 0x80000000 ? 0xffffffff : 0x0;
            esi = esi - eax;
            edi = edi - edx + CARRY(EFLAGS(cf));
            bool_49 = edi > 0x0;
            if (edi >= 0x0) {
                    if (bool_49) {
                            continue;
                    }
                    if (esi > 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            else {
                    temp_0 = 0x0;
                    break;
            }
    }
    else {
            if (*sub_47d825() == 0x5) {
                    *sub_47d812() = 0xd;
                    temp_0 = 0x1;
            }
            else {
                    temp_0 = 0x1;
            }
            break;
    }
    goto .l8;

loc_492402:
    esp = (esp - 0x8) + 0x8;
    var_8 = sub_492c14(arg_0, 0x8000);
    goto .l9;

.l6:
    *sub_47d812() = 0xc;
    eax = sub_47d812();
    eax = *eax;
    return eax;

.l8:
    if (temp_0 != 0x0) {
            esi = esi | 0xffffffff;
            var_C = esi;
    }
    else {
            esi = var_10;
    }
    sub_492c14(arg_0, var_8);
    esp = (esp - 0x8) + 0x8 - 0xc;
    HeapFree(GetProcessHeap(), decomp_var_2c, decomp_var_28);
    if ((esi & var_C) != 0xffffffff) {
            esp = (esp - 0x10) + 0x10;
            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                    eax = 0x0;
            }
            else {
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    else {
            eax = sub_47d812();
            eax = *eax;
    }
    return eax;

.l9:
    bool_63 = edi > 0x0;
    if (edi >= 0x0 && (bool_63 || esi >= 0x1000)) {
            eax = 0x1000;
    }
    else {
            eax = esi;
    }
    decomp_var_28 = eax;
    decomp_var_2c = var_4;
    eax = sub_48730d();
    esp = (esp - 0xc) + 0xc;
    if (eax != 0xffffffff) {
            edx = eax & 0x80000000 ? 0xffffffff : 0x0;
            esi = esi - eax;
            edi = edi - edx + CARRY(EFLAGS(cf));
            bool_60 = edi > 0x0;
            if (edi >= 0x0) {
                    if (bool_60) {
                            continue;
                    }
                    if (esi > 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            else {
                    temp_0 = 0x0;
                    break;
            }
    }
    else {
            if (*sub_47d825() == 0x5) {
                    *sub_47d812() = 0xd;
                    temp_0 = 0x1;
            }
            else {
                    temp_0 = 0x1;
            }
            break;
    }
    goto .l10;

.l10:
    if (temp_0 != 0x0) {
            esi = esi | 0xffffffff;
            var_C = esi;
    }
    else {
            esi = var_10;
    }
    sub_492c14(arg_0, var_8);
    esp = (esp - 0x8) + 0x8 - 0xc;
    HeapFree(GetProcessHeap(), decomp_var_2c, decomp_var_28);
    if ((esi & var_C) != 0xffffffff) {
            esp = (esp - 0x10) + 0x10;
            if ((sub_48df70(arg_0, var_18, var_14, 0x0) & edx) != 0xffffffff) {
                    eax = 0x0;
            }
            else {
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    else {
            eax = sub_47d812();
            eax = *eax;
    }
    return eax;
}
