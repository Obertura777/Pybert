// sub_49337f @ 0x49337f
// hopper name: sub_49337f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49337f() {
    eax = arg_0;
    if (eax[0x14] > 0x0) {
            if (eax[0x15] >= 0x10) {
                    eax = eax[0x10];
            }
            else {
                    eax = eax + 0x40;
            }
            eax = sub_482823();
    }
    return eax;
}
