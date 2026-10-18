// sub_476858 @ 0x476858
// hopper name: sub_476858
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476858() {
    esp = esp - 0x4;
    esi = ecx;
    if (esi != 0x0 && esi[0x14] == 0x0) {
            esp = esp - 0x8;
            decomp_var_8 = GetParent(esi[0x8]);
            eax = sub_4791ea();
            if (eax != 0x0) {
                    if (eax[0x13] != 0x0) {
                            esp = esp - 0x8;
                            (*(*eax[0x13] + 0x9c))(esi, 0x0);
                    }
            }
    }
    return;
}
