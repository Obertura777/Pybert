// sub_477be4 @ 0x477be4
// hopper name: sub_477be4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477be4() {
    ebx = ecx;
    esp = esp - 0x20;
    var_14 = ebx;
    var_C = 0x0;
    var_4 = 0x0;
    var_8 = 0x0;
    eax = RegOpenKeyExA(0x80000001, "software", 0x0, 0x2001f, &var_4);
    if (eax == 0x0) {
            esp = esp - 0x24;
            eax = RegCreateKeyExA(var_4, ebx[0x15], 0x0, 0x0, 0x0, 0x2001f, 0x0, &var_8, &var_10);
            if (eax == 0x0) {
                    esp = esp - 0x24;
                    eax = RegCreateKeyExA(var_8, var_14[0x1a], 0x0, 0x0, 0x0, 0x2001f, 0x0, &var_C, &var_10);
            }
    }
    if (var_4 != 0x0) {
            esp = esp - 0x4;
            RegCloseKey(var_4);
    }
    if (var_8 != 0x0) {
            esp = esp - 0x4;
            RegCloseKey(var_8);
    }
    eax = var_C;
    return eax;
}
