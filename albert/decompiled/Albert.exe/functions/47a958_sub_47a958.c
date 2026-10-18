// sub_47a958 @ 0x47a958
// hopper name: sub_47a958
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a958() {
    var_20 = *0x4b3970;
    eax = arg_4;
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0 && (*(int8_t *)eax & 0x8) != 0x0) {
            var_C = 0x1994000;
    }
    eax = RaiseException(var_20, var_1C, var_10, &var_C);
    return eax;
}
