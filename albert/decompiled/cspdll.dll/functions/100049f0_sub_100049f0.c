// sub_100049f0 @ 0x100049f0
// hopper name: sub_100049f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100049f0() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    esi = 0x1000a718;
    do {
            eax = *esi;
            if (eax != 0x0) {
                    esi[0x4] = (eax)();
            }
            esi = esi + 0x14;
            bool_1 = true;
    } while (esi < 0x1000a754);
    esi = arg_0;
    eax = 0x0;
    esp = esp - 0x4;
    decomp_var_14 = esi;
    ebx = esi + 0x4;
    asm { rep stosd  dword [edi], eax };
    esi[0x33] = eax;
    eax = sub_10005980(decomp_var_14, decomp_var_10, decomp_var_c);
    esp = esp + 0x4;
    *ebx = eax;
    if (eax != 0x0) {
            if (*(*esi + 0x44) != 0x0) {
                    eax = sub_10003c30(esi, 0x0, decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4, saved_fp);
                    esp = (esp - 0x8) + 0x8;
                    if (eax == 0x0) {
                            sub_10005a00(esi, eax);
                            *ebx = 0x0;
                            eax = 0x0;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x1;
            }
    }
    return eax;
}
