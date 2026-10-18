// sub_401050 @ 0x401050
// hopper name: sub_401050
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401050() {
    decomp_var_4 = esi;
    esi = ecx;
    eax = *esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    if (eax == 0x0 || eax != *edi) {
            sub_47a948();
    }
    eax = esi[0x1] != edi[0x1] ? 0x1 : 0x0;
    return eax;
}
