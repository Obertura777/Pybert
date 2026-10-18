// sub_470f0a @ 0x470f0a
// hopper name: sub_470f0a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470f0a() {
    esi = ecx;
    esp = esp - 0x8;
    if (InterlockedDecrement() == 0x0) {
            eax = esi[0x7];
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    (*(*eax + 0x8))();
                    esi[0x7] = esi[0x7] & 0x0;
            }
            eax = esi[0x2];
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    (*(*eax + 0x8))();
                    esi[0x2] = esi[0x2] & 0x0;
            }
    }
    return;
}
