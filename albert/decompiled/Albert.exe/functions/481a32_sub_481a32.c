// sub_481a32 @ 0x481a32
// hopper name: sub_481a32
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481a32() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_0;
    eax = esi[0x2f];
    esp = esp - 0x10;
    decomp_var_10 = edi;
    if (eax != 0x0 && eax != dword_4c8de4) {
            eax = esi[0x2c];
            if (eax != 0x0) {
                    ebp = 0x0;
                    if (*eax == 0x0) {
                            eax = esi[0x2e];
                            if (eax != ebp && *eax == ebp) {
                                    sub_47c8f9();
                                    sub_48b4ac(esi[0x2f]);
                                    esp = (esp - 0x8) + 0x8;
                            }
                            eax = esi[0x2d];
                            if (eax != ebp && *eax == ebp) {
                                    sub_47c8f9();
                                    sub_48b2a4(esi[0x2f]);
                                    esp = (esp - 0x8) + 0x8;
                            }
                            decomp_var_14 = esi[0x2c];
                            sub_47c8f9();
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x8;
                    }
            }
    }
    eax = esi[0x30];
    if (eax != 0x0 && *eax == 0x0) {
            decomp_var_14 = esi[0x31] - 0xfe;
            sub_47c8f9();
            sub_47c8f9();
            sub_47c8f9();
            sub_47c8f9();
            esp = (esp - 0x10) + 0x10;
    }
    edi = esi + 0xd4;
    eax = *edi;
    if (eax != 0x4c9d28 && eax[0x2d] == 0x0) {
            sub_48b0a1(eax);
            sub_47c8f9();
            esp = (esp - 0x8) + 0x8;
    }
    edi = esi + 0x50;
    ebx = 0x6;
    esp = (esp - 0x4) + 0x4;
    goto loc_481b2f;

loc_481b2f:
    if (*(edi - 0x8) != 0x4c9518) {
            ebp = 0x0;
            eax = *edi;
            if (eax != 0x0 && *eax == ebp) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    ebp = 0x0;
    if (*(edi - 0x4) != 0x0) {
            eax = edi[0x1];
            if (eax != ebp && *eax == ebp) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    edi = edi + 0x10;
    ebx = ebx - 0x1;
    if (ebx != 0x0) {
            continue;
    }
    break;
    sub_47c8f9();
    return;
}
