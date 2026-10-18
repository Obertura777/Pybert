// sub_470f58 @ 0x470f58
// hopper name: sub_470f58
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470f58() {
    esi = ecx;
    eax = esi[0xb];
    esp = esp - 0x8;
    *esi = 0x4b2ad0;
    if (eax != 0x0) {
            esp = esp - 0x4;
            UnhookWindowsHookEx(saved_fp);
    }
    eax = esi[0xa];
    if (eax != 0x0) {
            esp = esp - 0x4;
            UnhookWindowsHookEx(saved_fp);
    }
    esi = esi[0x3];
    if (esi != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    return;
}
