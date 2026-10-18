// sub_467ca0 @ 0x467ca0
// hopper name: sub_467ca0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467ca0() {
    esp = esp - 0x4;
    esi = ecx;
    eax = esi[0x5];
    bool_1 = eax >= 0x0;
    *esi = 0x4b1cfc;
    if (eax > 0x0) {
            esp = esp - 0x4;
            sub_47c8f9();
            esp = esp + 0x4;
    }
    else {
            if (!bool_1) {
                    esp = esp - 0x4;
                    sub_47c8f9();
                    esp = esp + 0x4;
            }
    }
    *esi = 0x4b1c34;
    if ((arg_4 & 0x1) != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi;
    return eax;
}
