// sub_40b8b0 @ 0x40b8b0
// hopper name: sub_40b8b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b8b0() {
    eax = *ecx;
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            decomp_var_4 = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_4);
    }
    return eax;
}
