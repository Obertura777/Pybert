// sub_4223c0 @ 0x4223c0
// hopper name: sub_4223c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4223c0() {
    var_C = *0x0;
    decomp_var_18 = edi;
    *0x0 = &var_C;
    *(int8_t *)ecx = *(int8_t *)arg_0;
    ecx[0x2] = arg_0[0x2];
    ecx[0x3] = arg_0[0x3];
    sub_405090(arg_0 + 0x10);
    sub_405090(arg_0 + 0x1c);
    sub_405090(arg_0 + 0x28);
    sub_41c3c0(arg_0 + 0x34);
    eax = ecx;
    *0x0 = var_C;
    return eax;
}
