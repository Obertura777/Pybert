// sub_476899 @ 0x476899
// hopper name: sub_476899
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476899() {
    edi = arg_4;
    esi = ecx;
    esp = esp - 0x8;
    eax = sub_4766ef(edi, &arg_4);
    if (arg_4 == 0x0) {
            esp = esp - 0x4;
            if (sub_4766b8() == 0x0) {
                    sub_46dec2();
            }
            esi[0x3] = esi[0x3] & 0x0;
            esi[0x2] = edi;
    }
    else {
            esi[0x3] = esi[0x3] & 0x0;
            esi[0x2] = edi;
    }
    return;
}
