// sub_45f930 @ 0x45f930
// hopper name: sub_45f930
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f930() {
    if (*dword_bc2128 == 0x0) {
            eax = sub_47bf0b("errorlog.txt", 0x4b0b1c);
            esp = (esp - 0x8) + 0x8;
            *dword_bc2128 = eax;
            if (eax != 0x0) {
                    sub_47c68d(eax, arg_0, &arg_4);
                    sub_47bcf8();
                    eax = sub_47c4e3();
            }
    }
    else {
            sub_47c68d(*dword_bc2128, arg_0, &arg_4);
            sub_47bcf8();
            eax = sub_47c4e3();
    }
    return eax;
}
