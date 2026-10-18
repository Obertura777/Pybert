// sub_46e4ea @ 0x46e4ea
// hopper name: sub_46e4ea
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e4ea() {
    esi = ecx;
    eax = esi[0x1d];
    esp = esp - 0x4;
    if (eax != 0x0) {
            eax = GlobalLock(eax);
            esp = esp - 0x10;
            eax = lstrcmpA((eax[0x1] & 0xffff) + eax, arg_0);
            if (eax == 0x0) {
                    esp = esp - 0xc;
                    eax = OpenPrinterA(arg_0, &var_4, 0x0);
                    if (eax != 0x0) {
                            edi = 0x0;
                            eax = esi[0x1c];
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    sub_477dfa(eax);
                            }
                            eax = DocumentPropertiesA(edi, var_4, arg_0, edi, edi, edi);
                            eax = GlobalAlloc(0x42, eax);
                            esi[0x1c] = eax;
                            eax = GlobalLock(eax);
                            decomp_var_44 = var_4;
                            esp = esp - 0x3c;
                            decomp_var_48 = edi;
                            if (DocumentPropertiesA(decomp_var_48, decomp_var_44, arg_0, eax, edi, 0x2) != 0x1) {
                                    esp = esp - 0x4;
                                    sub_477dfa(esi[0x1c]);
                                    esi[0x1c] = edi;
                            }
                            esp = esp - 0x4;
                            decomp_var_4c = var_4;
                            eax = ClosePrinter(decomp_var_4c);
                    }
            }
            esp = esp + 0x4;
    }
    return eax;
}
