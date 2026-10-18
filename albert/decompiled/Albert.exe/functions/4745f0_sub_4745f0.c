// sub_4745f0 @ 0x4745f0
// hopper name: sub_4745f0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4745f0() {
    eax = arg_0;
    esp = esp - 0x8;
    if (eax[0x2] == 0x0) {
            loc_47462b(saved_fp, arg_0, arg_4, arg_8, arg_c);
    }
    else {
            if (arg_1c == 0x0) {
                    loc_47462b(saved_fp, arg_0, arg_4, arg_8, arg_c);
            }
            else {
                    sub_47461a(saved_fp, arg_0, arg_4, arg_8, arg_c);
            }
    }
    return;
}
