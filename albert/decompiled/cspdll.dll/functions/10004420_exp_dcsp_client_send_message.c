// exp_dcsp_client_send_message @ 0x10004420
// hopper name: exp_dcsp_client_send_message
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_client_send_message() {
    eax = dcsp_server_send_message(arg_0, arg_4, 0x0, saved_fp, arg_0, arg_4, arg_8, arg_c);
    return eax;
}
