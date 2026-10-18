// sub_4777d0 @ 0x4777d0
// hopper name: sub_4777d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4777d0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    esi[0x5] = 0x0;
    esi[0x6] = 0x4;
    esi[0x1] = 0x0;
    esi[0x2] = 0x1;
    esi[0x3] = 0x0;
    esi[0x4] = 0x0;
    eax = TlsAlloc();
    *esi = eax;
    if (eax == 0xffffffff) {
            sub_46dea8();
    }
    InitializeCriticalSection(esi + 0x1c);
    return;
}
