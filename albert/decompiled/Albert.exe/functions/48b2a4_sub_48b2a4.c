// sub_48b2a4 @ 0x48b2a4
// hopper name: sub_48b2a4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48b2a4() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    if (esi != 0x0) {
            eax = *esi;
            if (eax != *dword_4c8de4) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            eax = esi[0x1];
            if (eax != *dword_4c8de8) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = esi[0x2];
            if (esi != *dword_4c8dec) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return;
}
