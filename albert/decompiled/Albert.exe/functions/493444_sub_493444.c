// sub_493444 @ 0x493444
// hopper name: sub_493444
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493444() {
    esp = esp - 0x4;
    decomp_var_4 = 0x8;
    sub_47d6bb(0x8);
    eax = *dword_bc6fe0;
    esi = eax;
    if (eax == 0x0) {
            esp = esp - 0x4;
            sub_4931ea(*dword_bc6fe0);
            eax = *dword_bc6fe0;
            decomp_var_4 = decomp_var_4 & esi;
            esi = eax;
            if (eax == 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_46dbce(0x34) != 0x0) {
                            esp = esp - 0x4;
                            esi = sub_4933a2();
                    }
                    else {
                            esi = 0x0;
                    }
                    decomp_var_4 = 0x0;
                    sub_49327e(esi);
                    esi[0x4] = 0x3f;
                    sub_402900(0x4b1d28);
                    *dword_bc6fe4 = esi;
                    sub_465710();
                    *dword_bc6ffc = *dword_bc6fe4;
            }
            sub_49320b();
    }
    eax = sub_47d75a();
    return eax;
}
