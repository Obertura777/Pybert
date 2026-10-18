// sub_482d93 @ 0x482d93
// hopper name: sub_482d93
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482d93() {
    eax = 0x0;
    if (arg_4 > 0x0) {
            ecx = arg_0;
            while (true) {
                    if (*(int8_t *)ecx == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    eax = eax + 0x1;
                    ecx = ecx + 0x1;
                    if (eax < arg_4) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
    }
    return eax;
}
