// sub_40bdc0 @ 0x40bdc0
// hopper name: sub_40bdc0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bdc0() {
    eax = ecx[0x8];
    eax = EnableWindow(eax, 0x0);
    return eax;
}
