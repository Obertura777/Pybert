// sub_40b630 @ 0x40b630
// hopper name: sub_40b630
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b630() {
    esi = arg_4;
    edi = arg_0;
    decomp_var_c = 0x6;
    decomp_var_10 = (esi >> 0x4) + 0x1 & 0xffff;
    esp = esp - 0x14;
    eax = FindResourceA(edi, decomp_var_10, 0x6);
    if (eax != 0x0) {
            eax = sub_40b5c0(edi, eax, esi);
    }
    return eax;
}
