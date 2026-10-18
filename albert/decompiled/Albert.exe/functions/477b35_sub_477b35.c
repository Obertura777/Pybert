// sub_477b35 @ 0x477b35
// hopper name: sub_477b35
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477b35() {
    esp = esp - 0x4;
    esi = ecx;
    eax = *esi;
    if (eax != 0x0 && *dword_bc6240 != 0x0) {
            esp = esp - 0x4;
            sub_47780f(saved_fp);
    }
    *esi = *esi & 0x0;
    return;
}
