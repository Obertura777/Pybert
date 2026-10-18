// sub_479da6 @ 0x479da6
// hopper name: sub_479da6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479da6() {
    if (ecx != 0x0) {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            do {
                    esi = *ecx;
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    ecx = esi;
            } while (esi != 0x0);
    }
    return;
}
