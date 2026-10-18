// sub_45f990 @ 0x45f990
// hopper name: sub_45f990
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f990() {
    if (*(int8_t *)byte_bc2130 != 0x0) {
            if (*dword_bc212c == 0x0) {
                    eax = sub_47bf0b("tcpiplog.txt", 0x4b0b1c);
                    esp = (esp - 0x8) + 0x8;
                    *dword_bc212c = eax;
                    if (eax != 0x0) {
                            sub_47bcf8();
                            sub_47c4e3();
                    }
            }
            else {
                    sub_47bcf8();
                    sub_47c4e3();
            }
    }
    return;
}
