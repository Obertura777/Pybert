// sub_470f8d @ 0x470f8d
// hopper name: sub_470f8d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470f8d() {
    esi = ecx;
    ecx = esi[0xf];
    esp = esp - 0x8;
    *esi = 0x4b2ad8;
    if (ecx != 0x0) {
            (*(*ecx + 0x13c))();
    }
    sub_47c8f9();
    esp = (esp - 0x4) + 0x4;
    ecx = esi[0x5];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = esi[0x6];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = esi[0x7];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = esi[0x8];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = esi[0x9];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    eax = esi[0xe];
    if (eax != 0x0) {
            while (eax[0x3] != 0x0) {
                    loc_479455();
                    sub_47c8f9();
                    eax = esi[0xe];
                    esp = (esp - 0x4) + 0x4;
            }
    }
    ecx = esi[0xc];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x4))();
    }
    ecx = esi[0xd];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x4))();
    }
    ecx = esi[0xe];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x4))();
    }
    return;
}
