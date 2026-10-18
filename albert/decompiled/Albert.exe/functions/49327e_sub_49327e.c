// sub_49327e @ 0x49327e
// hopper name: sub_49327e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49327e() {
    if (*(int8_t *)byte_bc7004 == 0x0) {
            *(int8_t *)byte_bc7004 = 0x1;
            sub_4937a3(sub_49324e);
    }
    eax = arg_0;
    *dword_bc6fe0 = eax;
    return eax;
}
