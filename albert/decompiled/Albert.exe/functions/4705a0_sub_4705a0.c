// sub_4705a0 @ 0x4705a0
// hopper name: sub_4705a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4705a0() {
    esi = ecx;
    sub_473b96();
    sub_473b68();
    esp = esp - 0x8;
    if (IsWindow(esi[0x1b]) != 0x0) {
            esp = esp - 0x8;
            EnableWindow(esi[0x1b], 0x1);
    }
    esi[0x1b] = esi[0x1b] & 0x0;
    eax = sub_4715ba();
    eax = eax[0x1];
    esp = esp + 0x4;
    if (eax != 0x0) {
            eax = sub_46ff82(0x1);
    }
    return eax;
}
