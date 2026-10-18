// sub_472033 @ 0x472033
// hopper name: sub_472033
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_472033() {
    ebx = arg_0;
    eax = arg_4;
    edx = arg_8;
    ecx = arg_c;
    while (true) {
            if (ebx[0x4] == 0x0) {
                    arg_0 = 0x0;
                    break;
            }
            if (eax != *ebx) {
                    ebx = ebx + 0x18;
                    continue;
            }
            if (edx != ebx[0x1]) {
                    ebx = ebx + 0x18;
                    continue;
            }
            if (ecx < ebx[0x2]) {
                    ebx = ebx + 0x18;
                    continue;
            }
            if (ecx > ebx[0x3]) {
                    ebx = ebx + 0x18;
                    continue;
            }
            arg_0 = ebx;
            break;
    }
    eax = arg_0;
    return eax;
}
