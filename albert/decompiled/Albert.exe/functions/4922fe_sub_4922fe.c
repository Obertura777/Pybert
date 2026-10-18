// sub_4922fe @ 0x4922fe
// hopper name: sub_4922fe
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4922fe() {
    decomp_var_4 = 0x8;
    sub_47f31c(0x4c39f8, 0x8);
    if (*dword_bc8368 != 0x0) {
            if ((arg_4 & 0x40) != 0x0) {
                    if (*dword_4ca0b0 != 0x0) {
                            intrinsic_ldmxcsr(arg_4, 0x0);
                    }
                    else {
                            intrinsic_ldmxcsr(arg_4 & 0xffffffbf, decomp_var_4);
                    }
                    eax = sub_47f361();
            }
            else {
                    intrinsic_ldmxcsr(arg_4 & 0xffffffbf, decomp_var_4);
                    eax = sub_47f361();
            }
    }
    else {
            eax = sub_47f361();
    }
    return eax;
}
