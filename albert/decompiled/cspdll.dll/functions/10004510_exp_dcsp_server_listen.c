// exp_dcsp_server_listen @ 0x10004510
// hopper name: exp_dcsp_server_listen
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_listen() {
    eax = (*0x10009140)();
    esp = esp - 0x5c;
    var_5C = 0x1c;
    *(int16_t *)(*dword_1000ab38 + 0x32) = eax;
    (*0x10009140)();
    eax = *dword_1000ab38;
    var_54 = 0x2;
    var_58 = 0x0;
    eax = eax[0x2e];
    if (eax != 0xff) {
            eax = dcsp_convert_message_format(&var_5C, 0xff, &var_3C, eax, 0x32, var_5C, var_58, var_54, decomp_var_50, decomp_var_4c);
            eax = dcsp_server_send_message(&var_3C, eax, 0x0, var_5C, var_58, var_54, decomp_var_50, decomp_var_4c);
    }
    else {
            eax = dcsp_server_send_message(&var_5C, 0x20, 0x0, var_5C, var_58, var_54, decomp_var_50, decomp_var_4c);
    }
    return eax;
}
