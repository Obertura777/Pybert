// sub_401850 @ 0x401850
// hopper name: sub_401850
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401850() {
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
    return eax;
}
