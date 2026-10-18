// sub_10005ab0 @ 0x10005ab0
// hopper name: sub_10005ab0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005ab0() {
    var_4 = ecx;
    FormatMessageA(0x1300, 0x0, GetLastError(), &var_4, 0x0, 0x0, var_4);
    MessageBoxA(0x0, &var_4, "Error from Diplomacy AI Client DLL", 0x40);
    eax = LocalFree(&var_4);
    return eax;
}
