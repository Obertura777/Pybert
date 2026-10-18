// sub_483bdf @ 0x483bdf
// hopper name: sub_483bdf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483bdf() {
    eax = arg_c;
    switch (eax) {
        case 101:
            esp = esp - 0x18;
            eax = sub_4834dc(arg_0, arg_4, arg_8, arg_10, arg_14, arg_18);
            break;
        case 69:
            esp = esp - 0x18;
            eax = sub_4834dc(arg_0, arg_4, arg_8, arg_10, arg_14, arg_18);
            break;
        default:
            if (eax == 0x66) {
                    eax = sub_483a2e(arg_0, arg_4, arg_8, arg_10, arg_18);
            }
            else {
                    switch (eax) {
                        case 97:
                            esp = esp - 0x18;
                            eax = sub_4835c8(arg_0, arg_4, arg_8, arg_10, arg_14, arg_18);
                            break;
                        case 65:
                            esp = esp - 0x18;
                            eax = sub_4835c8(arg_0, arg_4, arg_8, arg_10, arg_14, arg_18);
                            break;
                        default:
                            esp = esp - 0x18;
                            eax = sub_483ae7(arg_0, arg_4, arg_8, arg_10, arg_14, arg_18);
                            break;
                    }
            }
            break;
    }
    return eax;
}
