// sub_401d70 @ 0x401d70
// hopper name: sub_401d70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401d70() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    esp = esp - 0x28;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = ecx;
    ebx = arg_0;
    bool_0 = ebx[0x11] != 0x0;
    eax = esi[0x1];
    var_14 = eax;
    if (!bool_0) {
            esp = esp - 0x14;
            edi = sub_401b40(eax, arg_4, eax, ebx + 0xc, ebx[0x10] & 0xff);
            if (var_14[0x11] != 0x0) {
                    var_14 = edi;
            }
            *edi = sub_401d70(*ebx, edi);
            esp = esp - 0x10;
            edi[0x2] = sub_401d70(ebx[0x2], edi);
    }
    eax = var_14;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
