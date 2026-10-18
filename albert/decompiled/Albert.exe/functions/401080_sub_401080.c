// sub_401080 @ 0x401080
// hopper name: sub_401080
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401080() {
    eax = arg_0;
    ecx = eax[0x2];
    if (ecx[0x11] == 0x0) {
            do {
                    eax = ecx;
                    ecx = eax[0x2];
            } while (ecx[0x11] == 0x0);
    }
    return eax;
}
