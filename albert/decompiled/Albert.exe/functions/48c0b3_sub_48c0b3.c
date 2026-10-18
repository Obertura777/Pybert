// sub_48c0b3 @ 0x48c0b3
// hopper name: sub_48c0b3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c0b3() {
    eax = sub_47d630(*esi);
    decomp_var_8 = esi[0x1];
    bool_1 = true;
    esi[0x4] = (-(eax - 0x3) - -(eax - 0x3) + CARRY(EFLAGS(cf))) + 0x1;
    eax = sub_47d630(decomp_var_8);
    esi[0x6] = esi[0x6] & 0x0;
    bool_0 = esi[0x4] == 0x0;
    esp = (esp - 0x8) + 0x8;
    esi[0x5] = (-(eax - 0x3) - -(eax - 0x3) + CARRY(EFLAGS(cf))) + 0x1;
    if (!bool_0) {
            eax = 0x2;
            esp = (esp - 0x4) + 0x4;
    }
    else {
            eax = sub_48bd01();
    }
    esi[0x3] = eax;
    EnumSystemLocalesA(sub_48be24, 0x1);
    eax = esi[0x2];
    if ((eax & 0x100) != 0x0) {
            if ((eax & 0x200) != 0x0) {
                    if ((eax & 0x7) == 0x0) {
                            esi[0x2] = esi[0x2] & 0x0;
                    }
            }
            else {
                    esi[0x2] = esi[0x2] & 0x0;
            }
    }
    else {
            esi[0x2] = esi[0x2] & 0x0;
    }
    return eax;
}
