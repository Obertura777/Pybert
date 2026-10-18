// sub_477872 @ 0x477872
// hopper name: sub_477872
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477872() {
    sub_47d6ee(0x10);
    edi = ecx;
    decomp_var_18 = edi;
    esi = edi + 0x1c;
    esp = esp - 0x8;
    decomp_var_14 = esi;
    EnterCriticalSection(esi);
    eax = arg_4;
    if (eax > 0x0) {
            if (eax < edi[0x3]) {
                    esp = esp - 0x4;
                    decomp_var_4 = *edi;
                    esi = TlsGetValue(decomp_var_4);
                    if (esi != 0x0) {
                            ecx = arg_4;
                            if (ecx >= esi[0x2]) {
                                    if (arg_8 != 0x0) {
                                            ebx = 0x0;
                                            if (esi[0x3] == 0x0) {
                                                    ebx = 0x0;
                                                    eax = sub_4656f0(edi[0x3], 0x4);
                                                    esp = (esp - 0x8) + 0x8 - 0x8;
                                                    eax = LocalAlloc(0x0, eax);
                                            }
                                            else {
                                                    eax = sub_4656f0(edi[0x3], 0x4, 0x2);
                                                    esp = (esp - 0xc) + 0x8 - 0x8;
                                                    eax = LocalReAlloc(esi[0x3], eax, decomp_var_4);
                                            }
                                            if (eax == ebx) {
                                                    LeaveCriticalSection(decomp_var_14);
                                                    sub_46dea8();
                                            }
                                            ebx = 0x0;
                                            ecx = esi[0x2];
                                            esi[0x3] = eax;
                                            decomp_var_14 = eax + ecx * 0x4;
                                            sub_47ba40(decomp_var_14, 0x0, edi[0x3] - ecx << 0x2);
                                            esi[0x2] = edi[0x3];
                                            esp = (esp - 0xc) + 0xc - 0x8;
                                            TlsSetValue(*edi, esi);
                                            ecx = arg_4;
                                            eax = esi[0x3];
                                            if (eax != ebx && ecx < esi[0x2]) {
                                                    *(eax + ecx * 0x4) = arg_8;
                                            }
                                            decomp_var_18 = decomp_var_14;
                                            LeaveCriticalSection(decomp_var_18);
                                            sub_47d75a();
                                    }
                                    else {
                                            eax = esi[0x3];
                                            if (eax != 0x0 && ecx < esi[0x2]) {
                                                    *(eax + ecx * 0x4) = arg_8;
                                            }
                                            decomp_var_18 = decomp_var_14;
                                            LeaveCriticalSection(decomp_var_18);
                                            sub_47d75a();
                                    }
                            }
                            else {
                                    eax = esi[0x3];
                                    if (eax != 0x0 && ecx < esi[0x2]) {
                                            *(eax + ecx * 0x4) = arg_8;
                                    }
                                    decomp_var_18 = decomp_var_14;
                                    LeaveCriticalSection(decomp_var_18);
                                    sub_47d75a();
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_4 = 0x0;
                            eax = sub_477525();
                            if (eax != 0x0) {
                                    *eax = 0x4b3778;
                                    esi = eax;
                            }
                            else {
                                    esi = 0x0;
                            }
                            decomp_var_4 = decomp_var_4 | 0xffffffff;
                            esp = esp - 0x4;
                            esi[0x2] = 0x0;
                            esi[0x3] = 0x0;
                            sub_477641(esi);
                            if (esi[0x3] == 0x0) {
                                    eax = sub_4656f0(edi[0x3], 0x4);
                                    esp = (esp - 0x8) + 0x8 - 0x8;
                                    eax = LocalAlloc(0x0, eax);
                            }
                            else {
                                    eax = sub_4656f0(edi[0x3], 0x4, 0x2);
                                    esp = (esp - 0xc) + 0x8 - 0x8;
                                    eax = LocalReAlloc(esi[0x3], eax, decomp_var_4);
                            }
                            if (eax == 0x0) {
                                    LeaveCriticalSection(decomp_var_14);
                                    sub_46dea8();
                            }
                            ecx = esi[0x2];
                            esi[0x3] = eax;
                            decomp_var_14 = eax + ecx * 0x4;
                            sub_47ba40(decomp_var_14, 0x0, edi[0x3] - ecx << 0x2);
                            esi[0x2] = edi[0x3];
                            esp = (esp - 0xc) + 0xc - 0x8;
                            TlsSetValue(*edi, esi);
                            ecx = arg_4;
                            eax = esi[0x3];
                            if (eax != 0x0 && ecx < esi[0x2]) {
                                    *(eax + ecx * 0x4) = arg_8;
                            }
                            decomp_var_18 = decomp_var_14;
                            LeaveCriticalSection(decomp_var_18);
                            sub_47d75a();
                    }
            }
            else {
                    LeaveCriticalSection(decomp_var_18);
                    sub_47d75a();
            }
    }
    else {
            LeaveCriticalSection(decomp_var_18);
            sub_47d75a();
    }
    return;
}
