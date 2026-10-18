// sub_401820 @ 0x401820
// hopper name: sub_401820
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401820() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (*esi == 0x0) {
            sub_47a948();
    }
    eax = esi[0x1];
    eax = eax[0x1];
    ecx = *esi;
    esi[0x1] = eax;
    if (eax == ecx[0x1]) {
            sub_47a948();
    }
    eax = esi;
    return eax;
}
