// sub_478e2a @ 0x478e2a
// hopper name: sub_478e2a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478e2a() {
    esp = esp - 0x4;
    esi = ecx;
    ecx = arg_4 + 0x40;
    esi[0x1] = arg_4;
    if (ecx < arg_4) {
            eax = 0x0;
    }
    else {
            esp = esp - 0x8;
            eax = GlobalAlloc(0x40, ecx);
            *esi = eax;
            if (eax != 0x0) {
                    edi = GlobalLock(eax);
                    eax = esi[0x1];
                    sub_46dc09(edi, eax, arg_4, eax);
                    eax = sub_478cea(edi);
                    decomp_var_8 = *esi;
                    esi[0x2] = (--eax - --eax + CARRY(EFLAGS(cf))) + 0x1;
                    GlobalUnlock(decomp_var_8);
                    eax = 0x1;
                    esp = ((esp - 0x1c) + 0x14 - 0x4) + 0x4;
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
