// sub_493528 @ 0x493528
// hopper name: sub_493528
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493528() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    edi = ecx;
    esi = edi[0x8];
    while (esi != 0x0) {
            (esi[0x2])(arg_4, edi, esi[0x1]);
            esi = *esi;
            esp = (esp - 0xc) + 0xc;
    }
    return;
}
