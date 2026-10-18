// sub_402210 @ 0x402210
// hopper name: sub_402210
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402210() {
    decomp_var_4 = ebx;
    eax = arg_0[0x1];
    decomp_var_8 = esi;
    decomp_var_c = edi;
    esi = ecx;
    edi = esi[0x1];
    esp = esp - 0x14;
    edi[0x1] = sub_401d70(eax[0x1], edi);
    ecx = arg_0[0x2];
    edx = esi[0x1];
    esi[0x2] = ecx;
    eax = edx[0x1];
    if (eax[0x11] == 0x0) {
            ecx = *eax;
            if (ecx[0x11] == 0x0) {
                    do {
                            eax = ecx;
                            ecx = *eax;
                    } while (ecx[0x11] == 0x0);
            }
            *edx = eax;
            esi = esi[0x1];
            ecx = esi[0x1];
            eax = ecx[0x2];
            if (eax[0x11] == 0x0) {
                    ecx = eax;
                    eax = ecx[0x2];
                    if (eax[0x11] == 0x0) {
                            continue;
                    }
                    break;
            }
            esi[0x2] = ecx;
    }
    else {
            *edx = edx;
            esi = esi[0x1];
            esi[0x2] = esi;
    }
    return eax;
}
