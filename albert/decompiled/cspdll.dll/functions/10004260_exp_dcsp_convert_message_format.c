// exp_dcsp_convert_message_format @ 0x10004260
// hopper name: exp_dcsp_convert_message_format
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_convert_message_format() {
    eax = arg_4;
    decomp_var_10 = ebx;
    decomp_var_14 = ebp;
    esp = esp - 0x1c;
    var_8 = 0x0;
    var_4 = 0x0;
    var_C = 0x0;
    if (eax != 0xff) {
            eax = (*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + 0x1000a720))(*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + dword_1000a728), arg_0);
            ebx = eax;
            esp = (esp - 0x8) + 0x8;
            if (ebx == 0x0) {
                    eax = eax | 0xffffffff;
            }
            else {
                    saved_fp = 0x1;
                    eax = arg_14;
                    bool_19 = true;
                    bool_18 = true;
                    if (eax != 0xff) {
                            eax = (*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + 0x1000a71c))(*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + dword_1000a728), ebx, &var_4);
                            ebp = eax;
                            esp = (esp - 0xc) + 0xc;
                            if (ebp <= (arg_24 & 0xffff)) {
                                    bool_12 = true;
                                    bool_11 = true;
                                    *arg_1c = *arg_4;
                                    asm { rep movsb  byte [edi], byte [esi] };
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            (*0x10009150)() & 0xffff;
                            ebp = &arg_0;
                            *arg_1c = *arg_4;
                            asm { rep movsb  byte [edi], byte [esi] };
                    }
                    if (arg_8 != 0x0) {
                            free(ebx);
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (arg_10 != 0x0) {
                            free(arg_8);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = ebp;
            }
    }
    else {
            ebx = arg_0;
            eax = arg_14;
            bool_17 = true;
            bool_16 = true;
            if (eax != 0xff) {
                    eax = (*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + 0x1000a71c))(*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + dword_1000a728), ebx, &var_4);
                    ebp = eax;
                    esp = (esp - 0xc) + 0xc;
                    if (ebp <= (arg_24 & 0xffff)) {
                            bool_5 = true;
                            bool_4 = true;
                            *arg_1c = *arg_4;
                            asm { rep movsb  byte [edi], byte [esi] };
                    }
            }
            else {
                    esp = esp - 0x4;
                    (*0x10009150)() & 0xffff;
                    ebp = &arg_0;
                    *arg_1c = *arg_4;
                    asm { rep movsb  byte [edi], byte [esi] };
            }
            if (arg_8 != 0x0) {
                    free(ebx);
                    esp = (esp - 0x4) + 0x4;
            }
            if (arg_10 != 0x0) {
                    free(arg_8);
                    esp = (esp - 0x4) + 0x4;
            }
            eax = ebp;
    }
    return eax;
}
