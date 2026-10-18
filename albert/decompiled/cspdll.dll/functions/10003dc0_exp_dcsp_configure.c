// exp_dcsp_configure @ 0x10003dc0
// hopper name: exp_dcsp_configure
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_configure() {
    esi = malloc(0x3c);
    esp = (esp - 0x18) + 0x4;
    if (esi != 0x0) {
            *esi = 0x0;
            esi[0x4] = 0x0;
            esi[0x5] = 0x1;
            esi[0x6] = 0x1;
            esi[0x3] = 0x0;
            esi[0x6] = 0x0;
            esi[0x7] = 0x0;
            esi[0x8] = 0x0;
            esi[0x9] = 0x1;
            esi[0x28] = 0x50;
            esi[0xb] = *dword_10009184;
            eax = arg_10;
            esi[0xc] = 0x4c4b40;
            esi[0xd] = 0x0;
            esi[0xe] = 0x0;
            if (eax != 0x0) {
                    ebx = 0x0;
                    edi = sub_100062c0(eax);
                    esp = (esp - 0x4) + 0x4;
                    if (edi != 0x0) {
                            eax = sub_10006440(edi, "connection_logging", &arg_4, decomp_var_4);
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0x0) {
                                    esi[0x9] = arg_4;
                            }
                            eax = sub_10006440(edi, "trace_level", &arg_4, decomp_var_4);
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0x0) {
                                    esi[0x28] = arg_4;
                            }
                            eax = sub_100066d0(edi, "trace_filename", 0xf, &arg_8, ebx);
                            esp = (esp - 0x14) + 0x14;
                            if (eax == 0x0) {
                                    esi[0xb] = arg_8;
                            }
                            eax = sub_10006440(edi, "trace_size", &arg_4, decomp_var_4);
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0x0) {
                                    esi[0xc] = arg_4;
                            }
                            eax = sub_100066d0(edi, "trace_filter_in", 0x10, &arg_8, ebx);
                            esp = (esp - 0x14) + 0x14;
                            if (eax == 0x0) {
                                    esi[0xd] = arg_8;
                            }
                            eax = sub_100066d0(edi, "trace_filter_out", 0x11, &arg_8, ebx);
                            esp = (esp - 0x14) + 0x14;
                            if (eax == 0x0) {
                                    esi[0xe] = arg_8;
                            }
                    }
            }
    }
    eax = esi;
    return eax;
}
