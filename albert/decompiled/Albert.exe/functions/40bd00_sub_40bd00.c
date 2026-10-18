// sub_40bd00 @ 0x40bd00
// hopper name: sub_40bd00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bd00() {
    eax = arg_0;
    if (eax > 0x50) {
            sub_46dedc();
    }
    eax = (*((eax[0x40bd34] & 0xff) * 0x4 + 0x40bd24))();
    return eax;
}
