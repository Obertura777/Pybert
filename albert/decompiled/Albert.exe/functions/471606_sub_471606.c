// sub_471606 @ 0x471606
// hopper name: sub_471606
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471606() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (*(sub_4715ba(decomp_var_4) + 0x7c) != 0x0) {
            eax = arg_0[0x20];
            if (eax != 0xffffffff) {
                    esp = esp - 0x8;
                    esi[0x1] = sub_470dcd();
            }
            else {
                    esi[0x1] = esi[0x1] & 0x0;
            }
    }
    else {
            esi[0x1] = esi[0x1] & 0x0;
    }
    eax = esi;
    return eax;
}
