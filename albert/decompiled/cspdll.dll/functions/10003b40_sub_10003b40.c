// sub_10003b40 @ 0x10003b40
// hopper name: sub_10003b40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003b40() {
    eax = arg_0 & 0xffff;
    bool_7 = eax == 0xa48;
    if (eax > 0xa48) goto loc_10003b8e;
    goto loc_10003b50;

loc_10003b8e:
    bool_2 = eax == 0x1548;
    if (eax > 0x1548) goto loc_10003bb7;
    goto loc_10003b95;

loc_10003b50:
    if (bool_7) goto .l1;
    goto loc_10003b52;

loc_10003bb7:
    if (eax == 0x1848) goto .l1;
    goto .l1;

loc_10003b95:
    if (bool_2 || eax == 0xc48 || eax == 0xe48) goto .l1;

.l1:
    return;

loc_10003b52:
    bool_10 = eax == 0x748;
    if (eax > 0x748) goto loc_10003b7b;
    goto loc_10003b59;

loc_10003b7b:
    if (eax != 0x948) goto .l1;
    goto .l1;

loc_10003b59:
    if (bool_10 || eax == 0x348 || eax == 0x448) goto .l1;
}
