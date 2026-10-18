// PhaseHandler @ 0x40df20
// hopper name: sub_40df20
// pybert name: PhaseHandler
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

PhaseHandler() {
    esp = esp - 0xc;
    eax = ecx[0x2];
    eax = eax[0x901];
    edx = 0x0;
    var_C = 0x0;
    if (eax > 0x0) {
            decomp_var_10 = ebx;
            decomp_var_14 = ebp;
            decomp_var_18 = esi;
            esp = esp - 0x10;
            decomp_var_1c = edi;
            edi = 0x634e90;
            esi = 0x4d5528;
            var_4 = 0x634e90;
            var_8 = 0x4d5528;
            do {
                    ebx = 0x0;
                    if (eax > 0x0) {
                            eax = (edx + arg_0 * 0x15) * 0xa8 + 0x62e4b8;
                            edx = (edx + arg_0 * 0x15) * 0x54 + 0x631bd8;
                            do {
                                    *edx = *edi;
                                    *eax = *esi;
                                    eax[0x1] = esi[0x1];
                                    ebx = ebx + 0x1;
                                    edi = edi + 0x4;
                                    edx = edx + 0x4;
                                    esi = esi + 0x8;
                                    eax = eax + 0x8;
                            } while (ebx < arg_2400);
                            edx = var_C;
                    }
                    eax = ecx[0x2];
                    eax = eax[0x901];
                    edx = edx + 0x1;
                    esi = var_8 + 0xa8;
                    edi = var_4 + 0x54;
                    var_C = edx;
                    var_8 = esi;
                    var_4 = edi;
            } while (edx < eax);
            esp = esp + 0x10;
    }
    return eax;
}
