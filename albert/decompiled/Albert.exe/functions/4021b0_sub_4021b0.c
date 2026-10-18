// sub_4021b0 @ 0x4021b0
// hopper name: sub_4021b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4021b0() {
    edx = ecx[0x1];
    eax = edx[0x1];
    esp = esp - 0x8;
    edi = arg_4;
    if (eax[0x11] == 0x0) {
            esi = *edi;
            do {
                    if (esi < eax[0x3]) {
                            edx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x11] == 0x0);
    }
    esi = ecx[0x1];
    eax = esi[0x1];
    if (eax[0x11] == 0x0) {
            edi = *edi;
            do {
                    if (eax[0x3] < edi) {
                            eax = eax[0x2];
                    }
                    else {
                            esi = eax;
                            eax = *eax;
                    }
            } while (eax[0x11] == 0x0);
    }
    eax = arg_10;
    eax[0x1] = esi;
    *eax = ecx;
    eax[0x2] = ecx;
    eax[0x3] = edx;
    return eax;
}
