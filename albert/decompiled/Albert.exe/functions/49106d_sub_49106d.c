// sub_49106d @ 0x49106d
// hopper name: sub_49106d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49106d() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_78 = ebx;
    ebx = arg_14;
    decomp_var_7c = esi;
    esp = esp - 0xc;
    decomp_var_80 = edi;
    var_10 = arg_0;
    var_10 = arg_0;
    asm { movsw      word [edi], word [esi] };
    ecx = var_8 & 0x8000;
    edx = var_8 & 0x7fff;
    var_60 = ebx;
    var_30 = 0xcc;
    var_2C = 0xcc;
    var_28 = 0xcc;
    var_26 = 0xfb;
    var_74 = 0x1;
    var_6C = ecx;
    if (ecx != 0x0) {
            ebx[0x2] = 0x2d;
    }
    else {
            ebx[0x2] = 0x20;
    }
    esi = var_C;
    edi = var_10;
    if (edx != 0x0 || esi != 0x0) goto .l3;
    goto loc_4910fa;

.l3:
    if (edx != 0x7fff) goto loc_4911cd;
    goto loc_49112f;

loc_4910fa:
    if (edi != 0x0) goto loc_491124;
    goto loc_4910fe;

loc_4911cd:
    var_4C = SAR((((edx & 0xffff) >> 0x8) + (esi >> 0x18) * 0x2) * 0x4d + ((edx & 0xffff) * 0x4d10 - 0x134312f4), 0x10) & 0xffff;
    ebx = -sign_extend_32(SAR((((edx & 0xffff) >> 0x8) + (esi >> 0x18) * 0x2) * 0x4d + ((edx & 0xffff) * 0x4d10 - 0x134312f4), 0x10) & 0xffff);
    bool_5 = ebx >= 0x0;
    var_16 = edx;
    var_20 = 0x0;
    var_68 = 0x4ca160;
    if (ebx == 0x0) goto loc_4914cc;
    goto loc_49121e;

