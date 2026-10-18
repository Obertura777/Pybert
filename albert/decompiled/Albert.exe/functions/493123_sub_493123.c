// sub_493123 @ 0x493123
// hopper name: sub_493123
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493123() {
    decomp_var_4 = esi;
    esi = arg_0;
    *esi = *(sub_48bbb4() + 0x4);
    esi[0x1] = sub_48bb8e();
    eax = sub_4812c0(0x100, 0x2);
    esp = (esp - 0xc) + 0x8;
    esi[0x2] = eax;
    if (eax != 0x0) {
            sub_47c000(esi[0x2], sub_48ac5f(), decomp_var_8);
            esp = (esp - 0xc) + 0xc;
            esi[0x3] = 0x1;
    }
    else {
            eax = sub_48ac5f();
            esi[0x3] = esi[0x3] & 0x0;
            esi[0x2] = eax;
    }
    eax = esi;
    return eax;
}
