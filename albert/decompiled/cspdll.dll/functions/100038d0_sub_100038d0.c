// sub_100038d0 @ 0x100038d0
// hopper name: sub_100038d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100038d0() {
    eax = arg_0 & 0xffff;
    bool_9 = eax == 0xe48;
    if (eax > 0xe48) goto loc_1000395a;
    goto loc_100038e0;

loc_1000395a:
    bool_2 = eax == 0x1648;
    if (eax > 0x1648) goto loc_10003990;
    goto loc_10003961;

loc_100038e0:
    if (bool_9) goto .l1;
    goto loc_100038e2;

loc_10003990:
    if (eax == 0x1a48 || eax == 0x1b48 || eax != 0x1d48) goto .l1;
    goto .l1;

loc_10003961:
    if (bool_2 || eax == 0x1048 || eax == 0x1148 || eax == 0x1548) goto .l1;

.l1:
    return;

loc_100038e2:
    bool_18 = eax == 0xa48;
    if (eax > 0xa48) goto loc_1000392d;
    goto loc_100038e9;

loc_1000392d:
    if (eax == 0xb48 || eax == 0xc48 || eax == 0xd48) goto .l1;
    goto .l1;

loc_100038e9:
    if (bool_18) goto .l1;

loc_100038eb:
    bool_17 = eax == 0x748;
    if (eax > 0x748) goto loc_10003916;
    goto loc_100038f2;

loc_10003916:
    if (eax != 0x948) goto .l1;
    goto .l1;

loc_100038f2:
    if (bool_17 || eax != 0x48 && eax != 0x448) goto .l1;
}
