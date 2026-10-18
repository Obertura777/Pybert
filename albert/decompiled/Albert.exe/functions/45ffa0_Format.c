// Format @ 0x45ffa0
// hopper name: sub_45ffa0
// pybert name: Format
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

Format() {
    var_C = *0x0;
    *0x0 = &var_C;
    sub_465870();
    decomp_var_60 = *arg_4;
    eax = sub_45fca0(&var_1C, decomp_var_60, arg_4[0x2]);
    ebp = eax;
    decomp_var_5c = arg_4 + 0xc;
    sub_466540(&var_2C, decomp_var_5c);
    eax = sub_466330(&var_3C, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465aa0();
    eax = arg_0;
    *0x0 = var_C;
    return eax;
}
