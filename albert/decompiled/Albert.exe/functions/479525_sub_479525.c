// sub_479525 @ 0x479525
// hopper name: sub_479525
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479525() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    sub_479486();
    eax = sub_4715ba();
    eax = eax[0x1];
    if (eax != 0x0) {
            eax = eax[0xf];
            if (eax != 0x0) {
                    esp = esp - 0x8;
                    (eax)(0x1, 0x0);
            }
    }
    esi = sub_4715ed();
    ecx = esi[0xf];
    if (ecx != 0x0 && (*(*ecx + 0x13c))() != 0x0) {
            esi[0xf] = 0x0;
    }
    esi = sub_471099();
    eax = sub_4715ba();
    if (eax[0x14] == 0x0) {
            eax = esi[0xb];
            esp = esp - 0x4;
            decomp_var_c = edi;
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    UnhookWindowsHookEx(eax);
                    esi[0xb] = 0x0;
            }
            eax = esi[0xa];
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    eax = UnhookWindowsHookEx(eax);
                    esi[0xa] = 0x0;
            }
            esp = esp + 0x4;
    }
    return eax;
}
