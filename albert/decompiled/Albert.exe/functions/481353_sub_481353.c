// sub_481353 @ 0x481353
// hopper name: sub_481353
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481353() {
    esp = esp - 0x8;
    esi = 0x0;
    while (true) {
            eax = sub_47ccc0(saved_fp, arg_0, arg_4);
            edi = eax;
            esp = (esp - 0xc) + 0xc;
            if (edi != 0x0) {
                    temp_0 = 0x1;
                    break;
            }
            if (arg_10 == eax) {
                    temp_0 = 0x0;
                    break;
            }
            if (*dword_bc684c <= eax) {
                    temp_0 = 0x0;
                    break;
            }
            esp = esp - 0x4;
            Sleep(saved_fp);
            eax = esi + 0x3e8;
            if (eax > *dword_bc684c) {
                    eax = eax | 0xffffffff;
            }
            esi = eax;
            if (eax != 0xffffffff) {
                    continue;
            }
            temp_0 = 0x2;
            break;
    }
    return;
}
