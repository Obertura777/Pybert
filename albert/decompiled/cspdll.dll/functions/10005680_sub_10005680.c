// sub_10005680 @ 0x10005680
// hopper name: sub_10005680
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005680() {
    esi = malloc(0x10);
    esp = (esp - 0x14) + 0x4;
    *esi = 0x0;
    eax = *(int8_t *)(*arg_10 + 0x26);
    if (eax != 0xff) {
            ebx = arg_14;
            edi = esi + 0xc;
            esi[0x2] = (*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + 0x1000a71c))(*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + dword_1000a728), ebx[0x2], edi);
            eax = *edi;
            esp = (esp - 0xc) + 0xc;
            esi[0x1] = arg_24;
            ebp = eax != 0x0 ? 0x1 : 0x0;
            ecx = ebx[0x2];
            if (eax != 0x0) {
                    free(ecx);
                    esp = (esp - 0x4) + 0x4;
                    ebx[0x2] = 0x0;
            }
    }
    else {
            ebx = arg_14;
            edi = esi + 0xc;
            ebp = 0x1;
            *edi = ebx[0x2];
            esi[0x2] = ebx[0x2];
            esi[0x1] = arg_18;
    }
    ebx[0x2] = 0x0;
    free(ebx);
    esp = (esp - 0x4) + 0x4;
    if (ebp != 0x0) {
            ebp = arg_24;
            eax = *ebp;
            if (eax[0x25] == 0x1) {
                    (eax[0xe])(*edi, esi[0x2], esi[0x1], eax[0xf]);
                    free(*edi);
                    *edi = 0x0;
                    eax = free(esi);
            }
            else {
                    esp = esp - 0x8;
                    WaitForSingleObject(*eax, 0xffffffff);
                    eax = *ebp;
                    ecx = eax[0x2];
                    if (ecx == 0x0) {
                            eax[0x1] = esi;
                    }
                    else {
                            *ecx = esi;
                    }
                    *(*ebp + 0x8) = esi;
                    eax = **ebp;
                    eax = ReleaseMutex(eax);
            }
    }
    else {
            eax = free(esi);
    }
    return eax;
}
