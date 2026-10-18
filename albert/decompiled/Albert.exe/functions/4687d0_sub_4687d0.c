// sub_4687d0 @ 0x4687d0
// hopper name: sub_4687d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4687d0() {
    var_C = *0x0;
    *0x0 = &var_C;
    edi = sub_47d2f9();
    ecx[0x2] = 0x0;
    ecx[0x4] = 0x0;
    ecx[0x5] = 0x0;
    sub_49317e();
    ecx[0x2] = sub_468780(edi[0x2]);
    sub_49317e();
    ecx[0x4] = sub_468780("false");
    sub_49317e();
    ecx[0x5] = sub_468780("true");
    sub_49317e();
    ecx[0xc] = *(int8_t *)*edi;
    sub_49317e();
    eax = edi[0x1];
    ecx[0xd] = *(int8_t *)eax;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
