// sub_48bcb1 @ 0x48bcb1
// hopper name: sub_48bcb1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bcb1() {
    eax = 0x0;
    while (true) {
            if (arg_0 == eax[0x25ca2c]) {
                    eax = 0x0;
                    break;
            }
            eax = eax + 0x2;
            if (eax < 0x14) {
                    continue;
            }
            eax = 0x1;
            break;
    }
    return eax;
}
