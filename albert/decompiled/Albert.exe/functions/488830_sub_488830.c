// sub_488830 @ 0x488830
// hopper name: sub_488830
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488830() {
    var_4 = 0x0;
    var_8 = 0x0;
    eax = sub_47d8ff(&var_4);
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0) {
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    eax = sub_47d936(&var_8);
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0) {
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    esp = esp + 0x4;
    if (var_4 == 0x2 && var_8 >= 0x5) {
            eax = 0x1;
    }
    else {
            eax = 0x3;
    }
    return eax;
}
