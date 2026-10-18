// sub_4728e5 @ 0x4728e5
// hopper name: sub_4728e5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4728e5() {
    esp = esp - 0x4;
    esi = sub_4715ed();
    eax = esi[0xf];
    if (eax != 0x0) {
            eax = eax[0x8];
            if (eax != 0x0) {
                    esp = esp - 0x10;
                    SendMessageA(saved_fp, arg_0, arg_4, arg_8);
            }
    }
    esi = esi[0x14];
    if (arg_4 != 0x0) {
            if (esi != 0x0) {
                    esp = esp - 0x4;
                    if (GetKeyState(saved_fp) >= 0x0) {
                            esp = esp - 0x4;
                            (*(*esi + 0x164))();
                    }
            }
    }
    return;
}
