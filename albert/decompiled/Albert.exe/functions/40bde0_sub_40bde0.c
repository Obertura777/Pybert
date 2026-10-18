// sub_40bde0 @ 0x40bde0
// hopper name: sub_40bde0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bde0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    sub_470ce3();
    if ((arg_0 & 0x1) != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi;
    return eax;
}
