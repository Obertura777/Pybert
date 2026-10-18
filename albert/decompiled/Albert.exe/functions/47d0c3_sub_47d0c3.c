// sub_47d0c3 @ 0x47d0c3
// hopper name: sub_47d0c3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d0c3() {
    esp = esp - 0x4;
    sub_47aea2(arg_4);
    eax = var_10;
    if (eax[0x2b] > 0x1) {
            eax = sub_487c7b(arg_0, 0x80, &var_10);
    }
    else {
            eax = eax[0x32];
            eax = *(int8_t *)(eax + arg_0 * 0x2) & 0xff;
            eax = eax & 0x80;
    }
    if (var_4 != 0x0) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    return eax;
}
