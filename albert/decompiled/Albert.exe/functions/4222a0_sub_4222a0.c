// sub_4222a0 @ 0x4222a0
// hopper name: sub_4222a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4222a0() {
    var_C = *0x0;
    decomp_var_20 = edi;
    *0x0 = &var_C;
    *(int8_t *)ecx = *(int8_t *)arg_0 & 0xff;
    ecx[0x1] = arg_0;
    ecx[0x2] = arg_4;
    sub_405090(&arg_8);
    sub_41c3c0(&arg_14);
    sub_41c3c0(&arg_20);
    ecx[0xc] = arg_2c;
    ecx[0x21] = arg_80;
    sub_465f60(&arg_84);
    ecx[0x98] = arg_94 & 0xff;
    ecx[0x28] = arg_9c;
    ecx[0x29] = arg_a0;
    sub_465f60(&arg_a4);
    ecx[0x5c] = arg_b4;
    sub_465f60(&arg_b8);
    eax = ecx;
    *0x0 = var_C;
    return eax;
}
