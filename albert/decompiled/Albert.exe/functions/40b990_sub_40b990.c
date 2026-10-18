// sub_40b990 @ 0x40b990
// hopper name: sub_40b990
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b990() {
    esi = arg_4;
    edi = arg_0;
    ebx = ecx;
    esp = esp - 0x18;
    eax = FindResourceA(edi, (esi >> 0x4) + 0x1 & 0xffff, 0x6);
    if (eax != 0x0) {
            edi = sub_40b5c0(edi, eax, esi);
            esp = (esp - 0xc) + 0xc;
            if (edi == 0x0) {
                    eax = 0x0;
            }
            else {
                    esi = *(int16_t *)edi & 0xffff;
                    eax = (*0x4ca51c)(ebp);
                    ebp = edi + 0x2;
                    esp = esp - 0x24;
                    esi = WideCharToMultiByte(eax, 0x0, ebp, esi, 0x0, 0x0, 0x0, 0x0);
                    eax = *ebx;
                    if ((0x1 - *((eax - 0x10) + 0xc) | *((eax - 0x10) + 0x8) - esi) < 0x0) {
                            esp = esp - 0x4;
                            sub_40b860(esi, saved_fp);
                    }
                    WideCharToMultiByte((*0x4ca51c)(0x0, ebp, *(int16_t *)edi & 0xffff, *ebx, esi, 0x0, 0x0), saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14);
                    esp = (esp - 0x20) + 0x4;
                    if (esi >= 0x0) {
                            eax = *ebx;
                            if (esi <= *(eax - 0x8)) {
                                    *(eax - 0xc) = esi;
                                    *(int8_t *)(esi + *ebx) = 0x0;
                                    eax = 0x1;
                            }
                            else {
                                    eax = sub_40b5a0(0x80070057);
                            }
                    }
                    else {
                            eax = sub_40b5a0(0x80070057);
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
