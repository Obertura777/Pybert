// sub_100068d0 @ 0x100068d0
// hopper name: sub_100068d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100068d0() {
    eax = GetTickCount();
    if (eax < *dword_1000ab3c) {
            eax = eax - *dword_1000ab3c - 0x1;
    }
    else {
            eax = eax - *dword_1000ab3c;
    }
    return eax;
}
