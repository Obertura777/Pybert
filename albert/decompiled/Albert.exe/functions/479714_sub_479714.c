// sub_479714 @ 0x479714
// hopper name: sub_479714
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479714() {
    esi = arg_8;
    esp = esp - 0x4;
    decomp_var_14 = edi;
    if (esi == 0x0) {
            sub_46dedc();
    }
    ebx = arg_c;
    if (ebx == 0x0) {
            sub_46dedc();
    }
    arg_8 = arg_8 & 0x0;
    edi = esi;
    if (*(int8_t *)esi != 0x0) {
            ecx = *(int8_t *)edi;
            if (ecx == 0x25) {
                    eax = edi[0x1];
                    if (eax >= 0x31) {
                            if (eax > 0x39) {
                                    if (eax >= 0x41) {
                                            if (eax <= 0x5a) {
                                                    if (eax > 0x39) {
                                                            eax = sign_extend_32(eax) - 0x38;
                                                    }
                                                    else {
                                                            eax = sign_extend_32(eax) - 0x31;
                                                    }
                                                    edi = edi + 0x2;
                                                    if (eax < arg_10) {
                                                            eax = *(ebx + eax * 0x4);
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    arg_8 = arg_8 + lstrlenA(eax);
                                                            }
                                                    }
                                                    else {
                                                            arg_8 = arg_8 + 0x1;
                                                    }
                                                    if (*(int8_t *)edi != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                            arg_8 = arg_8 + 0x1;
                                                            edi = edi + 0x1;
                                                    }
                                                    edi = edi + 0x1;
                                                    arg_8 = arg_8 + 0x1;
                                                    if (*(int8_t *)edi != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                    arg_8 = arg_8 + 0x1;
                                                    edi = edi + 0x1;
                                            }
                                            edi = edi + 0x1;
                                            arg_8 = arg_8 + 0x1;
                                            if (*(int8_t *)edi != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = sign_extend_32(eax) - 0x31;
                                    edi = edi + 0x2;
                                    if (eax < arg_10) {
                                            eax = *(ebx + eax * 0x4);
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    arg_8 = arg_8 + lstrlenA(eax);
                                            }
                                    }
                                    else {
                                            arg_8 = arg_8 + 0x1;
                                    }
                                    if (*(int8_t *)edi != 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (eax >= 0x41) {
                                    if (eax <= 0x5a) {
                                            if (eax > 0x39) {
                                                    eax = sign_extend_32(eax) - 0x38;
                                            }
                                            else {
                                                    eax = sign_extend_32(eax) - 0x31;
                                            }
                                            edi = edi + 0x2;
                                            if (eax < arg_10) {
                                                    eax = *(ebx + eax * 0x4);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            arg_8 = arg_8 + lstrlenA(eax);
                                                    }
                                            }
                                            else {
                                                    arg_8 = arg_8 + 0x1;
                                            }
                                            if (*(int8_t *)edi != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                    arg_8 = arg_8 + 0x1;
                                                    edi = edi + 0x1;
                                            }
                                            edi = edi + 0x1;
                                            arg_8 = arg_8 + 0x1;
                                            if (*(int8_t *)edi != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                            arg_8 = arg_8 + 0x1;
                                            edi = edi + 0x1;
                                    }
                                    edi = edi + 0x1;
                                    arg_8 = arg_8 + 0x1;
                                    if (*(int8_t *)edi != 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                            arg_8 = arg_8 + 0x1;
                            edi = edi + 0x1;
                    }
                    edi = edi + 0x1;
                    arg_8 = arg_8 + 0x1;
                    if (*(int8_t *)edi != 0x0) {
                            continue;
                    }
                    break;
            }
    }
    esp = esp - 0x4;
    ebx = esi;
    edi = sub_40b8d0(arg_8);
    if (*(int8_t *)esi != 0x0) {
            ecx = *(int8_t *)ebx;
            if (ecx == 0x25) {
                    eax = ebx[0x1];
                    if (eax >= 0x31) {
                            if (eax > 0x39) {
                                    if (eax >= 0x41) {
                                            if (eax <= 0x5a) {
                                                    if (eax > 0x39) {
                                                            eax = sign_extend_32(eax) - 0x38;
                                                    }
                                                    else {
                                                            eax = sign_extend_32(eax) - 0x31;
                                                    }
                                                    ebx = ebx + 0x2;
                                                    if (eax >= arg_10) {
                                                            *(int8_t *)edi = 0x3f;
                                                            edi = edi + 0x1;
                                                            arg_8 = arg_8 - 0x1;
                                                    }
                                                    else {
                                                            esi = arg_c + eax * 0x4;
                                                            eax = *esi;
                                                            if (eax != 0x0) {
                                                                    lstrlenA(eax);
                                                                    decomp_var_18 = *esi;
                                                                    sub_46e5ba(edi, arg_8 + 0x1, decomp_var_18);
                                                                    arg_8 = arg_8 - decomp_var_4;
                                                                    esp = (esp - 0x10) + 0xc;
                                                                    edi = edi + decomp_var_4;
                                                            }
                                                    }
                                                    if (*(int8_t *)ebx != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                            *(int8_t *)edi = *(int8_t *)ebx;
                                                            edi = edi + 0x1;
                                                            ebx = ebx + 0x1;
                                                            arg_8 = arg_8 - 0x1;
                                                    }
                                                    *(int8_t *)edi = *(int8_t *)ebx;
                                                    edi = edi + 0x1;
                                                    ebx = ebx + 0x1;
                                                    arg_8 = arg_8 - 0x1;
                                                    if (*(int8_t *)ebx != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                    *(int8_t *)edi = *(int8_t *)ebx;
                                                    edi = edi + 0x1;
                                                    ebx = ebx + 0x1;
                                                    arg_8 = arg_8 - 0x1;
                                            }
                                            *(int8_t *)edi = *(int8_t *)ebx;
                                            edi = edi + 0x1;
                                            ebx = ebx + 0x1;
                                            arg_8 = arg_8 - 0x1;
                                            if (*(int8_t *)ebx != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = sign_extend_32(eax) - 0x31;
                                    ebx = ebx + 0x2;
                                    if (eax >= arg_10) {
                                            *(int8_t *)edi = 0x3f;
                                            edi = edi + 0x1;
                                            arg_8 = arg_8 - 0x1;
                                    }
                                    else {
                                            esi = arg_c + eax * 0x4;
                                            eax = *esi;
                                            if (eax != 0x0) {
                                                    lstrlenA(eax);
                                                    decomp_var_18 = *esi;
                                                    sub_46e5ba(edi, arg_8 + 0x1, decomp_var_18);
                                                    arg_8 = arg_8 - decomp_var_4;
                                                    esp = (esp - 0x10) + 0xc;
                                                    edi = edi + decomp_var_4;
                                            }
                                    }
                                    if (*(int8_t *)ebx != 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (eax >= 0x41) {
                                    if (eax <= 0x5a) {
                                            if (eax > 0x39) {
                                                    eax = sign_extend_32(eax) - 0x38;
                                            }
                                            else {
                                                    eax = sign_extend_32(eax) - 0x31;
                                            }
                                            ebx = ebx + 0x2;
                                            if (eax >= arg_10) {
                                                    *(int8_t *)edi = 0x3f;
                                                    edi = edi + 0x1;
                                                    arg_8 = arg_8 - 0x1;
                                            }
                                            else {
                                                    esi = arg_c + eax * 0x4;
                                                    eax = *esi;
                                                    if (eax != 0x0) {
                                                            lstrlenA(eax);
                                                            decomp_var_18 = *esi;
                                                            sub_46e5ba(edi, arg_8 + 0x1, decomp_var_18);
                                                            arg_8 = arg_8 - decomp_var_4;
                                                            esp = (esp - 0x10) + 0xc;
                                                            edi = edi + decomp_var_4;
                                                    }
                                            }
                                            if (*(int8_t *)ebx != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                                    *(int8_t *)edi = *(int8_t *)ebx;
                                                    edi = edi + 0x1;
                                                    ebx = ebx + 0x1;
                                                    arg_8 = arg_8 - 0x1;
                                            }
                                            *(int8_t *)edi = *(int8_t *)ebx;
                                            edi = edi + 0x1;
                                            ebx = ebx + 0x1;
                                            arg_8 = arg_8 - 0x1;
                                            if (*(int8_t *)ebx != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                                            *(int8_t *)edi = *(int8_t *)ebx;
                                            edi = edi + 0x1;
                                            ebx = ebx + 0x1;
                                            arg_8 = arg_8 - 0x1;
                                    }
                                    *(int8_t *)edi = *(int8_t *)ebx;
                                    edi = edi + 0x1;
                                    ebx = ebx + 0x1;
                                    arg_8 = arg_8 - 0x1;
                                    if (*(int8_t *)ebx != 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_47f62e(sign_extend_32(ecx)) != 0x0) {
                            *(int8_t *)edi = *(int8_t *)ebx;
                            edi = edi + 0x1;
                            ebx = ebx + 0x1;
                            arg_8 = arg_8 - 0x1;
                    }
                    *(int8_t *)edi = *(int8_t *)ebx;
                    edi = edi + 0x1;
                    ebx = ebx + 0x1;
                    arg_8 = arg_8 - 0x1;
                    if (*(int8_t *)ebx != 0x0) {
                            continue;
                    }
                    break;
            }
    }
    sub_45ba50();
    return;
}
