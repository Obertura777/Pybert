// exp_dcsp_client_receive_message @ 0x10004400
// hopper name: exp_dcsp_client_receive_message
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_client_receive_message() {
    eax = dcsp_server_receive_message();
    return eax;
}
