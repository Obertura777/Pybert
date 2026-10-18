// sub_474101 @ 0x474101
// hopper name: sub_474101
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474101() {
    sub_47d6ee(0x38);
    esp = esp - 0x8;
    ebx = sub_477aab();
    eax = 0x0;
    bool_3 = true;
    if (ebx == 0x0) {
            sub_46dedc();
    }
    esp = (esp - 0x4) + 0x4;
    decomp_var_44 = ebx[0x16];
    edi = arg_c;
    esi = arg_4;
    ebx[0x16] = arg_8;
    ebx[0x18] = arg_10;
    ebx[0x17] = edi;
    ebx[0x19] = arg_14;
    if (edi == 0x2) {
            edx = 0x0;
            if (esi[0x13] != 0x0) {
                    esp = esp - 0x4;
                    (*(*esi[0x13] + 0x60))(edx);
            }
    }
    arg_4 = arg_4 & 0x0;
    if (edi == 0x110) {
            esp = esp - 0xc;
            eax = sub_47282b(esi, &decomp_var_28);
    }
    esp = esp - 0xc;
    bool_5 = true;
    arg_14 = (*(*esi + 0x108))(edi, arg_10, arg_14);
    if (edi == 0x110) {
            esp = esp - 0xc;
            sub_474085(esi, &decomp_var_28, arg_4);
    }
    ebx[0x16] = decomp_var_44;
    eax = sub_47d75a();
    return eax;
}
