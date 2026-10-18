// sub_487d79 @ 0x487d79
// hopper name: sub_487d79
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487d79() {
    ecx = *dword_bc7210;
    eax = *dword_bc7214;
    ecx = ecx * 0x14 + *dword_bc7214;
    while (true) {
            if (eax < ecx) {
                    if (arg_0 - eax[0x3] >= 0x100000) {
                            eax = eax + 0x14;
                            continue;
                    }
                    break;
            }
            eax = 0x0;
            break;
    }
    return eax;
}
