// sub_474d39 @ 0x474d39
// hopper name: sub_474d39
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474d39() {
    esi = arg_0;
    esp = esp - 0x8;
    eax = sub_473b15();
    if (eax != 0x0) {
            eax = sub_474ae7();
    }
    else {
            esp = esp - 0x8;
            if ((GetWindowLongA(esi, 0xfffffff0) & 0x40000000) != 0x0) {
                    esp = esp - 0x4;
                    GetParent(esi);
            }
            else {
                    esp = esp - 0x8;
                    GetWindow(esi, 0x4);
            }
    }
    return;
}
