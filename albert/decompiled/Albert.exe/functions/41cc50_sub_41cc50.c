// sub_41cc50 @ 0x41cc50
// hopper name: sub_41cc50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41cc50() {
    var_C = *0x0;
    *0x0 = &var_C;
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = ecx[0xa];
    sub_419cb0(&var_14, ecx + 0x24, *eax, ecx + 0x24, eax);
    sub_47c8f9();
    *(ecx + 0x28) = 0x0;
    *(ecx + 0x2c) = 0x0;
    eax = ecx[0x7];
    sub_419cb0(&var_14, ecx + 0x18, *eax, ecx + 0x18, eax);
    sub_47c8f9();
    *(ecx + 0x1c) = 0x0;
    *(ecx + 0x20) = 0x0;
    eax = ecx[0x4];
    sub_403430(&var_14, ecx + 0xc, *eax, ecx + 0xc, eax);
    eax = sub_47c8f9();
    *(ecx + 0x10) = 0x0;
    *(ecx + 0x14) = 0x0;
    *0x0 = var_C;
    return eax;
}
