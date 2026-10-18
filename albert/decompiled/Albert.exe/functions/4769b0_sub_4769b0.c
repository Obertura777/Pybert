// sub_4769b0 @ 0x4769b0
// hopper name: sub_4769b0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4769b0() {
    esi = ecx;
    ecx = esi[0x1];
    eax = 0x1;
    esp = esp - 0x8;
    if (ecx != esi[0x2]) {
            esp = esp - 0x8;
            eax = RestoreDC(saved_fp, arg_0);
    }
    esi = esi[0x2];
    if (esi != 0x0) {
            if (eax != 0x0) {
                    esp = esp - 0x8;
                    RestoreDC(saved_fp, arg_0) == 0x0;
            }
    }
    return;
}
