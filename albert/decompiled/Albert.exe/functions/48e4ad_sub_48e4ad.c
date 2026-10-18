// sub_48e4ad @ 0x48e4ad
// hopper name: sub_48e4ad
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e4ad() {
    esp = esp - 0x8;
    sub_47f31c(0x4c3970, 0xc);
    edi = arg_4;
    esi = (edi & 0x1f) * 0x28 + *((SAR(edi, 0x5)) * 0x4 + dword_bc7240);
    decomp_var_1c = 0x1;
    if (esi[0x2] == 0x0) {
            sub_487c06(0xa);
            esp = (esp - 0x4) + 0x4;
            if (esi[0x2] == 0x0) {
                    esp = (esp - 0x8) + 0x8;
                    if (sub_489876() == 0x0) {
                            decomp_var_1c = 0x0;
                    }
                    esi[0x2] = esi[0x2] + 0x1;
            }
            sub_48e544();
    }
    if (decomp_var_1c != 0x0) {
            EnterCriticalSection(*((SAR(edi, 0x5)) * 0x4 + dword_bc7240) + (edi & 0x1f) * 0x28 + 0xc);
    }
    eax = sub_47f361();
    return eax;
}
