// sub_406a90 @ 0x406a90
// hopper name: sub_406a90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_406a90() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = sub_46dbce(0x80);
    esp = (esp - 0x2c) + 0x4;
    if (esi != 0x0) {
            *esi = arg_0;
            esi[0x1] = arg_4;
            esi[0x2] = arg_8;
            esi[0x3] = *arg_c;
            esp = esp - 0x4;
            sub_4065f0(arg_c + 0x4);
            esi[0x7c] = arg_10;
            esi[0x7d] = 0x0;
    }
    eax = esi;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
