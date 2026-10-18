// sub_476f3f @ 0x476f3f
// hopper name: sub_476f3f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476f3f() {
    sub_47d6bb(0x4);
    esi = ecx;
    esi[0x1] = 0x0;
    esi[0x2] = 0x0;
    esi[0x3] = 0x0;
    *esi = 0x4b3684;
    eax = arg_4[0x8];
    esi[0x4] = eax;
    if (sub_476ec2(BeginPaint(eax, esi + 0x14)) == 0x0) {
            sub_476aa8();
    }
    sub_47d75a();
    return;
}
