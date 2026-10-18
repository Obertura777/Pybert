// sub_477c75 @ 0x477c75
// hopper name: sub_477c75
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477c75() {
    esp = esp - 0x4;
    var_4 = 0x0;
    edi = sub_477be4();
    if (edi == 0x0) {
            eax = 0x0;
    }
    else {
            eax = RegCreateKeyExA(edi, arg_0, 0x0, 0x0, 0x0, 0x2001f, 0x0, &var_4, &var_8);
            esp = esp - 0x28;
            RegCloseKey(edi);
            eax = var_4;
    }
    return eax;
}
