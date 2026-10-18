// sub_401e30 @ 0x401e30
// hopper name: sub_401e30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401e30() {
    eax = sub_46dbce(0x14);
    if (eax != 0x0) {
            *eax = 0x0;
    }
    ecx = eax + 0x4;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    ecx = eax + 0x8;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    eax[0x10] = 0x1;
    eax[0x11] = 0x0;
    return;
}
