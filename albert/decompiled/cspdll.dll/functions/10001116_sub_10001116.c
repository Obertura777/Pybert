// sub_10001116 @ 0x10001116
// hopper name: sub_10001116
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001116() {
    edx = arg_0;
    esp = esp - 0x8;
    ebx = arg_4 + 0x6;
    *(int16_t *)*edx = 0x948;
    esi = *edx;
    *edx = esi + 0x2;
    ecx = *(int8_t *)ebx;
    eax = esi + 0x2;
    if (ecx != 0x0) {
            *(int16_t *)eax = 0x40;
            esp = esp - 0x8;
            ebp = &arg_fffffffffffffffe;
            ecx = ecx | 0xffffffff;
            *edx = ebp;
            esi = 0x0;
            asm { repne scasb al, byte [edi] };
            ecx = !ecx - 0x1;
            if (ecx != 0x0) {
                    do {
                            ecx = ecx | 0xffffffff;
                            HIBYTE(eax) = *(int8_t *)(ebx + esi);
                            *(int16_t *)ebp = eax | 0x4b;
                            edi = *edx;
                            *edx = edi + 0x2;
                            ebp = edi + 0x2;
                            esi = esi + 0x1;
                            asm { repne scasb al, byte [edi] };
                            ecx = !ecx - 0x1;
                    } while (esi < ecx);
            }
            *(int16_t *)ebp = 0x140;
            *edx = *edx + 0x2;
            esp = esp + 0x8;
    }
    return;
}
