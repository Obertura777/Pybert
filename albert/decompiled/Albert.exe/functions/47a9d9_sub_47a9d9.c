// sub_47a9d9 @ 0x47a9d9
// hopper name: sub_47a9d9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a9d9() {
    esi = *0x0;
    RtlUnwind(arg_0, 0x47aa02, arg_4, 0x0);
    eax = arg_4[0x1];
    eax = eax & 0xfffffffd;
    arg_4[0x1] = eax;
    *esi = *0x0;
    *0x0 = esi;
    return eax;
}
