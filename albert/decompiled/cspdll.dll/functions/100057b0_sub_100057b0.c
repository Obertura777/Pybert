// sub_100057b0 @ 0x100057b0
// hopper name: sub_100057b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100057b0() {
    decomp_var_4 = ecx;
    var_8 = ebx;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    decomp_var_14 = edi;
    decomp_var_18 = 0xffffffff;
    esp = esp - 0x1c;
    WaitForSingleObject(*(*dword_1000ab38 + 0x8), 0xffffffff);
    ebx = saved_fp;
    esi = *(*ebx + 0xc);
    edi = sub_10005a90();
    if (edi != 0x0) {
            *(*ebx + 0xc) = *esi;
            eax = *ebx;
            if (eax[0x3] == 0x0) {
                    eax[0x4] = 0x0;
            }
            *esi = 0x0;
    }
    else {
            esp = esp - 0xc;
            eax = ReleaseSemaphore(*(*ebx + 0x14), 0x1, &var_8);
            esi = 0x0;
    }
    esp = esp - 0x4;
    ReleaseMutex(*(*dword_1000ab38 + 0x8));
    if (esi != 0x0) {
            ebp = 0x0;
            if (*(ebx + esi[0x1] * 0x4 + 0x4) == 0x0) {
                    free(edi);
                    eax = free(esi[0x3]);
                    esi[0x3] = ebp;
            }
            else {
                    eax = *ebx;
                    eax = eax[0x26];
                    if (eax == 0xff) {
                            edi[0x2] = esi[0x3];
                    }
                    else {
                            eax = (*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + 0x1000a720))(*(((eax & 0xff) + (eax & 0xff) * 0x4 << 0x2) + dword_1000a728), esi[0x3]);
                            edi[0x2] = eax;
                            ecx = esi[0x3];
                            esp = (esp - 0x8) + 0x8;
                            if (eax != ecx) {
                                    decomp_var_14 = ecx;
                                    free(decomp_var_14);
                                    esp = (esp - 0x4) + 0x4;
                                    esi[0x3] = ebp;
                            }
                    }
                    esi[0x3] = ebp;
                    eax = edi[0x2];
                    if (*(int8_t *)eax == 0xff) {
                            sub_100058e0(ebx, esi[0x1], eax);
                            eax = free(esi);
                    }
                    else {
                            sub_10004cf0(ebx, esi[0x1], edi, ebp);
                            eax = free(esi);
                    }
            }
    }
    else {
            eax = (null)();
    }
    return eax;
}
