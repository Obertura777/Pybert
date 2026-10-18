// sub_402aa0 @ 0x402aa0
// hopper name: sub_402aa0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402aa0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    *esi = 0x4af470;
    if (esi[0x9] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x9] = 0xf;
    esi[0x8] = 0x0;
    esi[0x10] = 0x0;
    eax = sub_47a73c();
    return eax;
}
