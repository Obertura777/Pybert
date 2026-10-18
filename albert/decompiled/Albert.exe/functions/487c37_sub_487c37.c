// sub_487c37 @ 0x487c37
// hopper name: sub_487c37
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487c37() {
    sub_47aea2(arg_4);
    eax = *(int16_t *)(var_10[0x32] + (arg_0 & 0xff) * 0x2) & 0xffff;
    eax = eax & 0x8000;
    if (var_4 != 0x0) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    return eax;
}
