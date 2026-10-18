// sub_493d7e @ 0x493d7e
// hopper name: sub_493d7e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493d7e() {
    ebx = ebx | 0xffffffff;
    esi = sub_46f313();
    edi = *(sub_4715ba() + 0x4);
    esp = esp - 0x1c;
    if (sub_479a81(arg_10, arg_14, arg_18, arg_1c) != 0x0) {
            if (edi != 0x0) {
                    if ((*(*edi + 0x90))() != 0x0) {
                            eax = *esi;
                            eax = (eax[0x14])();
                            if (eax == 0x0) {
                                    if (esi[0x8] != eax) {
                                            (*(*esi[0x8] + 0x60))();
                                    }
                                    eax = *esi;
                                    eax = (eax[0x1a])();
                            }
                            else {
                                    eax = *esi;
                                    eax = (eax[0x15])();
                            }
                            ebx = eax;
                            sub_479525();
                            eax = ebx;
                    }
                    else {
                            sub_479525();
                            eax = ebx;
                    }
            }
            else {
                    eax = *esi;
                    eax = (eax[0x14])();
                    if (eax == 0x0) {
                            if (esi[0x8] != eax) {
                                    (*(*esi[0x8] + 0x60))();
                            }
                            eax = *esi;
                            eax = (eax[0x1a])();
                    }
                    else {
                            eax = *esi;
                            eax = (eax[0x15])();
                    }
                    ebx = eax;
                    sub_479525();
                    eax = ebx;
            }
    }
    else {
            sub_479525();
            eax = ebx;
    }
    return eax;
}
