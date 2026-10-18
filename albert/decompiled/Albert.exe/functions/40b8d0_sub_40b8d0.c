// sub_40b8d0 @ 0x40b8d0
// hopper name: sub_40b8d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b8d0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = *esi;
    edx = *(eax - 0x8);
    ecx = 0x1 - *((eax - 0x10) + 0xc);
    eax = arg_0;
    if ((ecx | edx - eax) < 0x0) {
            esp = esp - 0x4;
            sub_40b860(eax, decomp_var_4);
    }
    eax = *esi;
    return eax;
}
