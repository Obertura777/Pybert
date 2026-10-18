// sub_478a06 @ 0x478a06
// hopper name: sub_478a06
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478a06() {
    ebx = arg_8;
    esp = esp - 0x4;
    decomp_var_c = esi;
    esi = ecx;
    if (ebx != 0x0 && arg_4 != 0x0) {
            if ((!esi[0x6] & 0x1) == 0x0) {
                    sub_478ca7();
            }
            ecx = esi[0xa];
            eax = esi[0xb];
            eax = eax - ecx;
            esp = esp - 0x4;
            decomp_var_10 = edi;
            edi = ebx;
            if (ebx >= eax) {
                    edi = eax;
            }
            sub_46dc09(ecx, eax, arg_4, edi);
            esi[0xa] = esi[0xa] + edi;
            arg_4 = arg_4 + edi;
            esp = (esp - 0x10) + 0x10;
            ebx = ebx - edi;
            if (ebx != 0x0) {
                    sub_4786e7();
                    temp_1 = ebx % esi[0x8];
                    esp = esp - 0x8;
                    (*(*esi[0x9] + 0x38))(arg_4, ebx - temp_1);
                    arg_4 = arg_4 + (ebx - temp_1);
                    ebx = (ebx - ebx) + temp_1;
                    if (esi[0x2] != 0x0) {
                            esp = esp - 0x10;
                            (*(*esi[0x9] + 0x50))(0x1, esi[0x8], esi + 0x30, esi + 0x2c);
                            esi[0xa] = esi[0xc];
                    }
                    if (ebx >= esi[0x8]) {
                            sub_46dedc();
                    }
                    eax = esi[0xa];
                    if (eax != esi[0xc]) {
                            sub_46dedc();
                    }
                    sub_46dc09(eax, ebx, arg_4, ebx);
                    esp = (esp - 0x10) + 0x10;
                    esi[0xa] = esi[0xa] + ebx;
                    esp = esp + 0x4;
            }
            else {
                    esp = esp + 0x4;
            }
    }
    return;
}
