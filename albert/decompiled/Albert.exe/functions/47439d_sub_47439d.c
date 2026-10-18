// sub_47439d @ 0x47439d
// hopper name: sub_47439d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47439d() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (esi != 0x0 && esi[0x8] != 0x0) {
            if ((*(*esi + 0x120))() == 0x0) {
                    esi = sub_47435e();
            }
            if (esi != 0x0) {
                    while (true) {
                            eax = sub_47435e();
                            if (eax == 0x0) {
                                    break;
                            }
                            esi = eax;
                    }
            }
            eax = esi;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
