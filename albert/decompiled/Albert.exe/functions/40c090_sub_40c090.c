// sub_40c090 @ 0x40c090
// hopper name: sub_40c090
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c090() {
    decomp_var_c = *0x0;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    decomp_var_1c = *dword_4c8db8 ^ &decomp_var_18;
    *0x0 = &decomp_var_c;
    esi = ecx;
    esp = esp - 0x24;
    sub_470381(0x66, arg_0);
    *esi = 0x4af794;
    sub_4727e8();
    esi[0x1d] = 0x4af5d4;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            esi[0x33] = (*(*eax + 0xc))() + 0x10;
            sub_4727e8();
            esi[0x34] = 0x4af5d4;
            sub_4715ba();
            esi[0x32] = LoadIconA(*(sub_4715ba() + 0xc), 0x80);
            eax = esi;
            *0x0 = decomp_var_c;
    }
    return eax;
}
