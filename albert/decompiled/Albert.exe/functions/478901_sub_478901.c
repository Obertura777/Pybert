// sub_478901 @ 0x478901
// hopper name: sub_478901
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478901() {
    esp = esp - 0x4;
    esi = ecx;
    if ((esi[0x18] & 0x1) == 0x0) {
            sub_478ca7();
    }
    eax = esi[0xa];
    ecx = esi[0xb];
    if (eax + 0x4 > ecx) {
            esp = esp - 0x4;
            decomp_var_8 = (eax - ecx) + 0x4;
            sub_47875e(decomp_var_8);
    }
    *saved_fp = *esi[0xa];
    esi[0xa] = esi[0xa] + 0x4;
    return;
}
