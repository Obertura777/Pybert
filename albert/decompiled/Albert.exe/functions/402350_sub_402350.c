// sub_402350 @ 0x402350
// hopper name: sub_402350
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402350() {
    if (ecx[0x6] >= 0x10) {
            eax = ecx[0x1];
    }
    else {
            eax = ecx + 0x4;
    }
    return eax;
}
