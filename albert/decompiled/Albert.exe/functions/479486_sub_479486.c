// sub_479486 @ 0x479486
// hopper name: sub_479486
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479486() {
    sub_47d6bb(0xc);
    esi = sub_4715ba();
    sub_478104();
    edi = esi + 0x34;
    decomp_var_10 = 0x4b0b18;
    esp = esp - 0x14;
    decomp_var_14 = 0x0;
    sub_4784da(decomp_var_14, 0x4b0b18, &decomp_var_14);
    while (*(decomp_var_10 - 0xc) != 0x0) {
            UnregisterClassA(decomp_var_10, *(sub_4715ba() + 0x8));
            decomp_var_10 = 0x4b0b18;
            decomp_var_14 = &decomp_var_18;
            eax = sub_4784da(decomp_var_14, 0x4b0b18, &decomp_var_14);
            esp = esp - 0x18;
            sub_40c410(eax);
            sub_40b670();
    }
    sub_40b800();
    sub_478171();
    sub_40b670();
    eax = sub_47d75a();
    return eax;
}
