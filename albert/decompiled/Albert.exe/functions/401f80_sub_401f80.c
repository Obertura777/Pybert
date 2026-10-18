// sub_401f80 @ 0x401f80
// hopper name: sub_401f80
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401f80() {
    decomp_var_c = ebx;
    ebx = arg_4;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esi = arg_8;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = ecx;
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1 = esi == edi[0x1];
    ebp = *esi;
    if (!bool_1) {
            *esi[0x1] = ebp;
            *(*esi + 0x4) = esi[0x1];
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            edi[0x2] = edi[0x2] - 0x1;
    }
    eax = arg_0;
    eax[0x1] = ebp;
    *eax = ebx;
    return eax;
}
