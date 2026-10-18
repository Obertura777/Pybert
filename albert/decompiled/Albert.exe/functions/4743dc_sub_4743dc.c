// sub_4743dc @ 0x4743dc
// hopper name: sub_4743dc
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4743dc() {
    esp = esp - 0x4;
    eax = GetTopWindow(arg_0);
    while (true) {
            esi = eax;
            if (esi == 0x0) {
                    break;
            }
            if (arg_14 != 0x0) {
                    esp = esp - 0x4;
                    eax = sub_473b15();
                    if (eax != 0x0) {
                            esp = esp - 0x14;
                            sub_474101();
                    }
            }
            else {
                    esp = esp - 0x10;
                    SendMessageA(esi, arg_4, arg_8, arg_c);
            }
            if (arg_10 != 0x0) {
                    esp = esp - 0x4;
                    if (GetTopWindow(esi) != 0x0) {
                            esp = esp - 0x18;
                            sub_4743dc(esi, arg_14, arg_8, arg_c, arg_10, arg_14);
                    }
            }
            arg_4 = 0x2;
            esp = esp - 0x8;
            eax = GetWindow(esi, 0x2);
    }
    return;
}
