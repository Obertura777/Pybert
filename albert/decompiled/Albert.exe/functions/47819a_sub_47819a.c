// sub_47819a @ 0x47819a
// hopper name: sub_47819a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47819a() {
    sub_47d6bb(0x4);
    esi = ecx;
    edi = arg_4;
    *esi = 0x4b378c;
    sub_479b05(edi[0x1], 0x40);
    sub_479315(0xa);
    ebx = esi + 0x38;
    esp = esp - 0x14;
    sub_479315(0x4);
    if (arg_8 == 0x0) {
            eax = 0x0;
            sub_46dedc();
    }
    if (arg_c == 0x0) {
            eax = 0x0;
            sub_46dedc();
    }
    sub_479114(0x7, 0x0);
    esi[0x5] = arg_8;
    esi[0x6] = arg_c;
    esi[0x16] = arg_10;
    esi[0x17] = arg_14;
    esi[0x15] = edi;
    eax = sub_47d75a();
    return eax;
}
