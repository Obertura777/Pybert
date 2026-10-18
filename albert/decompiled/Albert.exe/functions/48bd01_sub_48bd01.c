// sub_48bd01 @ 0x48bd01
// hopper name: sub_48bd01
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bd01() {
    eax = 0x0;
    while (true) {
            ecx = *(int8_t *)edx;
            edx = edx + 0x1;
            if (ecx < 0x41) {
                    if (ecx <= 0x7a) {
                            eax = eax + 0x1;
                            continue;
                    }
                    break;
            }
            if (ecx <= 0x5a) {
                    eax = eax + 0x1;
                    continue;
            }
            if (ecx > 0x7a) {
                    break;
            }
            eax = eax + 0x1;
    }
    return eax;
}
