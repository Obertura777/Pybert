// sub_482655 @ 0x482655
// hopper name: sub_482655
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482655() {
    ebp = &var_78;
    arg_6c = *dword_4c8db8 ^ ebp;
    eax = arg_78;
    decomp_var_a0 = ebx;
    decomp_var_a4 = esi;
    esi = edx;
    esp = esp - 0xa4;
    decomp_var_a8 = edi;
    decomp_var_24 = esi;
    if (eax != 0x0) {
            if (ecx != 0x0) {
                    sub_48235f();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = sub_47ad69();
    }
    else {
            decomp_var_1c = 0x1;
            decomp_var_18 = 0x0;
            if (ecx != 0x0) {
                    if (*(int8_t *)ecx == 0x4c) {
                            if (ecx[0x1] == 0x43) {
                                    if (ecx[0x2] == 0x5f) {
                                            edi = ecx;
                                            while (true) {
                                                    eax = sub_48c400(edi, 0x4b3b58);
                                                    ebx = eax;
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (ebx == 0x0) {
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                                    eax = eax - edi;
                                                    decomp_var_1c = eax;
                                                    if (eax == 0x0) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    if (*(int8_t *)ebx == 0x3b) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    decomp_var_20 = 0x1;
                                                    esi = dword_value_4930152;
                                                    while (true) {
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_48c337(*esi, edi, eax) != 0x0) {
                                                                    decomp_var_20 = decomp_var_20 + 0x1;
                                                                    esi = esi + 0xc;
                                                                    if (esi <= 0x4b3abc) {
                                                                            eax = decomp_var_1c;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            decomp_var_ac = *esi;
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (decomp_var_1c == sub_47d630(decomp_var_ac)) {
                                                                    break;
                                                            }
                                                            decomp_var_20 = decomp_var_20 + 0x1;
                                                            esi = esi + 0xc;
                                                            if (esi > 0x4b3abc) {
                                                                    break;
                                                            }
                                                            eax = decomp_var_1c;
                                                    }
                                                    ebx = ebx + 0x1;
                                                    edi = sub_47d320(ebx, 0x4b3790);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (edi == 0x0) {
                                                            if (*(int8_t *)ebx == 0x3b) {
                                                                    if (decomp_var_20 <= 0x5) {
                                                                            eax = sub_47f4a4(&decomp_var_14, 0x83, ebx, edi);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            if (eax != 0x0) {
                                                                                    decomp_var_b0 = 0x0;
                                                                                    sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            decomp_var_ac = decomp_var_20;
                                                                            *(int8_t *)(ebp + (edi - 0x14)) = 0x0;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_48235f() != 0x0) {
                                                                                    decomp_var_18 = decomp_var_18 + 0x1;
                                                                            }
                                                                    }
                                                                    edi = edi + ebx;
                                                                    if (*(int8_t *)edi != 0x0) {
                                                                            edi = edi + 0x1;
                                                                            if (*(int8_t *)edi != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_20 <= 0x5) {
                                                                    eax = sub_47f4a4(&decomp_var_14, 0x83, ebx, edi);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    if (eax != 0x0) {
                                                                            decomp_var_b0 = 0x0;
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    decomp_var_ac = decomp_var_20;
                                                                    *(int8_t *)(ebp + (edi - 0x14)) = 0x0;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_48235f() != 0x0) {
                                                                            decomp_var_18 = decomp_var_18 + 0x1;
                                                                    }
                                                            }
                                                            edi = edi + ebx;
                                                            if (*(int8_t *)edi != 0x0) {
                                                                    edi = edi + 0x1;
                                                                    if (*(int8_t *)edi != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (temp_0 != 0x0 && temp_0 != 0x1 && temp_0 == 0x2) {
                                                    if (decomp_var_18 != 0x0) {
                                                            sub_48201a();
                                                    }
                                            }
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            ebx = 0x0;
                                            decomp_var_ac = 0x0;
                                            decomp_var_b0 = 0x0;
                                            esp = (esp - 0x18) + 0x18;
                                            if (sub_48218b() != 0x0) {
                                                    edi = esi + 0x48;
                                                    do {
                                                            if (ebx != 0x0) {
                                                                    eax = sub_47fd80(&decomp_var_14, *edi);
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (eax != 0x0) {
                                                                            decomp_var_ac = ebx;
                                                                            eax = sub_48235f();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (eax == 0x0) {
                                                                                    decomp_var_1c = decomp_var_1c & eax;
                                                                            }
                                                                            else {
                                                                                    decomp_var_18 = decomp_var_18 + 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            decomp_var_18 = decomp_var_18 + 0x1;
                                                                    }
                                                            }
                                                            ebx = ebx + 0x1;
                                                            edi = edi + 0x10;
                                                    } while (ebx <= 0x5);
                                                    if (decomp_var_1c == 0x0) {
                                                            if (decomp_var_18 != 0x0) {
                                                                    sub_48201a();
                                                            }
                                                    }
                                                    else {
                                                            sub_48201a();
                                                    }
                                            }
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    ebx = 0x0;
                                    decomp_var_ac = 0x0;
                                    decomp_var_b0 = 0x0;
                                    esp = (esp - 0x18) + 0x18;
                                    if (sub_48218b() != 0x0) {
                                            edi = esi + 0x48;
                                            do {
                                                    if (ebx != 0x0) {
                                                            eax = sub_47fd80(&decomp_var_14, *edi);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax != 0x0) {
                                                                    decomp_var_ac = ebx;
                                                                    eax = sub_48235f();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax == 0x0) {
                                                                            decomp_var_1c = decomp_var_1c & eax;
                                                                    }
                                                                    else {
                                                                            decomp_var_18 = decomp_var_18 + 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    decomp_var_18 = decomp_var_18 + 0x1;
                                                            }
                                                    }
                                                    ebx = ebx + 0x1;
                                                    edi = edi + 0x10;
                                            } while (ebx <= 0x5);
                                            if (decomp_var_1c == 0x0) {
                                                    if (decomp_var_18 != 0x0) {
                                                            sub_48201a();
                                                    }
                                            }
                                            else {
                                                    sub_48201a();
                                            }
                                    }
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            ebx = 0x0;
                            decomp_var_ac = 0x0;
                            decomp_var_b0 = 0x0;
                            esp = (esp - 0x18) + 0x18;
                            if (sub_48218b() != 0x0) {
                                    edi = esi + 0x48;
                                    do {
                                            if (ebx != 0x0) {
                                                    eax = sub_47fd80(&decomp_var_14, *edi);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax != 0x0) {
                                                            decomp_var_ac = ebx;
                                                            eax = sub_48235f();
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax == 0x0) {
                                                                    decomp_var_1c = decomp_var_1c & eax;
                                                            }
                                                            else {
                                                                    decomp_var_18 = decomp_var_18 + 0x1;
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_18 = decomp_var_18 + 0x1;
                                                    }
                                            }
                                            ebx = ebx + 0x1;
                                            edi = edi + 0x10;
                                    } while (ebx <= 0x5);
                                    if (decomp_var_1c == 0x0) {
                                            if (decomp_var_18 != 0x0) {
                                                    sub_48201a();
                                            }
                                    }
                                    else {
                                            sub_48201a();
                                    }
                            }
                            eax = sub_47ad69();
                    }
            }
            else {
                    sub_48201a();
                    eax = sub_47ad69();
            }
    }
    return eax;
}
