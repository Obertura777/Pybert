// sub_478943 @ 0x478943
// hopper name: sub_478943
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478943() {
    if (arg_0 == 0x0) {
            sub_46dedc();
    }
    esp = esp - 0x8;
    esi = sub_4715ba(esi);
    sub_478104();
    esi = esi[0x7];
    while (true) {
            if (esi != 0x0) {
                    esp = esp - 0x8;
                    if (lstrcmpA(saved_fp, *esi) != 0x0) {
                            esi = esi[0x5];
                            continue;
                    }
                    esp = esp - 0x4;
                    decomp_var_c = 0x0;
                    sub_478171();
                    break;
            }
            esp = esp - 0x4;
            decomp_var_c = esi;
            sub_478171();
            break;
    }
    return;
}
