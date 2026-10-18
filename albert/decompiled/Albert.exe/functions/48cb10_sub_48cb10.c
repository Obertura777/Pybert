// sub_48cb10 @ 0x48cb10
// hopper name: sub_48cb10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48cb10() {
    if (ecx < 0x40) {
            if (ecx < 0x20) {
                    asm { shrd       eax, edx, cl };
            }
            else {
                    eax = edx >> (ecx & 0x1f);
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
