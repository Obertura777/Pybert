// sub_40c5a0 @ 0x40c5a0
// hopper name: sub_40c5a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c5a0() {
    var_C = *0x0;
    decomp_var_10 = *dword_4c8db8 ^ &var_C;
    *0x0 = &var_C;
    esp = esp - 0x14;
    sub_40c410(&arg_0);
    eax = arg_0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_14 = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_14);
    }
    *0x0 = var_C;
    return eax;
}
