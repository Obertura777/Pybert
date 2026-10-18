// sub_486a18 @ 0x486a18
// hopper name: sub_486a18
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486a18() {
    if (arg_0 != 0x0) {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            esi = arg_4;
            if ((esi[0x6] & 0x1000) != 0x0) {
                    sub_47c365(esi);
                    esi[0x3] = esi[0x3] & 0xffffeeff;
                    esi[0x6] = esi[0x6] & 0x0;
                    *esi = *esi & 0x0;
                    esi[0x2] = esi[0x2] & 0x0;
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return;
}
