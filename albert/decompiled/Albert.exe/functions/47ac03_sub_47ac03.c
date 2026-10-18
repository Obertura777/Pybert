// sub_47ac03 @ 0x47ac03
// hopper name: sub_47ac03
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ac03() {
    edi = arg_0;
    eax = edi[0x4];
    esi = edi[0x3];
    var_4 = eax;
    ebx = esi;
    while (true) {
            arg_0 = esi;
            while (true) {
                    if (arg_4 < 0x0) {
                            esi = esi + 0x1;
                            *arg_c = esi;
                            *arg_10 = ebx;
                            if (ebx <= edi[0x3]) {
                                    if (esi > ebx) {
                                            temp_0 = 0x1;
                                    }
                                    else {
                                            temp_0 = 0x2;
                                    }
                            }
                            else {
                                    temp_0 = 0x1;
                            }
                            break;
                    }
                    else {
                            if (esi == 0xffffffff) {
                                    sub_4810dd();
                            }
                            esi = esi - 0x1;
                            eax = esi * 0x14 + var_4;
                            ecx = arg_8;
                            if (eax[0x1] < ecx) {
                                    if (ecx > eax[0x2]) {
                                            if (esi != 0xffffffff) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    else {
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                            else {
                                    if (esi != 0xffffffff) {
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
            }
            if (temp_0 == 0x0) {
                    arg_4 = arg_4 - 0x1;
                    ebx = arg_0;
                    continue;
            }
            if (temp_0 == 0x1) {
                    sub_4810dd();
            }
            break;
    }
    eax = esi * 0x14 + var_4;
    return eax;
}
