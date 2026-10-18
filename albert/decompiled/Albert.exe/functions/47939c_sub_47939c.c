// sub_47939c @ 0x47939c
// hopper name: sub_47939c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47939c() {
    edi = arg_0;
    esp = esp - 0xc;
    esi = ecx;
    eax = sub_4791b2(edi, &arg_0, &var_4);
    if (eax == 0x0) {
            if (esi[0x1] == eax) {
                    esp = esp - 0x8;
                    sub_479114(esi[0x2], 0x1);
            }
            eax = sub_47934e();
            eax[0x1] = edi;
            *eax = *((arg_0 << 0x2) + esi[0x1]);
            *((arg_0 << 0x2) + esi[0x1]) = eax;
    }
    eax = eax + 0x8;
    return eax;
}
