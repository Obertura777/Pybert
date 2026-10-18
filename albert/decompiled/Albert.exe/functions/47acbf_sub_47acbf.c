// sub_47acbf @ 0x47acbf
// hopper name: sub_47acbf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47acbf() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    if (esi == *(sub_480086() + 0x98)) {
            *(sub_480086() + 0x98) = esi[0x1];
    }
    else {
            eax = sub_480086();
            eax = eax[0x26];
            while (true) {
                    if (eax[0x1] != 0x0) {
                            ecx = eax[0x1];
                            if (esi != ecx) {
                                    eax = ecx;
                                    continue;
                            }
                            eax[0x1] = esi[0x1];
                            temp_0 = 0x0;
                            break;
                    }
                    sub_4810dd();
                    temp_0 = 0x1;
                    break;
            }
    }
    return;
}
