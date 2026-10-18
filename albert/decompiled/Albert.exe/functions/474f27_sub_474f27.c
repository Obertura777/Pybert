// sub_474f27 @ 0x474f27
// hopper name: sub_474f27
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474f27() {
    esp = esp - 0xc;
    if (arg_0 != 0x0) {
            esi = arg_4;
            if (esi != 0x0) {
                    ebx = arg_c;
                    if (ebx == 0x0) {
                            eax = 0x80004003;
                    }
                    else {
                            esp = esp - 0x4;
                            *ebx = *ebx & 0x0;
                            if (sub_474efc(arg_8) != 0x0) {
                                    esi = esi[0x1];
                                    esp = esp - 0x4;
                                    (*(*(esi + arg_0) + 0x4))(esi + arg_0);
                                    *ebx = esi + arg_0;
                                    eax = 0x0;
                            }
                            else {
                                    while (true) {
                                            edi = esi[0x2];
                                            if (edi == 0x0) {
                                                    eax = 0x80004002;
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    eax = *esi;
                                                    arg_4 = eax == 0x0 ? 0x1 : 0x0;
                                                    if (eax == 0x0) {
                                                            eax = sub_474ead(eax, arg_8);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax == 0x0) {
                                                                    esi = esi + 0xc;
                                                                    continue;
                                                            }
                                                            if (edi != 0x1) {
                                                                    decomp_var_10 = esi[0x1];
                                                                    esp = esp - 0x10;
                                                                    eax = (edi)(arg_0, arg_8, ebx, decomp_var_10);
                                                                    if (eax != 0x0) {
                                                                            if (arg_4 != 0x0) {
                                                                                    esi = esi + 0xc;
                                                                                    continue;
                                                                            }
                                                                            if (eax >= 0x0) {
                                                                                    esi = esi + 0xc;
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (edi != 0x1) {
                                                                    decomp_var_10 = esi[0x1];
                                                                    esp = esp - 0x10;
                                                                    eax = (edi)(arg_0, arg_8, ebx, decomp_var_10);
                                                                    if (eax != 0x0) {
                                                                            if (arg_4 != 0x0) {
                                                                                    esi = esi + 0xc;
                                                                                    continue;
                                                                            }
                                                                            if (eax >= 0x0) {
                                                                                    esi = esi + 0xc;
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    if (temp_0 != 0x0 && temp_0 != 0x1 && temp_0 != 0x2) {
                                            esi = esi[0x1];
                                            esp = esp - 0x4;
                                            (*(*(esi + arg_0) + 0x4))(esi + arg_0);
                                            *ebx = esi + arg_0;
                                            eax = 0x0;
                                    }
                            }
                    }
            }
            else {
                    eax = 0x80070057;
            }
    }
    else {
            eax = 0x80070057;
    }
    return eax;
}
