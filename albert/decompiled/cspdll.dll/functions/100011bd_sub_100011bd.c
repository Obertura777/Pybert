// sub_100011bd @ 0x100011bd
// hopper name: sub_100011bd
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100011bd() {
    edx = arg_0;
    esp = esp - 0x10;
    esi = 0x0;
    *(int16_t *)*edx = 0xc48;
    *edx = &arg_fffffffffffffffe;
    ebp = arg_8 + 0x6;
    ecx = arg_8 | 0xffffffff;
    *(int16_t *)&arg_fffffffffffffffe = 0x40;
    ebx = *edx;
    ebx = ebx + 0x2;
    *edx = ebx;
    asm { repne scasb al, byte [edi] };
    ecx = !ecx - 0x1;
    if (ecx != 0x0) {
            ecx = ecx | 0xffffffff;
            HIBYTE(eax) = *(int8_t *)(esi + ebp);
            *(int16_t *)ebx = eax | 0x4b;
            edi = *edx;
            *edx = edi + 0x2;
            ebx = edi + 0x2;
            esi = esi + 0x1;
            asm { repne scasb al, byte [edi] };
            ecx = !ecx - 0x1;
            if (esi < ecx) {
                    continue;
            }
            break;
    }
    *(int16_t *)ebx = 0x140;
    esi = 0x0;
    *edx = &arg_fffffffffffffffe;
    ebp = arg_14 + 0x47;
    ecx = arg_14 | 0xffffffff;
    *(int16_t *)&arg_fffffffffffffffe = 0x40;
    ebx = *edx;
    ebx = ebx + 0x2;
    *edx = ebx;
    asm { repne scasb al, byte [edi] };
    ecx = !ecx - 0x1;
    if (ecx != 0x0) {
            do {
                    ecx = ecx | 0xffffffff;
                    HIBYTE(eax) = *(int8_t *)(esi + ebp);
                    *(int16_t *)ebx = eax | 0x4b;
                    edi = *edx;
                    *edx = edi + 0x2;
                    ebx = edi + 0x2;
                    esi = esi + 0x1;
                    asm { repne scasb al, byte [edi] };
                    ecx = !ecx - 0x1;
            } while (esi < ecx);
    }
    *(int16_t *)ebx = 0x140;
    *edx = *edx + 0x2;
    return;
}
