// sub_40c010 @ 0x40c010
// hopper name: sub_40c010
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c010() {
    ecx = *(*ecx - 0x10);
    if (ecx != 0x0) {
            eax = *(*ecx + 0x10);
            eax = (eax)();
            if (eax == 0x0) {
                    eax = sub_47020b();
                    eax = *(*eax + 0x10);
                    eax = (eax)();
            }
    }
    else {
            eax = sub_47020b();
            eax = *(*eax + 0x10);
            eax = (eax)();
    }
    return eax;
}
