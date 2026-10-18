// sub_48b4ac @ 0x48b4ac
// hopper name: sub_48b4ac
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48b4ac() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    if (esi != 0x0) {
            eax = esi[0x3];
            if (eax != *dword_4c8df0) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x4];
            if (eax != *dword_4c8df4) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x5];
            if (eax != *dword_4c8df8) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x6];
            if (eax != *dword_4c8dfc) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x7];
            if (eax != *dword_4c8e00) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x8];
            if (eax != *dword_4c8e04) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = esi[0x9];
            if (esi != *dword_4c8e08) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return;
}
