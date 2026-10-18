// ComputePress @ 0x4401f0
// hopper name: sub_4401f0
// pybert name: ComputePress
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputePress() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_24 = ebx;
    decomp_var_28 = ebp;
    ebx = ecx;
    edx = 0x0;
    decomp_var_2c = esi;
    esp = esp - 0x30;
    var_30 = edi;
    if (*(ebx[0x2] + 0x2404) > 0x0) {
            esi = 0xb85768;
            do {
                    eax = 0x0;
                    *(edx * 0x4 + 0xb85710) = 0x0;
                    if (*(ebx[0x2] + 0x2400) > 0x0) {
                            ecx = esi;
                            do {
                                    *ecx = 0x0;
                                    eax = eax + 0x1;
                                    ecx = ecx + 0x4;
                            } while (eax < *(ebx[0x2] + 0x2400));
                    }
                    edx = edx + 0x1;
                    esi = esi + 0x400;
            } while (edx < *(ebx[0x2] + 0x2404));
    }
    eax = ebx[0x2];
    edi = *eax[0x915];
    esi = eax + 0x2450;
    var_18 = esi;
    var_14 = edi;
    goto loc_440280;

loc_440280:
    eax = ebx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (edi == ebp) goto .l10;
    goto loc_4402a3;

.l10:
    break;

loc_4402a3:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, var_30);
    esi = *eax[0x1];
    ebp = eax;
    var_1C = eax;
    var_10 = ebp;
    var_C = esi;
    &var_30 = &var_30;
    goto loc_4402f0;
    &decomp_var_20 = decomp_var_28;
    return eax;

loc_4402f0:
    var_4 = eax[0x1];
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (esi != var_4) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == ret_addr) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) {
                    sub_40f400();
                    esi = var_C;
                    ebp = var_10;
                    eax = var_1C;
                    continue;
            }
            if (esi == ret_addr) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
            if (HIBYTE(eax) == 0x41) {
                    if ((eax & 0xff) != 0x14) {
                            sub_40f400();
                            esi = var_C;
                            ebp = var_10;
                            eax = var_1C;
                            continue;
                    }
                    if (edi == var_18[0x1]) {
                            sub_47a948();
                    }
                    if (esi == ret_addr) {
                            sub_47a948();
                    }
                    if (*(((edi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb85768) == 0x0) {
                            if (edi == var_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x6];
                            *(eax * 0x4 + 0xb85710) = *(eax * 0x4 + 0xb85710) + 0x1;
                    }
                    if (edi == var_18[0x1]) {
                            sub_47a948();
                    }
                    if (esi == ret_addr) {
                            sub_47a948();
                    }
                    *(((edi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb85768) = 0x1;
                    sub_40f400();
                    esi = var_C;
                    ebp = var_10;
                    eax = var_1C;
                    continue;
            }
            if (edi == var_18[0x1]) {
                    sub_47a948();
            }
            if (esi == ret_addr) {
                    sub_47a948();
            }
            if (*(((edi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb85768) == 0x0) {
                    if (edi == var_18[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x6];
                    *(eax * 0x4 + 0xb85710) = *(eax * 0x4 + 0xb85710) + 0x1;
            }
            if (edi == var_18[0x1]) {
                    sub_47a948();
            }
            if (esi == ret_addr) {
                    sub_47a948();
            }
            *(((edi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb85768) = 0x1;
            sub_40f400();
            esi = var_C;
            ebp = var_10;
            eax = var_1C;
            continue;
    }
    break;
    sub_401390();
    edi = var_14;
    esi = var_18;
    continue;
}
