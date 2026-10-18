// sub_410150 @ 0x410150
// hopper name: sub_410150
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_410150() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = sub_46dbce(0x30);
    esp = (esp - 0x2c) + 0x4;
    if (esi != 0x0) {
            *esi = arg_0;
            esi[0x1] = arg_4;
            esi[0x2] = arg_8;
            esi[0x4] = *arg_c;
            esp = esp - 0x4;
            esi[0x5] = arg_c[0x1];
            sub_465f60(arg_c + 0x8);
            esi[0x28] = arg_10;
            esi[0x29] = 0x0;
    }
    eax = esi;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
