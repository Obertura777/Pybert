// sub_40a9f0 @ 0x40a9f0
// hopper name: sub_40a9f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40a9f0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    esp = esp - 0x20;
    decomp_var_20 = edi;
    esi = ecx;
    edi = 0x0;
    var_C = esi;
    var_10 = 0x0;
    if (esi[0x901] > 0x0) {
            ebx = esi + 0x2468;
            do {
                    esp = esp - 0x4;
                    eax = sub_409de0(&var_10, decomp_var_20);
                    if (eax[0x14] != 0x0) {
                            edx = eax[0x2];
                            ebp = eax[0x3];
                            ecx = eax[0x4];
                            if (ebp + edx < ecx) {
                                    eax[0x3] = ecx - edx;
                            }
                    }
                    else {
                            if (eax[0x2] < eax[0x4]) {
                                    esp = esp - 0x8;
                                    sub_409ad0(edi, eax);
                            }
                    }
                    edi = edi + 0x1;
                    var_10 = edi;
            } while (edi < esi[0x901]);
    }
    var_10 = 0x0;
    if (esi[0x901] > 0x0) {
            eax = sub_409de0(&var_10, decomp_var_20);
            sub_40aaa0(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, var_10, var_C, eax);
    }
    else {
            &var_10 = decomp_var_18;
    }
    return;
}
