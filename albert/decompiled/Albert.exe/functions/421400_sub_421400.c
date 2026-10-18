// sub_421400 @ 0x421400
// hopper name: sub_421400
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_421400() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = ecx[0xe];
    sub_419cb0(&var_14, ecx + 0x34, *eax, ecx + 0x34, eax);
    sub_47c8f9();
    *(ecx + 0x38) = 0x0;
    *(ecx + 0x3c) = 0x0;
    eax = ecx[0xb];
    sub_403430(&var_14, ecx + 0x28, *eax, ecx + 0x28, eax);
    sub_47c8f9();
    *(ecx + 0x2c) = 0x0;
    *(ecx + 0x30) = 0x0;
    eax = ecx[0x8];
    sub_403430(&var_14, ecx + 0x1c, *eax, ecx + 0x1c, eax);
    sub_47c8f9();
    *(ecx + 0x20) = 0x0;
    *(ecx + 0x24) = 0x0;
    eax = ecx[0x5];
    sub_403430(&var_14, ecx + 0x10, *eax, ecx + 0x10, eax);
    eax = sub_47c8f9();
    *(ecx + 0x14) = 0x0;
    *(ecx + 0x18) = 0x0;
    *0x0 = var_C;
    return eax;
}
