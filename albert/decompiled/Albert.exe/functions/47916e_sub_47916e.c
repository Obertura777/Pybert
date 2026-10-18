// sub_47916e @ 0x47916e
// hopper name: sub_47916e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47916e() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = esi[0x1];
    if (eax != 0x0) {
            sub_47c8f9();
            esi[0x1] = esi[0x1] & 0x0;
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x3] = esi[0x3] & 0x0;
    esi[0x4] = esi[0x4] & 0x0;
    eax = sub_479da6();
    esi[0x5] = esi[0x5] & 0x0;
    return eax;
}
