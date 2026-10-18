// sub_45d210 @ 0x45d210
// hopper name: sub_45d210
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d210() {
    var_C = *0x0;
    *0x0 = &var_C;
    sub_465870();
    eax = sub_466060(&var_1C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    sub_45cec0(&var_2C);
    (*(*ecx + 0xb0))(arg_0, arg_4);
    eax = sub_465fa0();
    *0x0 = saved_fp;
    return eax;
}
