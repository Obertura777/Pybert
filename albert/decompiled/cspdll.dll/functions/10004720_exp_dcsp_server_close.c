// exp_dcsp_server_close @ 0x10004720
// hopper name: exp_dcsp_server_close
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_close() {
    esp = esp - 0x58;
    var_58 = 0x1c;
    (*0x10009140)();
    eax = *dword_1000ab38;
    var_50 = 0x8;
    var_54 = 0x0;
    eax = eax[0x2e];
    if (eax != 0xff) {
            eax = dcsp_convert_message_format(&var_58, 0xff, &var_38, eax, 0x32, var_58, var_54, var_50, decomp_var_4c, decomp_var_48);
            eax = dcsp_server_send_message(&var_38, eax, saved_fp, var_58, var_54, var_50, decomp_var_4c, decomp_var_48);
    }
    else {
            eax = dcsp_server_send_message(&var_58, 0x20, saved_fp, var_58, var_54, var_50, decomp_var_4c, decomp_var_48);
    }
    return eax;
}
