// sub_406b40 @ 0x406b40
// hopper name: sub_406b40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_406b40() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = sub_46dbce(0x2c);
    esp = (esp - 0x2c) + 0x4;
    if (esi != 0x0) {
            esp = esp - 0x14;
            sub_406830(arg_0, arg_4, arg_8, arg_c, arg_10);
    }
    eax = esi;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
