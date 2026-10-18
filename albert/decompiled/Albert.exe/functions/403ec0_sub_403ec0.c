// sub_403ec0 @ 0x403ec0
// hopper name: sub_403ec0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_403ec0() {
    var_C = *0x0;
    decomp_var_54 = esi;
    esp = esp - 0x58;
    var_58 = *dword_4c8db8 ^ &decomp_var_54;
    *0x0 = &var_C;
    eax = ecx[0x2];
    edx = arg_0;
    if (0x3fffffff - eax < edx) {
            decomp_var_5c = 0x10;
            decomp_var_60 = "list<T> too long";
            var_3C = 0x0;
            sub_402650("list<T> too long", 0x10);
            sub_402a30(&var_58);
            ecx = &var_3C;
            esp = esp - 0x14;
            eax = sub_47a958(ecx, 0x4bb9a4);
    }
    eax = eax + edx;
    ecx[0x2] = eax;
    *0x0 = var_14;
    return eax;
}
