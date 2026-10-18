// sub_493851 @ 0x493851
// hopper name: sub_493851
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493851() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x4;
    var_98 = 0x94;
    GetVersionExA(&var_98);
    if (var_88 == 0x2) {
            eax = 0x49384d;
            if (var_94 < 0x5) {
                    eax = sub_4937e8;
            }
    }
    else {
            eax = sub_4937e8;
    }
    InterlockedExchange(0x4ca51c, eax);
    (*0x4ca51c)();
    eax = sub_47ad69();
    return eax;
}
