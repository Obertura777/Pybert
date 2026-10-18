// ComputeBuildDelta @ 0x40ab10
// hopper name: sub_40ab10
// pybert name: ComputeBuildDelta
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputeBuildDelta() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_81c = ebx;
    decomp_var_820 = ebp;
    decomp_var_824 = esi;
    esp = esp - 0x828;
    decomp_var_828 = edi;
    ebp = ecx;
    eax = arg_23FC;
    bool_2 = true;
    bool_1 = true;
    var_80C = ebp;
    var_815 = 0x0;
    if (eax > 0x0) {
            eax = 0x0;
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
    }
    esi = *arg_244C;
    ebx = &arg_2448;
    edi = ebx;
    var_814 = edi;
    var_810 = esi;
    goto loc_40ab70;

loc_40ab70:
    var_804 = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != var_804) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = esi[0x18] & 0xff;
            eax = esi[0x4];
            *(int16_t *)(ebp + (eax + eax * 0x8) * 0x4 + 0x20) = edx | 0x4100;
            eax = esi[0x6];
            *(&decomp_var_828 + eax * 0x4 + 0x428) = *(&decomp_var_828 + eax * 0x4 + 0x428) + 0x1;
            sub_401390();
            esi = var_810;
            edi = var_814;
            continue;
    }
    break;
    ecx = arg_23F8;
    if (ecx > 0x0) {
            eax = &arg_18;
            edx = ecx;
            do {
                    if (*(int8_t *)(eax - 0x1d) != 0x0 && *(int16_t *)word_4c61a0 != *(int16_t *)eax) {
                            ecx = *(int8_t *)eax & 0xff;
                            *(&decomp_var_828 + ecx * 0x4 + 0x28) = *(&decomp_var_828 + ecx * 0x4 + 0x28) + 0x1;
                    }
                    eax = eax + 0x24;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    ebx = 0x0;
    var_814 = 0x0;
    if (arg_23FC <= 0x0) {
            eax = 0x0;
            &decomp_var_818 = decomp_var_820;
    }
    else {
            do {
                    esp = esp - 0x4;
                    eax = sub_409de0(&var_814, decomp_var_828);
                    ecx = *(&decomp_var_828 + ebx * 0x4 + 0x428);
                    esi = eax;
                    eax = *(&decomp_var_828 + ebx * 0x4 + 0x28);
                    if (eax > ecx) {
                            esi[0x14] = 0x1;
                            edx = eax - ecx;
                    }
                    else {
                            esi[0x14] = 0x0;
                            edx = ecx - eax;
                    }
                    esi[0x4] = edx;
                    if (eax != ecx) {
                            var_815 = 0x1;
                    }
                    eax = esi[0x1];
                    esi[0x3] = 0x0;
                    ebp = eax[0x1];
                    edi = ebp;
                    if (arg_11 == 0x0) {
                            do {
                                    sub_40fb70(edi[0x2]);
                                    edi = *edi;
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x4;
                                    ebp = edi;
                            } while (edi[0x19] == 0x0);
                    }
                    eax = esi[0x1];
                    edx = var_80C;
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    ebx = ebx + 0x1;
                    esi[0x2] = esi;
                    var_814 = ebx;
            } while (ebx < edx[0x901]);
            eax = var_815;
            &decomp_var_818 = decomp_var_820;
    }
    return eax;
}
