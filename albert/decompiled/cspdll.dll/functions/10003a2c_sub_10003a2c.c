// sub_10003a2c @ 0x10003a2c
// hopper name: sub_10003a2c
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003a2c() {
    edx = arg_4;
    ecx = *(int8_t *)edx;
    ecx = ecx - 0x2;
    if (ecx != 0x0) {
            if (ecx == 0x3) {
                    sub_10003b00();
            }
    }
    else {
            sub_10003a60();
    }
    return;
}
