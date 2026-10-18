// sub_4779bd @ 0x4779bd
// hopper name: sub_4779bd
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4779bd() {
    esi = arg_0;
    ebx = 0x1;
    esp = esp - 0x8;
    edi = ecx;
    var_4 = 0x1;
    if (esi[0x2] > 0x1) {
            do {
                    eax = arg_4;
                    if (eax == 0x0) {
                            ecx = *(esi[0x3] + ebx * 0x4);
                            if (ecx != 0x0) {
                                    esp = esp - 0x4;
                                    (**ecx)(0x1);
                            }
                            eax = esi[0x3];
                            *(eax + ebx * 0x4) = *(eax + ebx * 0x4) & 0x0;
                            ebx = ebx + 0x1;
                            if (ebx < esi[0x2]) {
                                    continue;
                            }
                            break;
                    }
                    if (*(edi[0x4] + ebx * 0x8 + 0x4) == eax) {
                            ecx = *(esi[0x3] + ebx * 0x4);
                            if (ecx != 0x0) {
                                    esp = esp - 0x4;
                                    (**ecx)(0x1);
                            }
                            eax = esi[0x3];
                            *(eax + ebx * 0x4) = *(eax + ebx * 0x4) & 0x0;
                            ebx = ebx + 0x1;
                            if (ebx < esi[0x2]) {
                                    continue;
                            }
                            break;
                    }
                    eax = esi[0x3];
                    if (*(eax + ebx * 0x4) != 0x0) {
                            var_4 = var_4 & 0x0;
                    }
                    ebx = ebx + 0x1;
            } while (ebx < esi[0x2]);
            if (var_4 != 0x0) {
                    EnterCriticalSection(edi + 0x1c);
                    sub_47765a(esi);
                    LeaveCriticalSection(edi + 0x1c);
                    LocalFree(esi[0x3]);
                    (**esi)(0x1);
                    esp = esp - 0x1c;
                    eax = TlsSetValue(*edi, 0x0);
            }
    }
    else {
            EnterCriticalSection(edi + 0x1c);
            sub_47765a(esi);
            LeaveCriticalSection(edi + 0x1c);
            LocalFree(esi[0x3]);
            (**esi)(0x1);
            esp = esp - 0x1c;
            eax = TlsSetValue(*edi, 0x0);
    }
    return eax;
}
