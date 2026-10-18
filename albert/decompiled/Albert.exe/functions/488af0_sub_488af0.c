// sub_488af0 @ 0x488af0
// hopper name: sub_488af0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488af0() {
    ecx = arg_0;
    if (*(int16_t *)ecx != 0x5a4d) {
            eax = 0x0;
    }
    else {
            eax = ecx[0xf];
            eax = eax + ecx;
            if (*eax == 0x4550) {
                    eax = eax[0xc] == 0x10b ? 0x1 : 0x0;
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
