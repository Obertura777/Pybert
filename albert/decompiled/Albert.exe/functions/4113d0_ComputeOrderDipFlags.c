// ComputeOrderDipFlags @ 0x4113d0
// hopper name: sub_4113d0
// pybert name: ComputeOrderDipFlags
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputeOrderDipFlags() {
    &saved_fp = &saved_fp & 0xfffffff8;
    eax = ecx[0x2];
    edx = *dword_bb6f20;
    decomp_var_24 = ebx;
    var_20 = ecx;
    ecx = eax[0x2424] & 0xff;
    eax = *edx;
    decomp_var_28 = ebp;
    decomp_var_2c = esi;
    var_1C = ecx;
    esp = esp - 0x30;
    decomp_var_30 = edi;
    edi = 0xbb6f1c;
    ebx = eax;
    var_10 = 0xbb6f1c;
    var_C = ebx;
    goto loc_411410;

loc_411410:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            eax = sub_47a948();
    }
    if (ebx == *dword_bb6f20) goto .l27;
    goto loc_41142f;

.l27:
    break;

loc_41142f:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    bool_20 = ebx != edi[0x1];
    ebp = ebx[0x6];
    if (!bool_20) {
            sub_47a948();
    }
    bool_16 = ebx != edi[0x1];
    esi = ebx[0x5];
    var_18 = esi;
    if (!bool_16) {
            sub_47a948();
    }
    ebx[0x1c] = 0x1;
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    ebx[0x1d] = 0x1;
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    ebx[0x1e] = 0x0;
    eax = *(ebp * 0x4 + 0xba2f70);
    if (eax == esi) {
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            ebx[0x1c] = 0x0;
    }
    else {
            if (eax == var_1C) {
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx[0x1d] = 0x0;
            }
    }
    ecx = var_20[0x2];
    esi = ebp + ebp * 0x8 + ebp + ebp * 0x8 + ebp + ebp * 0x8 + ebp + ebp * 0x8;
    eax = esi + ecx;
    if (*(int8_t *)(esi + ecx + 0x3) != 0x0) {
            eax = eax[0x10];
            if (HIBYTE(eax) == 0x41) {
                    eax = eax & 0xff;
                    if (eax != 0x14) {
                            if (eax == var_1C) {
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx[0x1c] = 0x0;
                            }
                            else {
                                    if (eax == var_18) {
                                            if (ebx == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            ebx[0x1d] = 0x0;
                                    }
                            }
                    }
            }
    }
    eax = var_20[0x2];
    eax = eax + esi;
    if (eax[0x3] != 0x0) {
            eax = eax[0x10];
            if (HIBYTE(eax) == 0x41) {
                    esi = eax & 0xff;
                    if (esi != 0x14) {
                            if (*(esi * 0x8 + 0x4cf568) == 0x1) {
                                    if (*(esi * 0x8 + 0x4cf56c) != 0x0) {
                                            eax = var_1C;
                                            if (esi != eax) {
                                                    if ((*((eax * 0x15 + esi) * 0x8 + 0x4d5528) | *((eax * 0x15 + esi) * 0x8 + 0x4d552c)) == 0x0) {
                                                            if (ebx == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            ebx[0x1d] = 0x0;
                                                    }
                                            }
                                            else {
                                                    if (ebx == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    ebx[0x1d] = 0x0;
                                            }
                                    }
                                    else {
                                            if (ebx == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            ebx[0x1d] = 0x0;
                                    }
                            }
                            else {
                                    eax = var_1C;
                                    if (esi != eax) {
                                            if ((*((eax * 0x15 + esi) * 0x8 + 0x4d5528) | *((eax * 0x15 + esi) * 0x8 + 0x4d552c)) == 0x0) {
                                                    if (ebx == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    ebx[0x1d] = 0x0;
                                            }
                                    }
                                    else {
                                            if (ebx == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            ebx[0x1d] = 0x0;
                                    }
                            }
                    }
                    else {
                            if (ebx == edi[0x1]) {
                                    sub_47a948();
                            }
                            ebx[0x1d] = 0x0;
                    }
            }
            else {
                    esi = 0x14;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx[0x1d] = 0x0;
            }
            eax = var_18;
            if (esi != eax) {
                    if (esi != 0x14) {
                            if ((*((eax * 0x15 + esi) * 0x8 + 0x4d5528) | *((eax * 0x15 + esi) * 0x8 + 0x4d552c)) == 0x0) {
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx[0x1e] = 0x1;
                            }
                    }
                    else {
                            if (ebx == edi[0x1]) {
                                    sub_47a948();
                            }
                            ebx[0x1e] = 0x1;
                    }
            }
    }
    esi = **(var_20 + (ebp + ebp * 0x2) * 0x4 + 0x2a20);
    edi = var_20 + (ebp + ebp * 0x2) * 0x4 + 0x2a1c;
    var_14 = edi;
    var_8 = edi;
    var_4 = esi;
    goto loc_4115c0;
    &var_20 = decomp_var_28;
    return eax;

loc_4115c0:
    eax = var_14;
    ebp = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(var_20[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) {
                    sub_401520();
                    esi = var_4;
                    edi = var_8;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = *(int16_t *)(var_20[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
            esi = eax & 0xff;
            if (HIBYTE(eax) != 0x41) {
                    esi = 0x14;
            }
            if (*(esi * 0x8 + 0x4cf568) == 0x1 && *(esi * 0x8 + 0x4cf56c) == 0x0) {
                    if (ebx == var_10[0x1]) {
                            sub_47a948();
                    }
                    ebx[0x1d] = 0x0;
            }
            if (*(int8_t *)byte_baed68 == 0x1) {
                    if (esi == var_18) {
                            sub_401520();
                            esi = var_4;
                            edi = var_8;
                            continue;
                    }
                    eax = var_1C;
                    if (esi != eax && esi != 0x14) {
                            eax = eax * 0x15 + esi;
                            bool_73 = *(eax * 0x8 + 0x4d552c) > 0x0;
                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                    if (!bool_73) {
                                            if (*(eax * 0x8 + 0x4d5528) > 0x1) {
                                                    bool_69 = *(esi * 0x8 + 0x4d5484) < 0x0;
                                                    if (*(esi * 0x8 + 0x4d5484) <= 0x0) {
                                                            if (!bool_69) {
                                                                    if (*(esi * 0x8 + 0x4d5480) <= 0x1) {
                                                                            if (ebx == var_10[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            ebx[0x1d] = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    if (ebx == var_10[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    ebx[0x1d] = 0x0;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (ebx == var_10[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    ebx[0x1d] = 0x0;
                                            }
                                    }
                                    else {
                                            bool_80 = *(esi * 0x8 + 0x4d5484) < 0x0;
                                            if (*(esi * 0x8 + 0x4d5484) <= 0x0) {
                                                    if (!bool_80) {
                                                            if (*(esi * 0x8 + 0x4d5480) <= 0x1) {
                                                                    if (ebx == var_10[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    ebx[0x1d] = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            if (ebx == var_10[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            ebx[0x1d] = 0x0;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (ebx == var_10[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx[0x1d] = 0x0;
                            }
                    }
                    eax = var_18;
                    if (esi == eax) {
                            sub_401520();
                            esi = var_4;
                            edi = var_8;
                            continue;
                    }
                    if (esi == var_1C) {
                            sub_401520();
                            esi = var_4;
                            edi = var_8;
                            continue;
                    }
                    if (esi == 0x14) {
                            sub_401520();
                            esi = var_4;
                            edi = var_8;
                            continue;
                    }
                    if ((*((eax * 0x15 + esi) * 0x8 + 0x4d5528) | *((eax * 0x15 + esi) * 0x8 + 0x4d552c)) == 0x0) {
                            if (ebx == var_10[0x1]) {
                                    sub_47a948();
                            }
                            ebx[0x1e] = 0x1;
                    }
                    sub_401520();
                    esi = var_4;
                    edi = var_8;
                    continue;
            }
            eax = var_18;
            if (esi != eax && esi != var_1C) {
                    if (esi != 0x14 && (*((eax * 0x15 + esi) * 0x8 + 0x4d5528) | *((eax * 0x15 + esi) * 0x8 + 0x4d552c)) == 0x0) {
                            if (ebx == var_10[0x1]) {
                                    sub_47a948();
                            }
                            ebx[0x1e] = 0x1;
                    }
            }
            sub_401520();
            esi = var_4;
            edi = var_8;
            continue;
    }
    break;
    eax = sub_40f6f0();
    ebx = var_C;
    edi = var_10;
    continue;
}
