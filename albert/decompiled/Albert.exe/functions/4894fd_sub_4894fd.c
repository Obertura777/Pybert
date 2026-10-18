// sub_4894fd @ 0x4894fd
// hopper name: sub_4894fd
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4894fd() {
    eax = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    while (eax[0x1] != edx) {
            eax = eax + 0xc;
            if (eax >= *dword_4c9be4 * 0xc + arg_0) {
                    break;
            }
    }
    if (eax >= *dword_4c9be4 * 0xc + arg_0 || eax[0x1] != edx) {
            eax = 0x0;
    }
    return eax;
}
