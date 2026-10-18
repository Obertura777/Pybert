// sub_48bb8e @ 0x48bb8e
// hopper name: sub_48bb8e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bb8e() {
    eax = *(sub_480086() + 0x6c);
    bool_1 = eax != *dword_4c95f8;
    if (eax != *dword_4c95f8 && !bool_1) {
            eax = sub_481ce6();
    }
    eax = eax[0x1];
    return eax;
}
