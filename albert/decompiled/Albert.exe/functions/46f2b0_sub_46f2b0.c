// sub_46f2b0 @ 0x46f2b0
// hopper name: sub_46f2b0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f2b0() {
    esi = ecx;
    esp = esp - 0xc;
    (*(*esi + 0x4))();
    if (arg_8 != 0x0 && esi[0x4] == 0x0) {
            if (esi[0x2] >= esi[0x8]) {
                    sub_46dedc();
            }
            if (*dword_bc6238 == 0x0) {
                    sub_46f1b2();
                    if (*dword_bc6238 != 0x0) {
                            esp = esp - 0x14;
                            SetMenuItemBitmaps(saved_fp, arg_0, arg_4, arg_8, arg_c);
                    }
            }
            else {
                    esp = esp - 0x14;
                    SetMenuItemBitmaps(saved_fp, arg_0, arg_4, arg_8, arg_c);
            }
    }
    return;
}
