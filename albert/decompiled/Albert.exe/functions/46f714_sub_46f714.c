// sub_46f714 @ 0x46f714
// hopper name: sub_46f714
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f714() {
    ecx = *(sub_4715ed() + 0x4);
    if (ecx != 0x0) {
            eax = *ecx;
            eax = (eax[0x17])();
    }
    else {
            decomp_var_4 = esi;
            decomp_var_8 = edi;
            edi = sub_471099();
            esi = edi + 0x30;
            esp = esp - 0x18;
            eax = GetMessageA(esi, 0x0, 0x0, 0x0);
            if (eax != 0x0) {
                    if (edi[0xd] != 0x36a) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_46f5a7(esi) == 0x0) {
                                    TranslateMessage(esi);
                                    esp = esp - 0x8;
                                    DispatchMessageA(esi);
                            }
                    }
                    eax = 0x1;
            }
    }
    return eax;
}
