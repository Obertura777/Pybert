// exp_dcsp_server_set_rm @ 0x10004440
// hopper name: exp_dcsp_server_set_rm
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_set_rm() {
    decomp_var_4 = ebx;
    esi = arg_0;
    ebx = ((*0x10009150)() & 0xffff) + 0x4;
    esp = (esp - 0x18) + 0x4;
    *(*dword_1000ab38 + 0x48) = malloc(ebx);
    edi = *(*dword_1000ab38 + 0x48);
    bool_2 = true;
    bool_1 = true;
    if (edi == 0x0) {
            eax = 0x0;
    }
    else {
            ebp = 0x1;
            *edi = *esi;
            asm { rep movsb  byte [edi], byte [esi] };
            sub_100030d0(*dword_1000a728, *(*dword_1000ab38 + 0x48));
            eax = ebp;
    }
    return eax;
}
