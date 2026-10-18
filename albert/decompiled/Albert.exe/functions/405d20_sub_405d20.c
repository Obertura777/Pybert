// sub_405d20 @ 0x405d20
// hopper name: sub_405d20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_405d20() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = sub_4018e0();
    ecx[0x1] = eax;
    ecx[0x2] = 0x0;
    edx = arg_0[0x1];
    sub_4054c0(ecx, *eax, arg_0, *edx, arg_0, edx);
    eax = ecx;
    *0x0 = var_C;
    &var_14 = ebp;
    return eax;
}
