// sub_493590 @ 0x493590
// hopper name: sub_493590
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493590() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    if (esi[0x1] > 0x0) {
            eax = esi[0x1];
            eax[0xbc703c] = eax[0xbc703c] - 0x1;
            if (*(int8_t *)(esi[0x1] + 0xbc703c) <= 0x0) {
                    sub_49354a(esi);
                    esi = esi[0x9];
                    esp = (esp - 0x4) + 0x4;
                    if (esi != 0x0) {
                            sub_465790();
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
            }
    }
    else {
            sub_49354a(esi);
            esi = esi[0x9];
            esp = (esp - 0x4) + 0x4;
            if (esi != 0x0) {
                    sub_465790();
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return;
}
