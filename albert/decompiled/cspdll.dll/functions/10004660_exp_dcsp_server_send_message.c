// exp_dcsp_server_send_message @ 0x10004660
// hopper name: exp_dcsp_server_send_message
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_server_send_message() {
    ebx = malloc(0x10);
    esp = (esp - 0x14) + 0x4;
    if (ebx != 0x0) {
            esi = arg_14;
            eax = malloc(esi);
            esp = (esp - 0x4) + 0x4;
            ebx[0x3] = eax;
            bool_4 = true;
            bool_3 = true;
            if (eax != 0x0) {
                    ebx[0x2] = esi;
                    ebx[0x1] = arg_1c;
                    *ebx = 0x0;
                    *eax = *arg_14;
                    esp = esp - 0x4;
                    saved_fp = 0xffffffff;
                    asm { rep movsb  byte [edi], byte [esi] };
                    esp = esp - 0x4;
                    WaitForSingleObject(*(*dword_1000ab38 + 0x8), saved_fp);
                    eax = *(*dword_1000ab38 + 0x18);
                    if (eax == 0x0) {
                            *(*dword_1000ab38 + 0x14) = ebx;
                    }
                    else {
                            *eax = ebx;
                    }
                    *(*dword_1000ab38 + 0x18) = ebx;
                    ReleaseSemaphore(*(*dword_1000ab38 + 0x1c), 0x1, &arg_c);
                    ReleaseMutex(*(*dword_1000ab38 + 0x8));
            }
    }
    return;
}
