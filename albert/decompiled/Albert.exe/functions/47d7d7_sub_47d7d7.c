// sub_47d7d7 @ 0x47d7d7
// hopper name: sub_47d7d7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d7d7() {
    eax = arg_0;
    ecx = 0x0;
    while (true) {
            if (eax == *(ecx * 0x8 + 0x4c8e30)) {
                    eax = *(ecx * 0x8 + 0x4c8e34);
                    temp_0 = 0x0;
                    break;
            }
            ecx = ecx + 0x1;
            if (ecx < 0x2d) {
                    continue;
            }
            if (eax <= 0x24) {
                    eax = 0xd;
                    temp_0 = 0x1;
            }
            else {
                    eax = (eax + 0xffffff44 - eax + 0xffffff44 + CARRY(EFLAGS(cf)) & 0xe) + 0x8;
                    temp_0 = 0x1;
            }
            break;
    }
    return eax;
}
