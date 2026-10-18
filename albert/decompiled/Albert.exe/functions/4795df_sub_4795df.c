// sub_4795df @ 0x4795df
// hopper name: sub_4795df
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4795df() {
    esp = esp - 0x4;
    decomp_var_4 = 0x0;
    sub_47d6bb(0x0);
    esi = sub_4715ed();
    if (esi[0x6] == 0x0 && arg_4 != 0x0) {
            ebx = sub_46dbbc(0x477e2d);
            esp = (esp - 0x8) + 0x4;
            decomp_var_4 = decomp_var_4 & 0x0;
            if (sub_46dbce(0x60) != 0x0) {
                    esp = esp - 0x14;
                    eax = sub_47819a();
            }
            else {
                    eax = 0x0;
            }
            esi[0x6] = eax;
            sub_46dbbc(ebx);
    }
    eax = sub_47d75a();
    return eax;
}
