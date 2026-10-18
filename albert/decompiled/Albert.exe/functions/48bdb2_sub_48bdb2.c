// sub_48bdb2 @ 0x48bdb2
// hopper name: sub_48bdb2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bdb2() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x14;
    esi = ecx;
    eax = GetLocaleInfoA(arg_0 & 0x3ff | 0x400, 0x1, &var_7C, 0x78);
    if (eax != 0x0 && arg_0 != sub_48bccf() && arg_4 != 0x0) {
            esp = (esp - 0x8) + 0x8;
            sub_48bd01() == sub_47d630(*esi);
    }
    eax = sub_47ad69();
    return eax;
}
