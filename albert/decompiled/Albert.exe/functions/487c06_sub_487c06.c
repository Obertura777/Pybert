// sub_487c06 @ 0x487c06
// hopper name: sub_487c06
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487c06() {
    eax = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = eax * 0x8 + 0x4c9980;
    if (*esi == 0x0) {
            decomp_var_8 = eax;
            esp = (esp - 0x4) + 0x4;
            if (sub_487b43() == 0x0) {
                    sub_47d856(0x11);
                    esp = (esp - 0x4) + 0x4;
            }
    }
    eax = EnterCriticalSection(*esi);
    return eax;
}
