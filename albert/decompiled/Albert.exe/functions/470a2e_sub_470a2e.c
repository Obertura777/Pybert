// sub_470a2e @ 0x470a2e
// hopper name: sub_470a2e
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470a2e() {
    esp = esp - 0x4;
    decomp_var_4 = 0x24;
    sub_47d6ee(0x24);
    esi = ecx;
    decomp_var_1c = esi[0x18];
    decomp_var_18 = esi[0x17];
    eax = sub_4715ba();
    edi = eax[0x3];
    if (esi[0x16] != 0x0) {
            edi = *(sub_4715ba() + 0xc);
            eax = FindResourceA(edi, esi[0x16], 0x5);
            esp = esp - 0x14;
            eax = LoadResource(edi, eax);
            decomp_var_18 = eax;
    }
    if (decomp_var_18 != 0x0) {
            esp = esp - 0x4;
            eax = LockResource(decomp_var_18);
            decomp_var_1c = eax;
    }
    if (decomp_var_1c != 0x0) {
            ebx = 0x0;
            decomp_var_14 = sub_470566();
            sub_473b96();
            decomp_var_28 = decomp_var_28 & 0x0;
            decomp_var_2c = 0x0;
            if (decomp_var_14 != 0x0 && decomp_var_14 != GetDesktopWindow()) {
                    esp = esp - 0x4;
                    if (IsWindowEnabled(decomp_var_14) != 0x0) {
                            esp = esp - 0x8;
                            EnableWindow(decomp_var_14, 0x0);
                            decomp_var_2c = 0x1;
                            ebx = sub_46e5d5();
                            if (ebx != 0x0 && (*(*ebx + 0x120))() != 0x0) {
                                    if (sub_47679a() != 0x0) {
                                            esp = esp - 0x4;
                                            sub_4767b5(0x0);
                                            decomp_var_28 = 0x1;
                                    }
                            }
                    }
            }
            decomp_var_4 = decomp_var_4 & 0x0;
            decomp_var_8 = esi;
            sub_47550c();
            sub_473aee(decomp_var_14);
            esp = esp - 0x14;
            decomp_var_14 = decomp_var_1c;
            if (sub_47083e() != 0x0) {
                    if ((esi[0x3c] & 0x10) != 0x0) {
                            edi = 0x4;
                            esp = (esp - 0x4) + 0x4;
                            if ((sub_476745() & 0x100) != 0x0) {
                                    edi = 0x5;
                                    esp = (esp - 0x4) + 0x4;
                            }
                            esp = esp - 0x4;
                            sub_473684(edi, decomp_var_8);
                    }
                    if (esi[0x8] != 0x0) {
                            decomp_var_14 = 0x0;
                            decomp_var_18 = 0x0;
                            esp = esp - 0x18;
                            sub_47681c(0x0, 0x0, 0x0, 0x0, 0x0, 0x97);
                    }
            }
            if (decomp_var_28 != 0x0) {
                    esp = esp - 0x4;
                    sub_4767b5(0x1);
            }
            if (decomp_var_2c != 0x0) {
                    esp = esp - 0x8;
                    EnableWindow(decomp_var_14, 0x1);
            }
            if (decomp_var_14 != 0x0 && GetActiveWindow() == esi[0x8]) {
                    esp = esp - 0x4;
                    SetActiveWindow(decomp_var_14);
            }
            (*(*esi + 0x60))();
            sub_4705a0();
            if (esi[0x16] != 0x0) {
                    FreeResource(decomp_var_18);
            }
    }
    eax = sub_47d75a();
    return eax;
}
