// sub_473b96 @ 0x473b96
// hopper name: sub_473b96
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473b96() {
    esp = esp - 0x8;
    decomp_var_8 = 0x46def6;
    esi = sub_477aab();
    if (esi == 0x0) {
            sub_46dedc();
    }
    if (*(int8_t *)(sub_4715ba() + 0x14) != 0x0) {
            eax = esi[0xa];
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    UnhookWindowsHookEx(eax);
                    esi[0xa] = esi[0xa] & 0x0;
            }
    }
    if (esi[0x5] != 0x0) {
            esi[0x5] = esi[0x5] & 0x0;
    }
    return;
}
