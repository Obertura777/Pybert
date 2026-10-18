// sub_48c118 @ 0x48c118
// hopper name: sub_48c118
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c118() {
    eax = sub_47d630(*esi);
    esp = (esp - 0x4) + 0x4;
    esi[0x4] = (-(-(eax - 0x3) - 0x3) - -(-(eax - 0x3) - 0x3) + CARRY(EFLAGS(cf))) + 0x1;
    if (-(-(eax - 0x3) - 0x3) - -(-(eax - 0x3) - 0x3) + CARRY(EFLAGS(cf)) != 0xffffffff) {
            eax = 0x2;
            esp = (esp - 0x4) + 0x4;
    }
    else {
            eax = sub_48bd01();
    }
    esi[0x3] = eax;
    eax = EnumSystemLocalesA(sub_48bff4, 0x1);
    if ((esi[0x8] & 0x4) == 0x0) {
            esi[0x2] = esi[0x2] & 0x0;
    }
    return eax;
}