loc_49112f:
    *(int16_t *)ebx = 0x1;
    if (esi == 0x80000000) {
            if (edi != 0x0) {
                    if ((esi & 0x40000000) == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_84 = "1#SNAN";
                            esp = (esp - 0x8) + 0xc;
                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            ebx[0x3] = 0x6;
                            eax = sub_47ad69();
                    }
                    else {
                            if (ecx != 0x0) {
                                    if (esi == 0xc0000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#IND";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            if (esi == 0x80000000) {
                                                    if (edi == 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_84 = "1#INF";
                                                            esp = (esp - 0x8) + 0xc;
                                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            ebx[0x3] = 0x5;
                                                            eax = sub_47ad69();
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_84 = "1#QNAN";
                                                            esp = (esp - 0x8) + 0xc;
                                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            ebx[0x3] = 0x6;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
            }
            else {
                    if (ecx != 0x0) {
                            if (esi == 0xc0000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#IND";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
                    else {
                            if (esi == 0x80000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#INF";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_84 = "1#QNAN";
                                    esp = (esp - 0x8) + 0xc;
                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    ebx[0x3] = 0x6;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    else {
            if ((esi & 0x40000000) == 0x0) {
                    esp = esp - 0x4;
                    decomp_var_84 = "1#SNAN";
                    esp = (esp - 0x8) + 0xc;
                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                            sub_47a828();
                            esp = (esp - 0x14) + 0x14;
                    }
                    ebx[0x3] = 0x6;
                    eax = sub_47ad69();
            }
            else {
                    if (ecx != 0x0) {
                            if (esi == 0xc0000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#IND";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
                    else {
                            if (esi == 0x80000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#INF";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_84 = "1#QNAN";
                                    esp = (esp - 0x8) + 0xc;
                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    ebx[0x3] = 0x6;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    return eax;

loc_491124:
    if (edx != 0x7fff) goto .l8;
    goto .l4;

loc_4910fe:
    *(int16_t *)ebx = *(int16_t *)ebx & edi;
    ebx[0x2] = ((ecx != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
    ebx[0x3] = 0x1;
    ebx[0x4] = 0x30;
    ebx[0x5] = 0x0;
    eax = sub_47ad69();
    return eax;

loc_4914cc:
    ecx = var_18 >> 0x10;
    if (ecx < 0x3fff) goto loc_49172c;
    goto loc_4914e2;

loc_49121e:
    if (!bool_5) {
            ebx = -ebx;
            var_68 = 0x4ca2c0;
    }
    if (ebx == 0x0) goto loc_4914cc;
    goto .l180;

.l8:
    var_4C = SAR((((edx & 0xffff) >> 0x8) + (esi >> 0x18) * 0x2) * 0x4d + ((edx & 0xffff) * 0x4d10 - 0x134312f4), 0x10) & 0xffff;
    ebx = -sign_extend_32(SAR((((edx & 0xffff) >> 0x8) + (esi >> 0x18) * 0x2) * 0x4d + ((edx & 0xffff) * 0x4d10 - 0x134312f4), 0x10) & 0xffff);
    bool_155 = ebx >= 0x0;
    var_16 = edx;
    var_20 = 0x0;
    var_68 = 0x4ca160;
    if (ebx == 0x0) goto .l2;
    goto .l9;

.l4:
    *(int16_t *)ebx = 0x1;
    if (esi == 0x80000000) {
            if (edi != 0x0) {
                    if ((esi & 0x40000000) == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_84 = "1#SNAN";
                            esp = (esp - 0x8) + 0xc;
                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            ebx[0x3] = 0x6;
                            eax = sub_47ad69();
                    }
                    else {
                            if (ecx != 0x0) {
                                    if (esi == 0xc0000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#IND";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            if (esi == 0x80000000) {
                                                    if (edi == 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_84 = "1#INF";
                                                            esp = (esp - 0x8) + 0xc;
                                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            ebx[0x3] = 0x5;
                                                            eax = sub_47ad69();
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_84 = "1#QNAN";
                                                            esp = (esp - 0x8) + 0xc;
                                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            ebx[0x3] = 0x6;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
            }
            else {
                    if (ecx != 0x0) {
                            if (esi == 0xc0000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#IND";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
                    else {
                            if (esi == 0x80000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#INF";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_84 = "1#QNAN";
                                    esp = (esp - 0x8) + 0xc;
                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    ebx[0x3] = 0x6;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    else {
            if ((esi & 0x40000000) == 0x0) {
                    esp = esp - 0x4;
                    decomp_var_84 = "1#SNAN";
                    esp = (esp - 0x8) + 0xc;
                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                            sub_47a828();
                            esp = (esp - 0x14) + 0x14;
                    }
                    ebx[0x3] = 0x6;
                    eax = sub_47ad69();
            }
            else {
                    if (ecx != 0x0) {
                            if (esi == 0xc0000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#IND";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (esi == 0x80000000) {
                                            if (edi == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#INF";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x5;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_84 = "1#QNAN";
                                                    esp = (esp - 0x8) + 0xc;
                                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    ebx[0x3] = 0x6;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
                    else {
                            if (esi == 0x80000000) {
                                    if (edi == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#INF";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x5;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_84 = "1#QNAN";
                                            esp = (esp - 0x8) + 0xc;
                                            if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            ebx[0x3] = 0x6;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_84 = "1#QNAN";
                                    esp = (esp - 0x8) + 0xc;
                                    if (sub_47db5e(ebx + 0x4, 0x16, decomp_var_84) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    ebx[0x3] = 0x6;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    return eax;

loc_49172c:
    edx = var_60;
    ecx = var_4C;
    *(int16_t *)edx = ecx;
    if ((arg_10 & 0x1) != 0x0) {
            arg_c = arg_c + sign_extend_32(ecx);
            if (arg_c <= 0x0) {
                    *(int16_t *)edx = *(int16_t *)edx & 0x0;
                    edx[0x3] = 0x1;
                    edx[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                    edx[0x4] = 0x30;
                    edx[0x5] = 0x0;
                    eax = sub_47ad69();
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (arg_c > 0x15) {
                            arg_c = 0x15;
                    }
                    esi = (var_18 >> 0x10) - 0x3ffe;
                    ebx = 0x8;
                    esp = (esp - 0x4) + 0x4;
                    do {
                            eax = var_20;
                            var_20 = var_20 << 0x1;
                            edi = var_1C + var_1C | eax >> 0x1f;
                            eax = var_18 + var_18 | var_1C >> 0x1f;
                            ebx = ebx - 0x1;
                            var_1C = edi;
                            var_18 = eax;
                    } while (ebx != 0x0);
                    if (esi < 0x0) {
                            esi = -esi & 0xff;
                            if (esi > 0x0) {
                                    eax = var_18;
                                    var_18 = var_18 >> 0x1;
                                    edi = var_1C >> 0x1 | eax << 0x1f;
                                    eax = var_20 >> 0x1 | var_1C << 0x1f;
                                    esi = esi - 0x1;
                                    var_1C = edi;
                                    var_20 = eax;
                                    if (esi > 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    bool_226 = true;
                    bool_225 = true;
                    bool_224 = true;
                    ebx = edx + 0x4;
                    var_40 = ebx;
                    var_4C = arg_c + 0x1;
                    if (arg_c > 0xffffffff) {
                            var_3C = var_20;
                            var_3C = var_20;
                            var_3C = var_20;
                            edx = var_3C;
                            ecx = (var_18 + var_18 | var_1C >> 0x1f) + (var_18 + var_18 | var_1C >> 0x1f) | (var_1C + var_1C | var_20 >> 0x1f) >> 0x1f;
                            esi = (var_1C + var_1C | var_20 >> 0x1f) + (var_1C + var_1C | var_20 >> 0x1f) | var_20 << 0x1 >> 0x1f;
                            edi = edx + (var_20 << 0x1 << 0x1);
                            if (edi >= var_20 << 0x1 << 0x1) {
                                    if (edi < edx) {
                                            eax = esi + 0x1;
                                            edx = 0x0;
                                            if (eax < esi || eax < 0x1) {
                                                    edx = 0x1;
                                            }
                                            esi = eax;
                                            if (edx != 0x0) {
                                                    ecx = ecx + 0x1;
                                            }
                                    }
                            }
                            else {
                                    eax = esi + 0x1;
                                    edx = 0x0;
                                    if (eax < esi || eax < 0x1) {
                                            edx = 0x1;
                                    }
                                    esi = eax;
                                    if (edx != 0x0) {
                                            ecx = ecx + 0x1;
                                    }
                            }
                            eax = var_38;
                            edx = eax + esi;
                            var_44 = edx;
                            if (edx < esi || edx < eax) {
                                    ecx = ecx + 0x1;
                            }
                            var_20 = edi + edi;
                            var_18 = ecx + var_34 + ecx + var_34 | edx >> 0x1f;
                            *(int8_t *)ebx = ((ecx + var_34 + ecx + var_34 | edx >> 0x1f) >> 0x18) + 0x30;
                            ebx = ebx + 0x1;
                            var_4C = var_4C - 0x1;
                            var_1C = var_44 + var_44 | edi >> 0x1f;
                            if (var_4C > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    eax = *(int8_t *)(ebx - 0x1);
                    ebx = ebx - 0x2;
                    if (eax < 0x35) {
                            ecx = var_40;
                            while (ebx >= ecx) {
                                    if (*(int8_t *)ebx != 0x30) {
                                            break;
                                    }
                                    ebx = ebx - 0x1;
                            }
                            eax = var_60;
                            if (ebx < ecx) {
                                    *(int16_t *)eax = *(int16_t *)eax & 0x0;
                                    eax[0x3] = 0x1;
                                    eax[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                                    *(int8_t *)ecx = 0x30;
                                    eax[0x5] = 0x0;
                            }
                            else {
                                    eax[0x3] = ebx - eax - 0x3;
                                    *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                            }
                    }
                    else {
                            while (ebx >= var_40) {
                                    if (*(int8_t *)ebx != 0x39) {
                                            break;
                                    }
                                    *(int8_t *)ebx = 0x30;
                                    ebx = ebx - 0x1;
                            }
                            eax = var_60;
                            if (ebx < var_40) {
                                    ebx = ebx + 0x1;
                                    *(int16_t *)eax = *(int16_t *)eax + 0x1;
                            }
                            *(int8_t *)ebx = *(int8_t *)ebx + 0x1;
                            eax[0x3] = ebx - eax - 0x3;
                            *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                    }
                    eax = sub_47ad69();
            }
    }
    else {
            esp = (esp - 0x4) + 0x4;
            if (arg_c > 0x15) {
                    arg_c = 0x15;
            }
            esi = (var_18 >> 0x10) - 0x3ffe;
            ebx = 0x8;
            esp = (esp - 0x4) + 0x4;
            do {
                    eax = var_20;
                    var_20 = var_20 << 0x1;
                    edi = var_1C + var_1C | eax >> 0x1f;
                    eax = var_18 + var_18 | var_1C >> 0x1f;
                    ebx = ebx - 0x1;
                    var_1C = edi;
                    var_18 = eax;
            } while (ebx != 0x0);
            if (esi < 0x0) {
                    esi = -esi & 0xff;
                    if (esi > 0x0) {
                            eax = var_18;
                            var_18 = var_18 >> 0x1;
                            edi = var_1C >> 0x1 | eax << 0x1f;
                            eax = var_20 >> 0x1 | var_1C << 0x1f;
                            esi = esi - 0x1;
                            var_1C = edi;
                            var_20 = eax;
                            if (esi > 0x0) {
                                    continue;
                            }
                            break;
                    }
            }
            bool_275 = true;
            bool_274 = true;
            bool_273 = true;
            ebx = edx + 0x4;
            var_40 = ebx;
            var_4C = arg_c + 0x1;
            if (arg_c > 0xffffffff) {
                    var_3C = var_20;
                    var_3C = var_20;
                    var_3C = var_20;
                    edx = var_3C;
                    ecx = (var_18 + var_18 | var_1C >> 0x1f) + (var_18 + var_18 | var_1C >> 0x1f) | (var_1C + var_1C | var_20 >> 0x1f) >> 0x1f;
                    esi = (var_1C + var_1C | var_20 >> 0x1f) + (var_1C + var_1C | var_20 >> 0x1f) | var_20 << 0x1 >> 0x1f;
                    edi = edx + (var_20 << 0x1 << 0x1);
                    if (edi >= var_20 << 0x1 << 0x1) {
                            if (edi < edx) {
                                    eax = esi + 0x1;
                                    edx = 0x0;
                                    if (eax < esi || eax < 0x1) {
                                            edx = 0x1;
                                    }
                                    esi = eax;
                                    if (edx != 0x0) {
                                            ecx = ecx + 0x1;
                                    }
                            }
                    }
                    else {
                            eax = esi + 0x1;
                            edx = 0x0;
                            if (eax < esi || eax < 0x1) {
                                    edx = 0x1;
                            }
                            esi = eax;
                            if (edx != 0x0) {
                                    ecx = ecx + 0x1;
                            }
                    }
                    eax = var_38;
                    edx = eax + esi;
                    var_44 = edx;
                    if (edx < esi || edx < eax) {
                            ecx = ecx + 0x1;
                    }
                    var_20 = edi + edi;
                    var_18 = ecx + var_34 + ecx + var_34 | edx >> 0x1f;
                    *(int8_t *)ebx = ((ecx + var_34 + ecx + var_34 | edx >> 0x1f) >> 0x18) + 0x30;
                    ebx = ebx + 0x1;
                    var_4C = var_4C - 0x1;
                    var_1C = var_44 + var_44 | edi >> 0x1f;
                    if (var_4C > 0x0) {
                            continue;
                    }
                    break;
            }
            eax = *(int8_t *)(ebx - 0x1);
            ebx = ebx - 0x2;
            if (eax < 0x35) {
                    ecx = var_40;
                    while (ebx >= ecx) {
                            if (*(int8_t *)ebx != 0x30) {
                                    break;
                            }
                            ebx = ebx - 0x1;
                    }
                    eax = var_60;
                    if (ebx < ecx) {
                            *(int16_t *)eax = *(int16_t *)eax & 0x0;
                            eax[0x3] = 0x1;
                            eax[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                            *(int8_t *)ecx = 0x30;
                            eax[0x5] = 0x0;
                    }
                    else {
                            eax[0x3] = ebx - eax - 0x3;
                            *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                    }
            }
            else {
                    while (ebx >= var_40) {
                            if (*(int8_t *)ebx != 0x39) {
                                    break;
                            }
                            *(int8_t *)ebx = 0x30;
                            ebx = ebx - 0x1;
                    }
                    eax = var_60;
                    if (ebx < var_40) {
                            ebx = ebx + 0x1;
                            *(int16_t *)eax = *(int16_t *)eax + 0x1;
                    }
                    *(int8_t *)ebx = *(int8_t *)ebx + 0x1;
                    eax[0x3] = ebx - eax - 0x3;
                    *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
            }
            eax = sub_47ad69();
    }
    return eax;

loc_4914e2:
    var_4C = var_4C + 0x1;
    edx = ecx & 0xffff;
    ecx = var_26 ^ edx;
    edx = edx & 0x7fff;
    esi = var_26 & 0x7fff;
    ecx = ecx & 0x8000;
    var_58 = 0x0;
    var_10 = 0x0;
    var_C = 0x0;
    var_8 = 0x0;
    edi = esi + edx & 0xffff;
    if (edx >= 0x7fff || esi >= 0x7fff || edi > 0xbffd) goto loc_491712;
    goto loc_491528;

.l180:
    var_68 = var_68 + 0x54;
    ecx = ebx & 0x7;
    ebx = SAR(ebx, 0x3);
    if (ecx == 0x0) goto .l191;
    goto .l144;

.l2:
    ecx = var_18 >> 0x10;
    if (ecx < 0x3fff) goto .l6;
    goto .l11;

.l9:
    if (!bool_155) {
            ebx = -ebx;
            var_68 = 0x4ca2c0;
    }
    if (ebx == 0x0) goto .l2;
    goto loc_491235;

loc_491712:
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    goto loc_491726;

loc_491528:
    if (edi > 0x3fbf) goto loc_491537;
    goto loc_49152f;

.l191:
    if (ebx != 0x0) {
            continue;
    }
    break;

.l144:
    ecx = ecx * 0xc + var_68;
    bool_907 = true;
    bool_906 = true;
    bool_905 = true;
    var_64 = ecx;
    if (*(int16_t *)ecx >= 0x8000) {
            var_3C = *ecx;
            var_3C = *ecx;
            var_3C = *ecx;
            var_3A = var_3A - 0x1;
            var_64 = &var_3C;
            ecx = &var_3C;
    }
    edi = ecx[0x5] & 0xffff;
    ecx = edi ^ var_16;
    edx = var_16 & 0x7fff;
    edi = edi & 0x7fff;
    var_48 = 0x0;
    var_10 = 0x0;
    var_C = 0x0;
    var_8 = 0x0;
    ecx = ecx & 0x8000;
    eax = edi + edx & 0xffff;
    if (edx >= 0x7fff) goto .l190;
    goto .l142;

.l6:
    edx = var_60;
    ecx = var_4C;
    *(int16_t *)edx = ecx;
    if ((arg_10 & 0x1) != 0x0) {
            arg_c = arg_c + sign_extend_32(ecx);
            if (arg_c <= 0x0) {
                    *(int16_t *)edx = *(int16_t *)edx & 0x0;
                    edx[0x3] = 0x1;
                    edx[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                    edx[0x4] = 0x30;
                    edx[0x5] = 0x0;
                    eax = sub_47ad69();
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (arg_c > 0x15) {
                            arg_c = 0x15;
                    }
                    esi = (var_18 >> 0x10) - 0x3ffe;
                    ebx = 0x8;
                    esp = (esp - 0x4) + 0x4;
                    do {
                            eax = var_20;
                            var_20 = var_20 << 0x1;
                            edi = var_1C + var_1C | eax >> 0x1f;
                            eax = var_18 + var_18 | var_1C >> 0x1f;
                            ebx = ebx - 0x1;
                            var_1C = edi;
                            var_18 = eax;
                    } while (ebx != 0x0);
                    if (esi < 0x0) {
                            esi = -esi & 0xff;
                            if (esi > 0x0) {
                                    eax = var_18;
                                    var_18 = var_18 >> 0x1;
                                    edi = var_1C >> 0x1 | eax << 0x1f;
                                    eax = var_20 >> 0x1 | var_1C << 0x1f;
                                    esi = esi - 0x1;
                                    var_1C = edi;
                                    var_20 = eax;
                                    if (esi > 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    bool_263 = true;
                    bool_262 = true;
                    bool_261 = true;
                    ebx = edx + 0x4;
                    var_40 = ebx;
                    var_4C = arg_c + 0x1;
                    if (arg_c > 0xffffffff) {
                            var_3C = var_20;
                            var_3C = var_20;
                            var_3C = var_20;
                            edx = var_3C;
                            ecx = (var_18 + var_18 | var_1C >> 0x1f) + (var_18 + var_18 | var_1C >> 0x1f) | (var_1C + var_1C | var_20 >> 0x1f) >> 0x1f;
                            esi = (var_1C + var_1C | var_20 >> 0x1f) + (var_1C + var_1C | var_20 >> 0x1f) | var_20 << 0x1 >> 0x1f;
                            edi = edx + (var_20 << 0x1 << 0x1);
                            if (edi >= var_20 << 0x1 << 0x1) {
                                    if (edi < edx) {
                                            eax = esi + 0x1;
                                            edx = 0x0;
                                            if (eax < esi || eax < 0x1) {
                                                    edx = 0x1;
                                            }
                                            esi = eax;
                                            if (edx != 0x0) {
                                                    ecx = ecx + 0x1;
                                            }
                                    }
                            }
                            else {
                                    eax = esi + 0x1;
                                    edx = 0x0;
                                    if (eax < esi || eax < 0x1) {
                                            edx = 0x1;
                                    }
                                    esi = eax;
                                    if (edx != 0x0) {
                                            ecx = ecx + 0x1;
                                    }
                            }
                            eax = var_38;
                            edx = eax + esi;
                            var_44 = edx;
                            if (edx < esi || edx < eax) {
                                    ecx = ecx + 0x1;
                            }
                            var_20 = edi + edi;
                            var_18 = ecx + var_34 + ecx + var_34 | edx >> 0x1f;
                            *(int8_t *)ebx = ((ecx + var_34 + ecx + var_34 | edx >> 0x1f) >> 0x18) + 0x30;
                            ebx = ebx + 0x1;
                            var_4C = var_4C - 0x1;
                            var_1C = var_44 + var_44 | edi >> 0x1f;
                            if (var_4C > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    eax = *(int8_t *)(ebx - 0x1);
                    ebx = ebx - 0x2;
                    if (eax < 0x35) {
                            ecx = var_40;
                            while (ebx >= ecx) {
                                    if (*(int8_t *)ebx != 0x30) {
                                            break;
                                    }
                                    ebx = ebx - 0x1;
                            }
                            eax = var_60;
                            if (ebx < ecx) {
                                    *(int16_t *)eax = *(int16_t *)eax & 0x0;
                                    eax[0x3] = 0x1;
                                    eax[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                                    *(int8_t *)ecx = 0x30;
                                    eax[0x5] = 0x0;
                            }
                            else {
                                    eax[0x3] = ebx - eax - 0x3;
                                    *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                            }
                    }
                    else {
                            while (ebx >= var_40) {
                                    if (*(int8_t *)ebx != 0x39) {
                                            break;
                                    }
                                    *(int8_t *)ebx = 0x30;
                                    ebx = ebx - 0x1;
                            }
                            eax = var_60;
                            if (ebx < var_40) {
                                    ebx = ebx + 0x1;
                                    *(int16_t *)eax = *(int16_t *)eax + 0x1;
                            }
                            *(int8_t *)ebx = *(int8_t *)ebx + 0x1;
                            eax[0x3] = ebx - eax - 0x3;
                            *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                    }
                    eax = sub_47ad69();
            }
    }
    else {
            esp = (esp - 0x4) + 0x4;
            if (arg_c > 0x15) {
                    arg_c = 0x15;
            }
            esi = (var_18 >> 0x10) - 0x3ffe;
            ebx = 0x8;
            esp = (esp - 0x4) + 0x4;
            do {
                    eax = var_20;
                    var_20 = var_20 << 0x1;
                    edi = var_1C + var_1C | eax >> 0x1f;
                    eax = var_18 + var_18 | var_1C >> 0x1f;
                    ebx = ebx - 0x1;
                    var_1C = edi;
                    var_18 = eax;
            } while (ebx != 0x0);
            if (esi < 0x0) {
                    esi = -esi & 0xff;
                    if (esi > 0x0) {
                            eax = var_18;
                            var_18 = var_18 >> 0x1;
                            edi = var_1C >> 0x1 | eax << 0x1f;
                            eax = var_20 >> 0x1 | var_1C << 0x1f;
                            esi = esi - 0x1;
                            var_1C = edi;
                            var_20 = eax;
                            if (esi > 0x0) {
                                    continue;
                            }
                            break;
                    }
            }
            bool_251 = true;
            bool_250 = true;
            bool_249 = true;
            ebx = edx + 0x4;
            var_40 = ebx;
            var_4C = arg_c + 0x1;
            if (arg_c > 0xffffffff) {
                    var_3C = var_20;
                    var_3C = var_20;
                    var_3C = var_20;
                    edx = var_3C;
                    ecx = (var_18 + var_18 | var_1C >> 0x1f) + (var_18 + var_18 | var_1C >> 0x1f) | (var_1C + var_1C | var_20 >> 0x1f) >> 0x1f;
                    esi = (var_1C + var_1C | var_20 >> 0x1f) + (var_1C + var_1C | var_20 >> 0x1f) | var_20 << 0x1 >> 0x1f;
                    edi = edx + (var_20 << 0x1 << 0x1);
                    if (edi >= var_20 << 0x1 << 0x1) {
                            if (edi < edx) {
                                    eax = esi + 0x1;
                                    edx = 0x0;
                                    if (eax < esi || eax < 0x1) {
                                            edx = 0x1;
                                    }
                                    esi = eax;
                                    if (edx != 0x0) {
                                            ecx = ecx + 0x1;
                                    }
                            }
                    }
                    else {
                            eax = esi + 0x1;
                            edx = 0x0;
                            if (eax < esi || eax < 0x1) {
                                    edx = 0x1;
                            }
                            esi = eax;
                            if (edx != 0x0) {
                                    ecx = ecx + 0x1;
                            }
                    }
                    eax = var_38;
                    edx = eax + esi;
                    var_44 = edx;
                    if (edx < esi || edx < eax) {
                            ecx = ecx + 0x1;
                    }
                    var_20 = edi + edi;
                    var_18 = ecx + var_34 + ecx + var_34 | edx >> 0x1f;
                    *(int8_t *)ebx = ((ecx + var_34 + ecx + var_34 | edx >> 0x1f) >> 0x18) + 0x30;
                    ebx = ebx + 0x1;
                    var_4C = var_4C - 0x1;
                    var_1C = var_44 + var_44 | edi >> 0x1f;
                    if (var_4C > 0x0) {
                            continue;
                    }
                    break;
            }
            eax = *(int8_t *)(ebx - 0x1);
            ebx = ebx - 0x2;
            if (eax < 0x35) {
                    ecx = var_40;
                    while (ebx >= ecx) {
                            if (*(int8_t *)ebx != 0x30) {
                                    break;
                            }
                            ebx = ebx - 0x1;
                    }
                    eax = var_60;
                    if (ebx < ecx) {
                            *(int16_t *)eax = *(int16_t *)eax & 0x0;
                            eax[0x3] = 0x1;
                            eax[0x2] = ((var_6C != 0x8000 ? 0x1 : 0x0) - 0x1 & 0xd) + 0x20;
                            *(int8_t *)ecx = 0x30;
                            eax[0x5] = 0x0;
                    }
                    else {
                            eax[0x3] = ebx - eax - 0x3;
                            *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
                    }
            }
            else {
                    while (ebx >= var_40) {
                            if (*(int8_t *)ebx != 0x39) {
                                    break;
                            }
                            *(int8_t *)ebx = 0x30;
                            ebx = ebx - 0x1;
                    }
                    eax = var_60;
                    if (ebx < var_40) {
                            ebx = ebx + 0x1;
                            *(int16_t *)eax = *(int16_t *)eax + 0x1;
                    }
                    *(int8_t *)ebx = *(int8_t *)ebx + 0x1;
                    eax[0x3] = ebx - eax - 0x3;
                    *(int8_t *)(sign_extend_32(ebx - eax - 0x3) + eax + 0x4) = 0x0;
            }
            eax = sub_47ad69();
    }
    return eax;

.l11:
    var_4C = var_4C + 0x1;
    edx = ecx & 0xffff;
    ecx = var_26 ^ edx;
    edx = edx & 0x7fff;
    esi = var_26 & 0x7fff;
    ecx = ecx & 0x8000;
    var_58 = 0x0;
    var_10 = 0x0;
    var_C = 0x0;
    var_8 = 0x0;
    edi = esi + edx & 0xffff;
    if (edx >= 0x7fff || esi >= 0x7fff || edi > 0xbffd) goto .l19;
    goto .l12;

loc_491235:
    var_68 = var_68 + 0x54;
    ecx = ebx & 0x7;
    ebx = SAR(ebx, 0x3);
    if (ecx == 0x0) goto .l5;
    goto loc_491249;

loc_491726:
    var_1C = 0x0;
    var_20 = 0x0;
    goto loc_49172c;

loc_491537:
    eax = 0x0;
    if (edx != 0x0) goto loc_491559;
    goto loc_49153c;

loc_49152f:
    var_18 = 0x0;
    goto loc_491726;

.l190:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l142:
    if (edi >= 0x7fff) goto .l188;
    goto .l139;

.l19:
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    goto .l13;

.l12:
    if (edi > 0x3fbf) goto .l16;
    goto .l10;

.l5:
    if (ebx != 0x0) {
            continue;
    }
    break;

loc_491249:
    ecx = ecx * 0xc + var_68;
    bool_316 = true;
    bool_315 = true;
    bool_314 = true;
    var_64 = ecx;
    if (*(int16_t *)ecx >= 0x8000) {
            var_3C = *ecx;
            var_3C = *ecx;
            var_3C = *ecx;
            var_3A = var_3A - 0x1;
            var_64 = &var_3C;
            ecx = &var_3C;
    }
    edi = ecx[0x5] & 0xffff;
    ecx = edi ^ var_16;
    edx = var_16 & 0x7fff;
    edi = edi & 0x7fff;
    var_48 = 0x0;
    var_10 = 0x0;
    var_C = 0x0;
    var_8 = 0x0;
    ecx = ecx & 0x8000;
    eax = edi + edx & 0xffff;
    if (edx >= 0x7fff) goto loc_4914a6;
    goto loc_4912a3;

loc_491559:
    if (esi != eax) goto loc_491572;
    goto loc_49155e;

loc_49153c:
    edi = edi + 0x1;
    if ((var_18 & 0x7fffffff) != 0x0 || var_1C != eax || var_20 != eax) goto loc_491559;
    goto loc_49172c;

.l188:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l139:
    if (eax > 0xbffd) goto .l152;
    goto .l173;

.l13:
    var_1C = 0x0;
    var_20 = 0x0;
    goto .l6;

.l16:
    if (edx != 0x0) goto .l7;
    goto .l17;

.l10:
    var_18 = 0x0;
    goto .l13;

loc_4914a6:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

loc_4912a3:
    if (edi >= 0x7fff) goto .l52;
    goto loc_4912ac;

loc_491572:
    var_54 = var_54 & 0x0;
    eax = &var_C;
    var_40 = 0x5;
    goto loc_491580;

loc_49155e:
    edi = edi + 0x1;
    if ((var_28 & 0x7fffffff) != 0x0 || var_2C != eax || var_30 != eax) goto loc_491572;
    goto loc_49152f;

.l152:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l173:
    if (eax > 0x3fbf) goto .l169;
    goto .l143;

.l7:
    if (esi != 0x0) goto .l15;
    goto .l14;

.l17:
    edi = edi + 0x1;
    if ((var_18 & 0x7fffffff) != 0x0 || var_1C != 0x0) goto .l7;
    goto loc_49154b;

.l52:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

loc_4912ac:
    if (eax > 0xbffd) goto .l31;
    goto loc_4912b6;

loc_491580:
    edx = var_54 + var_54;
    var_50 = var_40;
    if (var_40 <= 0x0) goto loc_4915e1;
    goto loc_49158f;

.l169:
    if (edx != 0x0) goto .l159;
    goto .l171;

.l143:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l15:
    var_54 = var_54 & 0x0;
    eax = &var_C;
    var_40 = 0x5;
    goto .l21;

.l14:
    edi = edi + 0x1;
    if ((var_28 & 0x7fffffff) != 0x0) goto .l15;
    goto loc_491568;

loc_49154b:
    eax = 0x0;
    if (var_20 != 0x0) goto .l7;
    goto .l6;

.l31:
    var_1C = var_1C & 0x0;
    var_20 = var_20 & 0x0;
    var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    if (ebx != 0x0) {
            continue;
    }
    break;

loc_4912b6:
    if (eax > 0x3fbf) goto loc_4912cc;
    goto loc_4912bc;

loc_4915e1:
    eax = eax + 0x2;
    var_54 = var_54 + 0x1;
    var_40 = var_40 - 0x1;
    if (var_40 > 0x0) {
            continue;
    }
    break;

loc_49158f:
    var_5C = &var_28;
    var_48 = ebp + (edx - 0x20);
    goto loc_49159c;

.l159:
    if (edi != 0x0) goto .l197;
    goto .l166;

.l171:
    eax = eax + 0x1;
    if ((var_18 & 0x7fffffff) != 0x0) goto .l135;
    goto .l162;

.l21:
    edx = var_54 + var_54;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l22;
    goto .l20;

loc_491568:
    eax = 0x0;
    if (var_2C != 0x0 || var_30 != eax) goto .l15;
    goto .l10;

loc_4912cc:
    if (edx != 0x0) goto .l36;
    goto loc_4912d3;

loc_4912bc:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    ebx = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    edi = edi + 0xffff;
                    var_C = ebx;
                    var_8 = edx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            eax = -edi & 0xffff;
                            edi = edi + eax;
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_58 = var_58 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    ebx = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    eax = eax - 0x1;
                                    var_C = ebx;
                                    var_10 = edx;
                            } while (eax != 0x0);
                            if (var_58 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    eax = -edi & 0xffff;
                    edi = edi + eax;
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_58 = var_58 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            ebx = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            eax = eax - 0x1;
                            var_C = ebx;
                            var_10 = edx;
                    } while (eax != 0x0);
                    if (var_58 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 > 0x8000 || (var_10 & 0x1ffff) == 0x18000) {
            if (var_E == 0xffffffff) {
                    var_E = 0x0;
                    if (var_A == 0xffffffff && var_6 == 0xffff) {
                            edi = edi + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (edi >= 0x7fff) {
            var_1C = 0x0;
            var_20 = 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    }
    else {
            var_20 = var_E;
    }
    goto loc_49172c;

loc_49159c:
    esi = *(int16_t *)var_48 & 0xffff;
    edx = *(int16_t *)var_5C & 0xffff;
    var_44 = var_44 & 0x0;
    edx = edx * esi;
    esi = *(eax - 0x4);
    ebx = esi + edx;
    if (ebx < esi || ebx < edx) {
            var_44 = 0x1;
    }
    *(eax - 0x4) = ebx;
    if (var_44 != 0x0) {
            *(int16_t *)eax = *(int16_t *)eax + 0x1;
    }
    var_48 = var_48 + 0x2;
    var_5C = var_5C - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l197:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l232;

.l166:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l189;
    goto .l149;

.l135:
    if (edi != 0x0) goto .l179;
    goto .l183;

.l162:
    if (var_1C != 0x0) goto .l147;
    goto .l134;

.l22:
    eax = eax + 0x2;
    var_54 = var_54 + 0x1;
    var_40 = var_40 - 0x1;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l20:
    var_5C = &var_28;
    var_48 = ebp + (edx - 0x20);
    goto .l23;

.l36:
    if (edi != 0x0) goto .l40;
    goto .l58;

loc_4912d3:
    eax = eax + 0x1;
    if ((var_18 & 0x7fffffff) != 0x0) goto .l24;
    goto loc_4912dd;

.l232:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l231;
    goto .l230;

.l189:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l198;

.l149:
    if (edx[0x1] != 0x0) goto .l157;
    goto .l185;

.l179:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l206;

.l183:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l181;
    goto .l187;

.l147:
    if (edi != 0x0) goto .l170;
    goto .l176;

.l134:
    if (var_20 != 0x0) goto .l156;
    goto .l131;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    ebx = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    edi = edi + 0xffff;
                    var_C = ebx;
                    var_8 = edx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            eax = -edi & 0xffff;
                            edi = edi + eax;
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_58 = var_58 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    ebx = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    eax = eax - 0x1;
                                    var_C = ebx;
                                    var_10 = edx;
                            } while (eax != 0x0);
                            if (var_58 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    eax = -edi & 0xffff;
                    edi = edi + eax;
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_58 = var_58 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            ebx = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            eax = eax - 0x1;
                            var_C = ebx;
                            var_10 = edx;
                    } while (eax != 0x0);
                    if (var_58 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = 0x0;
                            if (var_A == 0xffffffff && var_6 == 0xffff) {
                                    edi = edi + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = 0x0;
                    if (var_A == 0xffffffff && var_6 == 0xffff) {
                            edi = edi + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (edi >= 0x7fff) {
            var_1C = 0x0;
            var_20 = 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    }
    else {
            var_20 = var_E;
    }
    goto .l6;

.l23:
    esi = *(int16_t *)var_48 & 0xffff;
    edx = *(int16_t *)var_5C & 0xffff;
    var_44 = var_44 & 0x0;
    edx = edx * esi;
    esi = *(eax - 0x4);
    ebx = esi + edx;
    if (ebx < esi || ebx < edx) {
            var_44 = 0x1;
    }
    *(eax - 0x4) = ebx;
    if (var_44 != 0x0) {
            *(int16_t *)eax = *(int16_t *)eax + 0x1;
    }
    var_48 = var_48 + 0x2;
    var_5C = var_5C - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l40:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto loc_491329;

.l58:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l26;
    goto .l59;

.l24:
    if (edi != 0x0) goto .l45;
    goto .l70;

loc_4912dd:
    if (var_1C != 0x0) goto .l25;
    goto loc_4912e2;

.l231:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l230:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l233;

.l198:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l200;
    goto .l199;

.l157:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l258;

.l185:
    if (*edx != 0x0) goto .l141;
    goto .l161;

.l206:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l208;
    goto .l207;

.l181:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l219;

.l187:
    esi = 0x0;
    if (edx[0x1] != 0x0) goto .l192;
    goto .l194;

.l170:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l248;

.l176:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l137;
    goto .l153;

.l156:
    esi = 0x0;
    if (edi != 0x0) goto .l178;
    goto .l138;

.l131:
    var_16 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

loc_491329:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto loc_491390;
    goto loc_491338;

.l26:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l77;

.l59:
    if (edx[0x1] != 0x0) goto .l27;
    goto .l62;

.l45:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l124;

.l70:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l48;
    goto .l44;

.l25:
    if (edi != 0x0) goto .l54;
    goto loc_4912f5;

loc_4912e2:
    if (var_20 != 0x0) goto loc_4912f0;
    goto loc_4912e7;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l233:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l200:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l199:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l201;

.l258:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l259;
    goto .l260;

.l141:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l234;

.l161:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l208:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l207:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l209;

.l219:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l220;
    goto .l218;

.l192:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l204;

.l194:
    if (*edx != esi) goto .l196;
    goto .l140;

.l248:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l246;
    goto .l247;

.l137:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l216;

.l153:
    if (edx[0x1] != 0x0) goto .l172;
    goto .l150;

.l178:
    edi = &var_C;
    var_5C = esi;
    var_44 = edi;
    var_40 = 0x5;
    goto .l240;

.l138:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l182;
    goto .l155;

loc_491390:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

loc_491338:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto loc_491348;

.l77:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l75;
    goto .l76;

.l27:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l121;

.l62:
    esi = 0x0;
    if (*edx != 0x0) goto .l63;
    goto .l32;

.l124:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l123;
    goto .l125;

.l48:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l129;

.l44:
    if (edx[0x1] != 0x0) goto .l53;
    goto loc_491307;

.l54:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l85;

loc_4912f5:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l41;
    goto .l68;

loc_4912f0:
    if (edi != 0x0) goto .l57;
    goto .l49;

loc_4912e7:
    var_16 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l201:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l259:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l260:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l261;

.l234:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l235;
    goto .l236;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l209:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l220:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l218:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l221;

.l204:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l202;
    goto .l203;

.l196:
    edi = &var_C;
    var_5C = esi;
    var_44 = edi;
    var_40 = 0x5;
    goto .l210;

.l140:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l246:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l247:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l249;

.l216:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l215;
    goto .l214;

.l172:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l223;

.l150:
    if (*edx != 0x0) goto .l165;
    goto .l193;

.l240:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l239;
    goto .l238;

.l182:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l255;

.l155:
    if (edx[0x1] != 0x0) goto .l145;
    goto .l136;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

loc_491348:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l75:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l76:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l78;

.l121:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l120;
    goto .l119;

.l63:
    edi = &var_C;
    var_5C = esi;
    var_44 = edi;
    var_40 = 0x5;
    goto .l95;

.l32:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l123:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l125:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l126;

.l129:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l128;
    goto .l127;

.l53:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l115;

loc_491307:
    if (*edx != 0x0) goto .l66;
    goto loc_49130b;

.l85:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l83;
    goto .l84;

.l41:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l87;

.l68:
    if (edx[0x1] != 0x0) goto .l65;
    goto .l38;

.l57:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l93;

.l49:
    edx = var_64;
    eax = eax + 0x1;
    if ((edx[0x2] & 0x7fffffff) != 0x0) goto .l34;
    goto loc_491302;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l261:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l235:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l236:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l237;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l221:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l202:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l203:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l205;

.l210:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l211;
    goto .l212;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l249:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l215:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l214:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l217;

.l223:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l222;
    goto .l224;

.l165:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l251;

.l193:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l239:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l238:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l241;

.l255:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l254;
    goto .l256;

.l145:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l228;

.l136:
    esi = 0x0;
    if (*edx != 0x0) goto .l177;
    goto .l175;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l78:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l120:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l119:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l122;

.l95:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l97;
    goto .l96;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l126:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l128:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l127:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l130;

.l115:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l117;
    goto .l116;

.l66:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l101;

loc_49130b:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l83:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l84:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l86;

.l87:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l88;
    goto .l89;

.l65:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l73;

.l38:
    if (*edx != 0x0) goto loc_491319;
    goto .l33;

.l93:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l91;
    goto .l92;

.l34:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l108;

loc_491302:
    if (edx[0x1] != 0x0) goto .l50;
    goto .l47;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l237:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l205:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l211:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l212:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l213;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l217:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l222:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l224:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l225;

.l251:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l252;
    goto .l250;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l241:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l254:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l256:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l257;

.l228:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l227;
    goto .l226;

.l177:
    edi = &var_C;
    var_5C = esi;
    var_44 = edi;
    var_40 = 0x5;
    goto .l243;

.l175:
    var_18 = esi;
    var_1C = esi;
    var_20 = esi;
    if (ebx != 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l122:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l97:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l96:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l98;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l130:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l117:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l116:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l118;

.l101:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l99;
    goto .l100;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l86:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l88:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l89:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l90;

.l73:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l72;
    goto .l71;

loc_491319:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l104;

.l33:
    var_18 = 0x0;
    var_1C = 0x0;
    var_20 = 0x0;
    if (ebx != 0x0) {
            continue;
    }
    break;

.l91:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l92:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l94;

.l108:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l107;
    goto .l109;

.l50:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l81;

.l47:
    esi = 0x0;
    if (*edx != 0x0) goto .l37;
    goto .l51;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l213:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l225:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l252:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l250:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l253;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l257:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l227:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l226:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l229;

.l243:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l242;
    goto .l244;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l98:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l118:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l99:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l100:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l102;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l90:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l72:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l71:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l74;

.l104:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l103;
    goto .l105;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l94:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l107:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l109:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l110;

.l81:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l80;
    goto .l79;

.l37:
    edi = &var_C;
    var_5C = 0x0;
    var_44 = edi;
    var_40 = 0x5;
    goto .l112;

.l51:
    var_18 = esi;
    var_1C = esi;
    var_20 = esi;
    if (ebx != 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l253:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l229:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l242:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l244:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l245;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l102:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l74:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l103:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l105:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l106;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l110:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l80:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l79:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l82;

.l112:
    edx = var_5C + var_5C;
    var_50 = var_40;
    if (var_40 <= 0x0) goto .l111;
    goto .l113;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_4914cc;

.l245:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l106:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l82:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;

.l111:
    edi = edi + 0x2;
    var_5C = var_5C + 0x1;
    var_40 = var_40 - 0x1;
    var_44 = edi;
    if (var_40 > 0x0) {
            continue;
    }
    break;

.l113:
    var_58 = ebp + (edx - 0x20);
    var_54 = var_64 + 0x8;
    goto .l114;
    eax = eax + 0xc002;
    if (eax > 0x0) {
            while ((var_8 & 0x80000000) == 0x0) {
                    edx = var_10;
                    var_10 = var_10 << 0x1;
                    edi = var_C + var_C | edx >> 0x1f;
                    edx = var_8 + var_8 | var_C >> 0x1f;
                    eax = eax + 0xffff;
                    var_C = edi;
                    var_8 = edx;
                    if (eax <= 0x0) {
                            break;
                    }
            }
            if (eax <= 0x0) {
                    eax = eax + 0xffff;
                    if (eax < 0x0) {
                            var_44 = -eax & 0xffff;
                            eax = eax + (-eax & 0xffff);
                            do {
                                    if ((var_10 & 0x1) != 0x0) {
                                            var_48 = var_48 + 0x1;
                                    }
                                    edx = var_8;
                                    var_8 = var_8 >> 0x1;
                                    edi = var_C >> 0x1 | edx << 0x1f;
                                    edx = var_10 >> 0x1 | var_C << 0x1f;
                                    var_44 = var_44 - 0x1;
                                    var_C = edi;
                                    var_10 = edx;
                            } while (var_44 != 0x0);
                            if (var_48 != 0x0) {
                                    var_10 = var_10 | 0x1;
                            }
                    }
            }
    }
    else {
            eax = eax + 0xffff;
            if (eax < 0x0) {
                    var_44 = -eax & 0xffff;
                    eax = eax + (-eax & 0xffff);
                    do {
                            if ((var_10 & 0x1) != 0x0) {
                                    var_48 = var_48 + 0x1;
                            }
                            edx = var_8;
                            var_8 = var_8 >> 0x1;
                            edi = var_C >> 0x1 | edx << 0x1f;
                            edx = var_10 >> 0x1 | var_C << 0x1f;
                            var_44 = var_44 - 0x1;
                            var_C = edi;
                            var_10 = edx;
                    } while (var_44 != 0x0);
                    if (var_48 != 0x0) {
                            var_10 = var_10 | 0x1;
                    }
            }
    }
    if (var_10 <= 0x8000) {
            if ((var_10 & 0x1ffff) == 0x18000) {
                    if (var_E == 0xffffffff) {
                            var_E = var_E & 0x0;
                            if (var_A == 0xffffffff) {
                                    var_A = var_A & 0x0;
                                    if (var_6 == 0xffff) {
                                            var_6 = 0x8000;
                                            eax = eax + 0x1;
                                    }
                                    else {
                                            var_6 = var_6 + 0x1;
                                    }
                            }
                            else {
                                    var_A = var_A + 0x1;
                            }
                    }
                    else {
                            var_E = var_E + 0x1;
                    }
            }
    }
    else {
            if (var_E == 0xffffffff) {
                    var_E = var_E & 0x0;
                    if (var_A == 0xffffffff) {
                            var_A = var_A & 0x0;
                            if (var_6 == 0xffff) {
                                    var_6 = 0x8000;
                                    eax = eax + 0x1;
                            }
                            else {
                                    var_6 = var_6 + 0x1;
                            }
                    }
                    else {
                            var_A = var_A + 0x1;
                    }
            }
            else {
                    var_E = var_E + 0x1;
            }
    }
    if (eax < 0x7fff) {
            var_20 = var_E;
            var_16 = eax | ecx;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_1C = var_1C & 0x0;
            var_20 = var_20 & 0x0;
            var_18 = (-ecx - -ecx + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            if (ebx != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l114:
    esi = *(int16_t *)var_54 & 0xffff;
    edx = *(int16_t *)var_58 & 0xffff;
    edi = *(edi - 0x4);
    edx = edx * esi;
    var_70 = var_70 & 0x0;
    esi = edi + edx;
    if (esi < edi || esi < edx) {
            var_70 = 0x1;
    }
    edi = var_44;
    *(edi - 0x4) = esi;
    if (var_70 != 0x0) {
            *(int16_t *)edi = *(int16_t *)edi + 0x1;
    }
    var_58 = var_58 + 0x2;
    var_54 = var_54 - 0x2;
    var_50 = var_50 - 0x1;
    if (var_50 > 0x0) {
            continue;
    }
    break;
}
