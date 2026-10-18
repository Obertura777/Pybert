// exp_dcsp_client_receive_message_vb @ 0x10004410
// hopper name: exp_dcsp_client_receive_message_vb
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_client_receive_message_vb() {
    eax = dcsp_client_receive_message(*arg_0);
    return eax;
}
