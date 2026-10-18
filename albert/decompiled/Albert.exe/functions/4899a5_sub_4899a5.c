// sub_4899a5 @ 0x4899a5
// hopper name: sub_4899a5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4899a5() {
    esp = esp - 0x4;
    do {
            *esi = *esi + 0x1;
            ebx = sub_48998f();
            if (ebx == 0xffffffff) {
                    break;
            }
            esp = (esp - 0x4) + 0x4;
    } while (sub_47d191() != 0x0);
    return;
}
