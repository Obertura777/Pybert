// sub_4220e0 @ 0x4220e0
// hopper name: sub_4220e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4220e0() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = sub_40fed0();
    ecx[0x1] = eax;
    eax[0x21] = 0x1;
    eax = ecx[0x1];
    eax[0x1] = eax;
    eax = ecx[0x1];
    *eax = eax;
    eax = ecx[0x1];
    eax[0x2] = eax;
    ecx[0x2] = 0x0;
    sub_411b40(arg_0);
    eax = ecx;
    *0x0 = var_C;
    &var_14 = ebp;
    return eax;
}
