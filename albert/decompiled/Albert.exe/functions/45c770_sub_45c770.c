// sub_45c770 @ 0x45c770
// hopper name: sub_45c770
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45c770() {
    var_8 = 0x498828;
    var_C = *0x0;
    eax = *dword_4c8db8;
    *0x0 = &var_C;
    esp = esp - 0x30;
    eax = sub_46b050(&var_28, eax ^ &var_28, var_28);
    var_4 = 0x0;
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_45f930("REJ( DRW() ) message received : %s", eax);
    esp = (esp - 0x8) + 0x8;
    if (var_8 >= 0x10) {
            eax = sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_4;
    return eax;
}
