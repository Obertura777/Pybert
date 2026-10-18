// sub_46ebb6 @ 0x46ebb6
// hopper name: sub_46ebb6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ebb6() {
    esp = esp - 0x4;
    sub_47d6bb(0x4);
    esi = ecx;
    eax = sub_46f665();
    *esi = 0x4b250c;
    if (arg_4 != 0x0) {
            eax = sub_47dc4a(arg_4);
            esi[0x14] = eax;
    }
    else {
            esi[0x14] = 0x0;
    }
    ebx = sub_4715ba();
    if (ebx == 0x0) {
            sub_46dedc();
    }
    edi = 0x0;
    eax = sub_46e822();
    if (eax == 0x0) {
            sub_46dedc();
    }
    eax[0x1] = esi;
    esi[0xb] = GetCurrentThread();
    esi[0xc] = GetCurrentThreadId();
    ebx[0x1] = esi;
    esi[0x11] = edi;
    esi[0x1f] = edi;
    esi[0x19] = edi;
    esi[0x1a] = edi;
    esi[0x15] = edi;
    esi[0x18] = edi;
    esi[0x22] = edi;
    esi[0x16] = edi;
    esi[0x49] = edi;
    esi[0x48] = edi;
    esi[0x12] = edi;
    esi[0x23] = edi;
    esi[0x20] = edi;
    esi[0x21] = edi;
    esi[0x1c] = edi;
    esi[0x1d] = edi;
    esi[0x25] = edi;
    esi[0x27] = edi;
    esi[0x17] = edi;
    esi[0x1b] = edi;
    esi[0x26] = 0x200;
    eax = sub_47d75a();
    return eax;
}
