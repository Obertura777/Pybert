// sub_467490 @ 0x467490
// hopper name: sub_467490
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467490() {
    var_C = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    decomp_var_24 = *dword_4c8db8 ^ &decomp_var_20;
    *0x0 = &var_C;
    esi = ecx;
    sub_49337f(esi);
    esp = (esp - 0x28) + 0x4;
    if (esi[0x1c] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x1c] = 0xf;
    esi[0x1b] = 0x0;
    esi[0x5c] = 0x0;
    if (esi[0x15] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x15] = 0xf;
    esi[0x14] = 0x0;
    esi[0x40] = 0x0;
    if (esi[0xe] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0xe] = 0xf;
    esi[0xd] = 0x0;
    esi[0x24] = 0x0;
    if (esi[0x7] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x7] = 0xf;
    esi[0x6] = 0x0;
    esi[0x8] = 0x0;
    eax = sub_49320b();
    *0x0 = var_C;
    return eax;
}
