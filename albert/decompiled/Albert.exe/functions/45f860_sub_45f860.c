// sub_45f860 @ 0x45f860
// hopper name: sub_45f860
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f860() {
    decomp_var_10 = ebp;
    esi = ecx;
    esp = esp - 0x1c;
    WaitForSingleObject(esi[0x9], 0xffffffff);
    if (esi[0x8] != 0x0) {
            decomp_var_10 = ebx;
            esp = esp - 0x8;
            decomp_var_14 = edi;
            do {
                    ecx = esi[0x7];
                    edi = *ecx;
                    if (edi == ecx) {
                            sub_47a948();
                    }
                    ecx = esi[0x7];
                    ebx = edi[0x2];
                    edi = *ecx;
                    var_4 = ebx;
                    if (edi == ecx) {
                            sub_47a948();
                    }
                    if (edi != esi[0x7]) {
                            *edi[0x1] = *edi;
                            *(*edi + 0x4) = edi[0x1];
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            esi[0x8] = esi[0x8] - 0x1;
                    }
                    ReleaseMutex(esi[0x9]);
                    sub_45f670(&var_4);
                    sub_47c8f9();
                    decomp_var_18 = 0xffffffff;
                    esp = (esp - 0xc) + 0x4 - 0x8;
                    WaitForSingleObject(esi[0x9], 0xffffffff);
            } while (esi[0x8] != 0x0);
            esp = esp + 0x8;
    }
    eax = esi[0x9];
    eax = ReleaseMutex(eax);
    return eax;
}
