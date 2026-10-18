// EntryPoint @ 0x100070f5
// hopper name: EntryPoint
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

EntryPoint() {
    ebx = arg_0;
    esi = arg_4;
    esp = esp - 0x8;
    edi = arg_8;
    bool_90 = esi != 0x0;
    if (esi != 0x0) goto loc_10007111;
    goto loc_10007108;

loc_10007111:
    if (esi == 0x1) goto loc_1000711b;
    goto loc_10007116;

loc_10007108:
    if (bool_90) goto .l4;
    goto .l3;

loc_1000711b:
    eax = *0x1000ab54;
    bool_1 = eax != 0x0;
    if (eax == 0x0) goto loc_1000712d;
    goto loc_10007124;

loc_10007116:
    if (esi == 0x2) {
            eax = *0x1000ab54;
            bool_57 = eax != 0x0;
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    eax = loc_1000ab54(ebx, esi, edi);
                    bool_50 = eax != 0x0;
                    if (eax != 0x0) {
                            esp = esp - 0xc;
                            sub_1000704a(ebx, esi);
                            if (!bool_50) {
                                    eax = 0x0;
                            }
                            else {
                                    esp = esp - 0xc;
                                    eax = sub_100047f0();
                                    arg_4 = eax;
                                    if (esi == 0x1) {
                                            if (eax == 0x0) {
                                                    esp = esp - 0xc;
                                                    sub_1000704a(ebx, eax);
                                                    if (esi != 0x0) {
                                                            if (esi == 0x3) {
                                                                    esp = esp - 0xc;
                                                                    eax = sub_1000704a(ebx, esi);
                                                                    if (eax == 0x0) {
                                                                            arg_4 = arg_4 & eax;
                                                                    }
                                                                    if (arg_4 != 0x0) {
                                                                            if (*0x1000ab54 != 0x0) {
                                                                                    esp = esp - 0xc;
                                                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                                                            }
                                                                    }
                                                                    eax = arg_4;
                                                            }
                                                            else {
                                                                    eax = arg_4;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0xc;
                                                            eax = sub_1000704a(ebx, esi);
                                                            if (eax == 0x0) {
                                                                    arg_4 = arg_4 & eax;
                                                            }
                                                            if (arg_4 != 0x0) {
                                                                    if (*0x1000ab54 != 0x0) {
                                                                            esp = esp - 0xc;
                                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                                    }
                                                            }
                                                            eax = arg_4;
                                                    }
                                            }
                                            else {
                                                    eax = arg_4;
                                            }
                                    }
                                    else {
                                            if (esi != 0x0) {
                                                    if (esi == 0x3) {
                                                            esp = esp - 0xc;
                                                            eax = sub_1000704a(ebx, esi);
                                                            if (eax == 0x0) {
                                                                    arg_4 = arg_4 & eax;
                                                            }
                                                            if (arg_4 != 0x0) {
                                                                    if (*0x1000ab54 != 0x0) {
                                                                            esp = esp - 0xc;
                                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                                    }
                                                            }
                                                            eax = arg_4;
                                                    }
                                                    else {
                                                            eax = arg_4;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0xc;
                                                    eax = sub_1000704a(ebx, esi);
                                                    if (eax == 0x0) {
                                                            arg_4 = arg_4 & eax;
                                                    }
                                                    if (arg_4 != 0x0) {
                                                            if (*0x1000ab54 != 0x0) {
                                                                    esp = esp - 0xc;
                                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                                            }
                                                    }
                                                    eax = arg_4;
                                            }
                                    }
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    esp = esp - 0xc;
                    sub_1000704a(ebx, esi);
                    if (!bool_57) {
                            eax = 0x0;
                    }
                    else {
                            esp = esp - 0xc;
                            eax = sub_100047f0();
                            arg_4 = eax;
                            if (esi == 0x1) {
                                    if (eax == 0x0) {
                                            esp = esp - 0xc;
                                            sub_1000704a(ebx, eax);
                                            if (esi != 0x0) {
                                                    if (esi == 0x3) {
                                                            esp = esp - 0xc;
                                                            eax = sub_1000704a(ebx, esi);
                                                            if (eax == 0x0) {
                                                                    arg_4 = arg_4 & eax;
                                                            }
                                                            if (arg_4 != 0x0) {
                                                                    if (*0x1000ab54 != 0x0) {
                                                                            esp = esp - 0xc;
                                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                                    }
                                                            }
                                                            eax = arg_4;
                                                    }
                                                    else {
                                                            eax = arg_4;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0xc;
                                                    eax = sub_1000704a(ebx, esi);
                                                    if (eax == 0x0) {
                                                            arg_4 = arg_4 & eax;
                                                    }
                                                    if (arg_4 != 0x0) {
                                                            if (*0x1000ab54 != 0x0) {
                                                                    esp = esp - 0xc;
                                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                                            }
                                                    }
                                                    eax = arg_4;
                                            }
                                    }
                                    else {
                                            eax = arg_4;
                                    }
                            }
                            else {
                                    if (esi != 0x0) {
                                            if (esi == 0x3) {
                                                    esp = esp - 0xc;
                                                    eax = sub_1000704a(ebx, esi);
                                                    if (eax == 0x0) {
                                                            arg_4 = arg_4 & eax;
                                                    }
                                                    if (arg_4 != 0x0) {
                                                            if (*0x1000ab54 != 0x0) {
                                                                    esp = esp - 0xc;
                                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                                            }
                                                    }
                                                    eax = arg_4;
                                            }
                                            else {
                                                    eax = arg_4;
                                            }
                                    }
                                    else {
                                            esp = esp - 0xc;
                                            eax = sub_1000704a(ebx, esi);
                                            if (eax == 0x0) {
                                                    arg_4 = arg_4 & eax;
                                            }
                                            if (arg_4 != 0x0) {
                                                    if (*0x1000ab54 != 0x0) {
                                                            esp = esp - 0xc;
                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                    }
                                            }
                                            eax = arg_4;
                                    }
                            }
                    }
            }
    }
    else {
            esp = esp - 0xc;
            eax = sub_100047f0();
            arg_4 = eax;
            if (esi == 0x1) {
                    if (eax == 0x0) {
                            esp = esp - 0xc;
                            sub_1000704a(ebx, eax);
                            if (esi != 0x0) {
                                    if (esi == 0x3) {
                                            esp = esp - 0xc;
                                            eax = sub_1000704a(ebx, esi);
                                            if (eax == 0x0) {
                                                    arg_4 = arg_4 & eax;
                                            }
                                            if (arg_4 != 0x0) {
                                                    if (*0x1000ab54 != 0x0) {
                                                            esp = esp - 0xc;
                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                    }
                                            }
                                            eax = arg_4;
                                    }
                                    else {
                                            eax = arg_4;
                                    }
                            }
                            else {
                                    esp = esp - 0xc;
                                    eax = sub_1000704a(ebx, esi);
                                    if (eax == 0x0) {
                                            arg_4 = arg_4 & eax;
                                    }
                                    if (arg_4 != 0x0) {
                                            if (*0x1000ab54 != 0x0) {
                                                    esp = esp - 0xc;
                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                            }
                                    }
                                    eax = arg_4;
                            }
                    }
                    else {
                            eax = arg_4;
                    }
            }
            else {
                    if (esi != 0x0) {
                            if (esi == 0x3) {
                                    esp = esp - 0xc;
                                    eax = sub_1000704a(ebx, esi);
                                    if (eax == 0x0) {
                                            arg_4 = arg_4 & eax;
                                    }
                                    if (arg_4 != 0x0) {
                                            if (*0x1000ab54 != 0x0) {
                                                    esp = esp - 0xc;
                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                            }
                                    }
                                    eax = arg_4;
                            }
                            else {
                                    eax = arg_4;
                            }
                    }
                    else {
                            esp = esp - 0xc;
                            eax = sub_1000704a(ebx, esi);
                            if (eax == 0x0) {
                                    arg_4 = arg_4 & eax;
                            }
                            if (arg_4 != 0x0) {
                                    if (*0x1000ab54 != 0x0) {
                                            esp = esp - 0xc;
                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                    }
                            }
                            eax = arg_4;
                    }
            }
    }
    return eax;

.l4:
    esp = esp - 0xc;
    eax = sub_100047f0();
    arg_4 = eax;
    if (esi != 0x1) goto .l7;
    goto .l5;

.l3:
    eax = 0x0;
    return eax;

loc_1000712d:
    esp = esp - 0xc;
    sub_1000704a(ebx, esi);
    if (bool_1) goto loc_1000713d;
    goto loc_10007139;

loc_10007124:
    esp = esp - 0xc;
    eax = loc_1000ab54(ebx, esi, edi);
    bool_13 = eax != 0x0;
    if (eax != 0x0) {
            esp = esp - 0xc;
            sub_1000704a(ebx, esi);
            if (!bool_13) {
                    eax = 0x0;
            }
            else {
                    esp = esp - 0xc;
                    eax = sub_100047f0();
                    arg_4 = eax;
                    if (esi == 0x1) {
                            if (eax == 0x0) {
                                    esp = esp - 0xc;
                                    sub_1000704a(ebx, eax);
                                    if (esi != 0x0) {
                                            if (esi == 0x3) {
                                                    esp = esp - 0xc;
                                                    eax = sub_1000704a(ebx, esi);
                                                    if (eax == 0x0) {
                                                            arg_4 = arg_4 & eax;
                                                    }
                                                    if (arg_4 != 0x0) {
                                                            if (*0x1000ab54 != 0x0) {
                                                                    esp = esp - 0xc;
                                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                                            }
                                                    }
                                                    eax = arg_4;
                                            }
                                            else {
                                                    eax = arg_4;
                                            }
                                    }
                                    else {
                                            esp = esp - 0xc;
                                            eax = sub_1000704a(ebx, esi);
                                            if (eax == 0x0) {
                                                    arg_4 = arg_4 & eax;
                                            }
                                            if (arg_4 != 0x0) {
                                                    if (*0x1000ab54 != 0x0) {
                                                            esp = esp - 0xc;
                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                    }
                                            }
                                            eax = arg_4;
                                    }
                            }
                            else {
                                    eax = arg_4;
                            }
                    }
                    else {
                            if (esi != 0x0) {
                                    if (esi == 0x3) {
                                            esp = esp - 0xc;
                                            eax = sub_1000704a(ebx, esi);
                                            if (eax == 0x0) {
                                                    arg_4 = arg_4 & eax;
                                            }
                                            if (arg_4 != 0x0) {
                                                    if (*0x1000ab54 != 0x0) {
                                                            esp = esp - 0xc;
                                                            arg_4 = loc_1000ab54(ebx, esi, edi);
                                                    }
                                            }
                                            eax = arg_4;
                                    }
                                    else {
                                            eax = arg_4;
                                    }
                            }
                            else {
                                    esp = esp - 0xc;
                                    eax = sub_1000704a(ebx, esi);
                                    if (eax == 0x0) {
                                            arg_4 = arg_4 & eax;
                                    }
                                    if (arg_4 != 0x0) {
                                            if (*0x1000ab54 != 0x0) {
                                                    esp = esp - 0xc;
                                                    arg_4 = loc_1000ab54(ebx, esi, edi);
                                            }
                                    }
                                    eax = arg_4;
                            }
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;

.l7:
    if (esi == 0x0 || esi == 0x3) {
            esp = esp - 0xc;
            eax = sub_1000704a(ebx, esi);
            if (eax == 0x0) {
                    arg_4 = arg_4 & eax;
            }
            if (arg_4 != 0x0) {
                    if (*0x1000ab54 != 0x0) {
                            esp = esp - 0xc;
                            arg_4 = loc_1000ab54(ebx, esi, edi);
                    }
            }
    }
    goto loc_10007188;

.l5:
    if (eax != 0x0) goto .l2;
    goto .l6;

loc_1000713d:
    esp = esp - 0xc;
    eax = sub_100047f0();
    arg_4 = eax;
    if (esi != 0x1) goto loc_10007159;
    goto loc_1000714d;

loc_10007139:
    eax = 0x0;
    return eax;

loc_10007188:
    eax = arg_4;
    return eax;

.l2:
    eax = arg_4;
    return eax;

.l6:
    esp = esp - 0xc;
    sub_1000704a(ebx, eax);
    goto .l7;

loc_10007159:
    if (esi == 0x0 || esi == 0x3) {
            esp = esp - 0xc;
            eax = sub_1000704a(ebx, esi);
            if (eax == 0x0) {
                    arg_4 = arg_4 & eax;
            }
            if (arg_4 != 0x0) {
                    if (*0x1000ab54 != 0x0) {
                            esp = esp - 0xc;
                            arg_4 = loc_1000ab54(ebx, esi, edi);
                    }
            }
    }
    goto loc_10007188;

loc_1000714d:
    if (eax != 0x0) goto loc_10007188;

loc_10007151:
    esp = esp - 0xc;
    sub_1000704a(ebx, eax);
    goto loc_10007159;
}
