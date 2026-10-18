// sub_45fc30 @ 0x45fc30
// hopper name: sub_45fc30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45fc30() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_4;
    esi[0x2] = 0x0;
    if (sub_4658e0() != 0x0) {
            eax = sub_4658f0(&arg_0);
            *esi = *(int8_t *)eax & 0xff;
            esi[0x2] = arg_8;
            eax = esi;
    }
    else {
            eax = sub_465900(&arg_8, 0x0);
            *esi = *(int8_t *)eax & 0xff;
            eax = sub_465900(&arg_8, 0x1);
            esi[0x2] = *(int16_t *)eax;
            eax = esi;
    }
    return eax;
}
