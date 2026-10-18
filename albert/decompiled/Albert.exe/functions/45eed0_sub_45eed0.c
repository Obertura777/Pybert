// sub_45eed0 @ 0x45eed0
// hopper name: sub_45eed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45eed0() {
    var_8 = 0x498e48;
    var_C = *0x0;
    decomp_var_30 = esi;
    decomp_var_34 = edi;
    *0x0 = &var_C;
    esi = ecx;
    edi = arg_0;
    eax = sub_466060(&var_2C, 0x1);
    esp = esp - 0x48;
    eax = sub_465900(&arg_0, 0x0);
    if (*(int16_t *)word_4c7070 != *(int16_t *)eax) {
            eax = sub_466060(&var_1C, 0x1);
            esp = esp - 0x10;
            sub_45e9f0(edi, eax);
            sub_465fa0();
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_0, 0x0);
            if (*(int16_t *)word_4c70dc != *(int16_t *)eax) {
                    eax = sub_466060(&var_1C, 0x1);
                    esp = esp - 0x10;
                    (*(*esi + 0x50))(edi, eax);
                    sub_465fa0();
            }
            else {
                    esp = esp - 0x4;
                    (*(*esi + 0xc0))(edi);
            }
    }
    eax = sub_465fa0();
    *0x0 = var_8;
    return eax;
}
