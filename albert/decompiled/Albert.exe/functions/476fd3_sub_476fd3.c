// sub_476fd3 @ 0x476fd3
// hopper name: sub_476fd3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476fd3() {
    esp = esp - 0x4;
    sub_47d6bb(saved_fp);
    esi = sub_4715ed();
    if (esi[0x8] == 0x0 && arg_4 != 0x0) {
            ebx = sub_46dbbc(saved_fp);
            esp = (esp - 0x8) + 0x4;
            decomp_var_4 = 0x60 & 0x0;
            if (sub_46dbce(saved_fp) != 0x0) {
                    esp = esp - 0x14;
                    decomp_var_4 = 0x4b359c;
                    eax = sub_47819a();
            }
            else {
                    eax = 0x0;
            }
            esi[0x8] = eax;
            sub_46dbbc(saved_fp);
    }
    sub_47d75a();
    return;
}
