// exp_dcsp_server_use_default_address @ 0x100044c0
// hopper name: exp_dcsp_server_use_default_address
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_use_default_address() {
    esp = esp - 0x108;
    var_108 = &var_100;
    if ((*0x1000913c)() != 0x0) {
            eax = 0x0;
    }
    else {
            eax = dcsp_convert_address(&var_108, 0x1, var_4);
    }
    return eax;
}
