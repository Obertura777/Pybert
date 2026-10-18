// sub_10003c1b @ 0x10003c1b
// hopper name: sub_10003c1b
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003c1b() {
    *(int8_t *)(eax + eax) = *(int8_t *)(eax + eax) - HIBYTE(ebx) + CARRY(EFLAGS(cf));
    *(int8_t *)eax = *(int8_t *)eax + ebx + CARRY(EFLAGS(cf));
    *(int8_t *)eax = *(int8_t *)eax + ebx + CARRY(EFLAGS(cf));
    loc_10003c2f();
    return;
}
