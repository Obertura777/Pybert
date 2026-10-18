// sub_48c440 @ 0x48c440
// hopper name: sub_48c440
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c440() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x10;
    eax = GetLocaleInfoA(arg_0, 0x1004, &var_C, 0x6);
    if (eax != 0x0) {
            sub_47b259(&var_C);
    }
    eax = sub_47ad69();
    return eax;
}
