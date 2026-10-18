// sub_45d180 @ 0x45d180
// hopper name: sub_45d180
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d180() {
    var_C = *0x0;
    *0x0 = &var_C;
    edi = arg_0;
    sub_466060(&var_1C, 0x1);
    eax = sub_4658f0(&var_1E);
    arg_0 = *(int16_t *)eax;
    sub_465fa0();
    sub_45cd40(&arg_0);
    eax = *(*ecx + 0x30);
    eax = (eax)(edi);
    *0x0 = saved_fp;
    return eax;
}
