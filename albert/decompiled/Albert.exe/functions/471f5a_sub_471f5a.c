// sub_471f5a @ 0x471f5a
// hopper name: sub_471f5a
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471f5a() {
    esi = ecx;
    eax = esi[0x10];
    if (eax == 0x0) {
            eax = *esi;
            eax = (eax[0x3c])();
            eax = *eax;
            if (eax == 0x0) {
                    esp = esp - 0x10;
                    eax = DefWindowProcA(esi[0x8], arg_0, arg_4, arg_8);
            }
            else {
                    esp = esp - 0x14;
                    eax = CallWindowProcA(eax, esi[0x8], arg_0, arg_4, arg_8);
            }
    }
    else {
            esp = esp - 0x14;
            eax = CallWindowProcA(eax, esi[0x8], arg_0, arg_4, arg_8);
    }
    return eax;
}
