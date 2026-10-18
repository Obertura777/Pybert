// exp_dcsp_server_receive_message @ 0x100045a0
// hopper name: exp_dcsp_server_receive_message
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_receive_message() {
    var_4 = ebx;
    decomp_var_c = edi;
    decomp_var_10 = 0xffffffff;
    esp = esp - 0x14;
    decomp_var_14 = *(*dword_1000ab38 + 0x8);
    WaitForSingleObject(decomp_var_14, 0xffffffff);
    ebx = *(*dword_1000ab38 + 0xc);
    if (ebx == 0x0) {
            esi = 0x0;
    }
    else {
            edi = var_4;
            bool_4 = true;
            bool_3 = true;
            if (edi != 0x0) {
                    ecx = ebx[0x2];
                    esi = ebx[0x3];
                    *edi = *esi;
                    asm { rep movsb  byte [edi], byte [esi] };
                    if (*(*dword_1000ab38 + 0x28) == 0x0) {
                            *saved_fp = ebx[0x1];
                    }
                    edx = *dword_1000ab38;
                    ecx = *ebx;
                    esi = ebx[0x2];
                    edx[0x3] = ecx;
                    if (*(*dword_1000ab38 + 0xc) == 0x0) {
                            *(*dword_1000ab38 + 0x10) = 0x0;
                    }
                    eax = ebx[0x3];
                    *ebx = 0x0;
                    free(eax);
                    ebx[0x3] = 0x0;
                    free(ebx);
                    esp = (esp - 0x8) + 0x8;
            }
            else {
                    esi = ebx[0x2];
            }
    }
    ReleaseMutex(*(*dword_1000ab38 + 0x8));
    eax = esi;
    return eax;
}
