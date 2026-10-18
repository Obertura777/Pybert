// sub_4028a0 @ 0x4028a0
// hopper name: sub_4028a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4028a0() {
    sub_4019f0(*(ecx[0x1] + 0x4));
    eax = ecx[0x1];
    eax[0x1] = eax;
    eax = ecx[0x1];
    ecx[0x2] = 0x0;
    *eax = eax;
    esi = ecx[0x1];
    esi[0x2] = esi;
    return eax;
}
