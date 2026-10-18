// sub_427570 @ 0x427570
// hopper name: sub_427570
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_427570() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = sub_46dbce(0xf0);
    esp = (esp - 0x2c) + 0x4;
    if (esi != 0x0) {
            *esi = arg_0;
            esi[0x1] = arg_4;
            esi[0x2] = arg_8;
            esi[0x4] = *arg_c;
            esp = esp - 0x4;
            sub_4222a0(arg_c + 0x8);
            esi[0xe8] = arg_10;
            esi[0xe9] = 0x0;
    }
    eax = esi;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
