// sub_45fca0 @ 0x45fca0
// hopper name: sub_45fca0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45fca0() {
    var_C = *0x0;
    decomp_var_24 = ebx;
    esp = esp - 0x30;
    *0x0 = &var_C;
    edi = ecx;
    esi = arg_0;
    sub_465870();
    var_20 = 0x1;
    if (arg_9 == 0x46) {
            eax = sub_466540(&var_1C, &arg_8);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            sub_465aa0();
    }
    else {
            sub_465f30(edi + (arg_4 + arg_4 * 0x8) * 0x4);
            esp = esp - 0x8;
            eax = sub_465ff0(&var_1C);
            sub_465fa0();
    }
    eax = esi;
    *0x0 = saved_fp;
    return eax;
}
