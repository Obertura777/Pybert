// sub_45ecd0 @ 0x45ecd0
// hopper name: sub_45ecd0
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ecd0() {
    esi = arg_0;
    ebp = ecx;
    sub_45d120(esi);
    esp = esp - 0x24;
    arg_20 = CreateMutexA(0x0, 0x0, 0x0);
    if (esi[0xc] == 0x0) {
            esi[0x4] = 0x0;
    }
    bool_12 = esi[0x4] > 0x0;
    bool_11 = esi[0x4] > 0x0;
    bool_10 = esi[0x4] != 0x0;
    bool_9 = esi[0x4] != 0x0;
    sub_45f920(bool_12 ? 0x1 : 0x0);
    eax = dcsp_configure("aiclient.cfg");
    *eax = 0x1;
    eax[0x4] = 0x0;
    eax[0x5] = 0x1;
    eax[0x6] = 0x1;
    eax[0x6] = sub_45e930;
    eax[0x7] = 0x0;
    eax[0x9] = bool_11 ? 0x1 : 0x0;
    eax[0x28] = esi[0x10];
    eax[0xb] = "tcpip_output.txt";
    eax[0xc] = 0x4c4b40;
    eax[0xd] = 0x4b1973;
    eax[0xe] = 0x4b1973;
    dcsp_start(eax);
    esp = (esp - 0xc) + 0xc;
    arg_1c = bool_10 ? 0x1 : 0x0;
    if (!bool_9) {
            sub_45f930("Failed to start TCP/IP Server", arg_4);
            eax = arg_24;
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    *eax = 0x0;
            }
            eax = arg_1c;
    }
    else {
            if (*(int8_t *)esi == 0x0) {
                    ebx = 0x0;
                    if (esi[0x1] == 0x0) {
                            eax = esi[0x1];
                            edi = esi + 0x4;
                            if ((0x1 - *((eax - 0x10) + 0xc) | *((eax - 0x10) + 0x8) - 0x3e8) < 0x0) {
                                    esp = esp - 0x4;
                                    sub_40b860(0x3e8, arg_4);
                            }
                            ebx = 0x0;
                            esp = esp - 0x8;
                            gethostname(*edi, 0x3e8);
                            ecx = *edi;
                            if (ecx == 0x0) {
                                    if (0x0 <= *(ecx - 0x8)) {
                                            *(ecx - 0xc) = 0x0;
                                            *(int8_t *)(0x0 + *edi) = ebx;
                                            esi[0x1] = 0x1;
                                            if (esi[0x8] == ebx) {
                                                    esi[0x5] = 0x4149;
                                            }
                                            ebx = 0x0;
                                            eax = esi[0x1];
                                            edi = esi + 0x4;
                                            eax = eax - 0x10;
                                            ecx = 0x1 - eax[0x3];
                                            if (esi[0x1] != 0x0) {
                                                    if ((ecx | eax[0x2]) < 0x0) {
                                                            esp = esp - 0x4;
                                                            sub_40b860(ebx, arg_4);
                                                    }
                                                    esp = esp - 0x8;
                                            }
                                            else {
                                                    if ((ecx | eax[0x2]) < 0x0) {
                                                            esp = esp - 0x4;
                                                            sub_40b860(ebx, arg_4);
                                                    }
                                                    esp = esp - 0x8;
                                            }
                                            esp = (esp - 0x4) + 0xc;
                                            if (dcsp_convert_address(*edi) == 0x0) {
                                                    ebx = 0x0;
                                                    arg_4 = *edi;
                                                    sub_45f930("Bad TCP/IP address '%s'", arg_4);
                                                    eax = arg_28;
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax != 0x0) {
                                                            *eax = 0x1;
                                                            eax = 0x0;
                                                    }
                                                    else {
                                                            eax = arg_1c;
                                                    }
                                            }
                                            else {
                                                    dcsp_client_connect();
                                                    (*(*ebp + 0xc))();
                                                    eax = arg_20;
                                            }
                                    }
                                    else {
                                            eax = sub_40b5a0(0x80070057);
                                    }
                            }
                            else {
                                    eax = ecx;
                                    ebp = eax + 0x1;
                                    do {
                                            edx = *(int8_t *)eax;
                                            eax = eax + 0x1;
                                    } while (edx != ebx);
                                    eax = eax - ebp;
                                    if (eax >= 0x0) {
                                            ebp = arg_14;
                                            if (eax <= *(ecx - 0x8)) {
                                                    *(ecx - 0xc) = eax;
                                                    *(int8_t *)(eax + *edi) = ebx;
                                                    esi[0x1] = 0x1;
                                                    if (esi[0x8] == ebx) {
                                                            esi[0x5] = 0x4149;
                                                    }
                                                    eax = esi[0x1];
                                                    edi = esi + 0x4;
                                                    eax = eax - 0x10;
                                                    ecx = 0x1 - eax[0x3];
                                                    if (esi[0x1] != ebx) {
                                                            if ((ecx | eax[0x2]) < 0x0) {
                                                                    esp = esp - 0x4;
                                                                    sub_40b860(0x0, arg_4);
                                                            }
                                                            esp = esp - 0x8;
                                                    }
                                                    else {
                                                            if ((ecx | eax[0x2]) < 0x0) {
                                                                    esp = esp - 0x4;
                                                                    sub_40b860(ebx, arg_4);
                                                            }
                                                            esp = esp - 0x8;
                                                    }
                                                    esp = (esp - 0x4) + 0xc;
                                                    if (dcsp_convert_address(*edi) == 0x0) {
                                                            ebx = 0x0;
                                                            arg_4 = *edi;
                                                            sub_45f930("Bad TCP/IP address '%s'", arg_4);
                                                            eax = arg_28;
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax != 0x0) {
                                                                    *eax = 0x1;
                                                                    eax = ebx;
                                                            }
                                                            else {
                                                                    eax = arg_1c;
                                                            }
                                                    }
                                                    else {
                                                            dcsp_client_connect();
                                                            (*(*ebp + 0xc))();
                                                            eax = arg_20;
                                                    }
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
                            if (esi[0x8] == ebx) {
                                    esi[0x5] = 0x4149;
                            }
                            ebx = 0x0;
                            eax = esi[0x1];
                            edi = esi + 0x4;
                            eax = eax - 0x10;
                            ecx = 0x1 - eax[0x3];
                            if (esi[0x1] != 0x0) {
                                    if ((ecx | eax[0x2]) < 0x0) {
                                            esp = esp - 0x4;
                                            sub_40b860(ebx, arg_4);
                                    }
                                    esp = esp - 0x8;
                            }
                            else {
                                    if ((ecx | eax[0x2]) < 0x0) {
                                            esp = esp - 0x4;
                                            sub_40b860(ebx, arg_4);
                                    }
                                    ebx = 0x0;
                                    esp = esp - 0x8;
                            }
                            esp = (esp - 0x4) + 0xc;
                            if (dcsp_convert_address(*edi) == 0x0) {
                                    arg_4 = *edi;
                                    sub_45f930("Bad TCP/IP address '%s'", arg_4);
                                    eax = arg_28;
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax != ebx) {
                                            *eax = 0x1;
                                            eax = ebx;
                                    }
                                    else {
                                            eax = arg_1c;
                                    }
                            }
                            else {
                                    dcsp_client_connect();
                                    (*(*ebp + 0xc))();
                                    eax = arg_20;
                            }
                    }
            }
            else {
                    if (esi[0x8] == 0x0) {
                            esi[0x5] = 0x4149;
                    }
                    eax = esi[0x1];
                    edi = esi + 0x4;
                    eax = eax - 0x10;
                    ecx = 0x1 - eax[0x3];
                    if (esi[0x1] != 0x0) {
                            if ((ecx | eax[0x2]) < 0x0) {
                                    esp = esp - 0x4;
                                    sub_40b860(0x0, arg_4);
                            }
                            esp = esp - 0x8;
                    }
                    else {
                            if ((ecx | eax[0x2]) < 0x0) {
                                    esp = esp - 0x4;
                                    sub_40b860(0x0, arg_4);
                            }
                            esp = esp - 0x8;
                    }
                    esp = (esp - 0x4) + 0xc;
                    if (dcsp_convert_address(*edi) == 0x0) {
                            ebx = 0x0;
                            arg_4 = *edi;
                            sub_45f930("Bad TCP/IP address '%s'", arg_4);
                            eax = arg_28;
                            esp = (esp - 0x8) + 0x8;
                            if (eax != 0x0) {
                                    *eax = 0x1;
                                    eax = ebx;
                            }
                            else {
                                    eax = arg_1c;
                            }
                    }
                    else {
                            dcsp_client_connect();
                            (*(*ebp + 0xc))();
                            eax = arg_20;
                    }
            }
    }
    return eax;
}
