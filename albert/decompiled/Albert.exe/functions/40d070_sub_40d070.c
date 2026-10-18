// sub_40d070 @ 0x40d070
// hopper name: sub_40d070
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40d070() {
    ecx = sub_47b678();
    eax = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % arg_0;
    return eax;
}
