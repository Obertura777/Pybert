// sub_48517e @ 0x48517e
// hopper name: sub_48517e
// referenced by: called,immediate
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48517e() {
    ebp = &var_1FC;
    arg_1f0 = *dword_4c8db8 ^ ebp;
    decomp_var_280 = ebx;
    ebx = arg_200;
    decomp_var_284 = esi;
    decomp_var_288 = edi;
    esp = esp - 0x288;
    decomp_var_30 = arg_1fc;
    decomp_var_2c = arg_208;
    sub_47aea2(arg_204);
    if (decomp_var_30 == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            if (decomp_var_58 != 0x0) {
                    eax = decomp_var_5c;
                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
            }
            eax = sub_47ad69();
    }
    else {
            eax = decomp_var_30;
            if ((eax[0xc] & 0x40) == 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_4867ae(eax) != 0xffffffff) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_4867ae(decomp_var_30) != 0xfffffffe) {
                                    esi = (SAR(sub_4867ae(decomp_var_30), 0x5)) * 0x4 + dword_bc7240;
                                    eax = sub_4867ae(decomp_var_30);
                                    eax = (eax & 0x1f) * 0x28 + *esi;
                                    esp = (esp - 0x8) + 0x8;
                            }
                            else {
                                    eax = 0x4c9958;
                            }
                    }
                    else {
                            eax = 0x4c9958;
                    }
                    if ((eax[0x24] & 0x7f) == 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_4867ae(decomp_var_30) != 0xffffffff) {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_4867ae(decomp_var_30) != 0xfffffffe) {
                                            esi = (SAR(sub_4867ae(decomp_var_30), 0x5)) * 0x4 + dword_bc7240;
                                            eax = sub_4867ae(decomp_var_30);
                                            eax = (eax & 0x1f) * 0x28 + *esi;
                                            esp = (esp - 0x8) + 0x8;
                                    }
                                    else {
                                            eax = 0x4c9958;
                                    }
                            }
                            else {
                                    eax = 0x4c9958;
                            }
                            if ((eax[0x24] & 0x80) == 0x0) {
                                    if (ebx != 0x0) {
                                            edx = *(int8_t *)ebx;
                                            ecx = 0x0;
                                            decomp_var_34 = 0x0;
                                            if (edx != 0x0) {
                                                    while (true) {
                                                            decomp_var_48 = ebx + 0x1;
                                                            if (decomp_var_34 < 0x0) {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            if (edx <= 0x78) {
                                                                    eax = *(int8_t *)(sign_extend_32(edx) + 0x4b7520) & 0xff;
                                                                    eax = eax & 0xf;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                            eax = sign_extend_32(*(int8_t *)(ecx + eax * 0x8 + 0x4b7540));
                                                            eax = SAR(eax, 0x4);
                                                            esp = (esp - 0x4) + 0x4;
                                                            decomp_var_74 = eax;
                                                            if (eax > 0x7) {
                                                                    ebx = decomp_var_48;
                                                                    eax = *(int8_t *)ebx;
                                                                    if (eax != 0x0) {
                                                                            ecx = decomp_var_74;
                                                                            edx = eax;
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            eax = (*(eax * 0x4 + 0x485af6))();
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    if (temp_0 != 0x0) {
                                                            if (decomp_var_58 != 0x0) {
                                                                    decomp_var_5c[0x1c] = decomp_var_5c[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (decomp_var_58 != 0x0) {
                                                            decomp_var_5c[0x1c] = decomp_var_5c[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            *sub_47d812() = 0x16;
                                            eax = sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            if (decomp_var_58 != 0x0) {
                                                    eax = decomp_var_5c;
                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                            }
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    *sub_47d812() = 0x16;
                                    eax = sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    if (decomp_var_58 != 0x0) {
                                            eax = decomp_var_5c;
                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                    }
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            if (decomp_var_58 != 0x0) {
                                    eax = decomp_var_5c;
                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                            }
                            eax = sub_47ad69();
                    }
            }
            else {
                    if (ebx != 0x0) {
                            edx = *(int8_t *)ebx;
                            ecx = 0x0;
                            decomp_var_34 = 0x0;
                            if (edx != 0x0) {
                                    while (true) {
                                            decomp_var_48 = ebx + 0x1;
                                            if (decomp_var_34 < 0x0) {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            if (edx <= 0x78) {
                                                    eax = *(int8_t *)(sign_extend_32(edx) + 0x4b7520) & 0xff;
                                                    eax = eax & 0xf;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                            eax = sign_extend_32(*(int8_t *)(ecx + eax * 0x8 + 0x4b7540));
                                            eax = SAR(eax, 0x4);
                                            esp = (esp - 0x4) + 0x4;
                                            decomp_var_74 = eax;
                                            if (eax > 0x7) {
                                                    ebx = decomp_var_48;
                                                    eax = *(int8_t *)ebx;
                                                    if (eax != 0x0) {
                                                            ecx = decomp_var_74;
                                                            edx = eax;
                                                            continue;
                                                    }
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                            eax = (*(eax * 0x4 + 0x485af6))();
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
                                            if (decomp_var_58 != 0x0) {
                                                    decomp_var_5c[0x1c] = decomp_var_5c[0x1c] & 0xfffffffd;
                                            }
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (decomp_var_58 != 0x0) {
                                            decomp_var_5c[0x1c] = decomp_var_5c[0x1c] & 0xfffffffd;
                                    }
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            if (decomp_var_58 != 0x0) {
                                    eax = decomp_var_5c;
                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                            }
                            eax = sub_47ad69();
                    }
            }
    }
    return eax;
}
