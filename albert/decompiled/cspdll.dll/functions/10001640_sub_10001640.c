// sub_10001640 @ 0x10001640
// hopper name: sub_10001640
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001640() {
    eax = (*0x10009150)();
    eax = (eax & 0xffffe000) << 0x2 | eax & 0x1fff;
    return eax;
}
