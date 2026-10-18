// sub_48fefd @ 0x48fefd
// hopper name: sub_48fefd
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fefd() {
    eax = arg_0;
    if (arg_c == 0xa && eax < 0x0) {
            decomp_var_4 = 0x1;
            esp = esp - 0x8;
            decomp_var_8 = 0xa;
    }
    else {
            decomp_var_4 = 0x0;
            esp = esp - 0x8;
            decomp_var_8 = arg_c;
    }
    eax = sub_48fe22(arg_8, decomp_var_8, decomp_var_4);
    return eax;
}
