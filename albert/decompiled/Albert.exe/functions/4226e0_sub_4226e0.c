// sub_4226e0 @ 0x4226e0
// hopper name: sub_4226e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4226e0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    ecx = esi[0x1];
    eax = *ecx;
    *ecx = ecx;
    ecx = esi[0x1];
    ecx[0x1] = ecx;
    bool_0 = eax == esi[0x1];
    esi[0x2] = 0x0;
    if (!bool_0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            do {
                    edi = *eax;
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    eax = edi;
            } while (edi != esi[0x1]);
            esp = esp + 0x4;
    }
    eax = esi[0x1];
    eax = *eax;
    eax = sub_4054c0(esi, eax, arg_0, arg_4, arg_8, arg_c);
    return eax;
}
