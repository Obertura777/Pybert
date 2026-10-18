// sub_4710b2 @ 0x4710b2
// hopper name: sub_4710b2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4710b2() {
    esp = esp - 0x4;
    sub_47d6bb(saved_fp);
    esi = ecx;
    *esi = 0x4b2ae0;
    ecx = esi[0x12];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = esi[0x1c];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0xc))();
            ecx = esi[0x1c];
            if (ecx != 0x0) {
                    esp = esp - 0x4;
                    (*(*ecx + 0x4))();
            }
    }
    ecx = *esi[0x1e];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    ecx = *(esi[0x1e] + 0x4);
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)();
    }
    sub_47c8f9();
    edi = esi + 0x80;
    eax = *edi;
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0 && eax != 0xffffffff) {
            sub_470dbf();
            *edi = *edi | 0xffffffff;
    }
    sub_477b35();
    sub_40b670();
    sub_47d75a();
    return;
}
