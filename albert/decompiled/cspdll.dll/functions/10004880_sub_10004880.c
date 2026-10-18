// sub_10004880 @ 0x10004880
// hopper name: sub_10004880
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004880() {
    var_270 = esi;
    esi = 0x2;
    ebx = 0x0;
    vos_trace_thread_start();
    var_274 = &var_268;
    var_268 = arg_0;
    esp = (esp - 0x274) + 0x4;
    if (sub_100049f0(var_274) != 0x0) {
            esi = 0x0;
            eax = 0x0;
            edx = &var_264;
            do {
                    ecx = *edx;
                    if (ecx != 0x0) {
                            ecx = ecx[0x1];
                            *(&var_270 + esi * 0x4 + 0x1a8) = eax;
                            *(&var_270 + esi * 0x4 + 0xd8) = ecx;
                            esi = esi + 0x1;
                    }
                    eax = eax + 0x1;
                    edx = edx + 0x4;
            } while (eax < 0x32);
            esi = esi + 0x2;
            *(&var_270 + esi * 0x4 + 0xd0) = var_268[0x5];
            *(&var_270 + esi * 0x4 + 0xd4) = var_268[0x6];
            do {
                    var_274 = 0xffffffff;
                    var_278 = 0x0;
                    decomp_var_27c = &var_198;
                    esp = esp - 0x10;
                    decomp_var_280 = esi;
                    eax = (*0x10009160)();
                    if (eax == esi - 0x2) {
                            sub_100057b0();
                            esp = (esp - 0x4) + 0x4;
                    }
                    else {
                            if (eax != esi - 0x1) {
                                    if (eax <= esi - 0x3) {
                                            sub_10004d90(&var_278, *(&decomp_var_280 + eax * 0x4 + 0x1a8));
                                            esp = (esp - 0x8) + 0x8;
                                    }
                                    else {
                                            if (eax == 0xffffffff) {
                                                    sub_10005ab0();
                                                    ebx = 0x1;
                                            }
                                    }
                            }
                            else {
                                    ebx = 0x1;
                            }
                    }
                    if (var_1A8 != 0x0) {
                            esi = 0x0;
                            eax = 0x0;
                            edx = &var_270;
                            do {
                                    ecx = *edx;
                                    if (ecx != 0x0) {
                                            ecx = ecx[0x1];
                                            *(&decomp_var_27c + esi * 0x4 + 0x1a8) = eax;
                                            *(&decomp_var_27c + esi * 0x4 + 0xd8) = ecx;
                                            esi = esi + 0x1;
                                    }
                                    eax = eax + 0x1;
                                    edx = edx + 0x4;
                            } while (eax < 0x32);
                            esi = esi + 0x2;
                            *(&decomp_var_27c + esi * 0x4 + 0xd0) = var_274[0x5];
                            *(&decomp_var_27c + esi * 0x4 + 0xd4) = var_274[0x6];
                            var_1A8 = 0x0;
                    }
            } while (ebx == 0x0);
            esi = 0x1;
    }
    sub_10004a80(&var_274, decomp_var_27c);
    ReleaseSemaphore(var_274[0x7], 0x1, 0x0);
    eax = esi;
    return eax;
}
