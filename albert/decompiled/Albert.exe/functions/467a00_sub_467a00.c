// sub_467a00 @ 0x467a00
// hopper name: sub_467a00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467a00() {
    var_C = *0x0;
    *0x0 = &var_C;
    esi = ecx;
    var_98 = esi;
    esi[0x1] = arg_8;
    var_4 = 0x0;
    *esi = 0x4b1cfc;
    sub_4678b0(0x4b1d28);
    eax = sub_493123(&var_94);
    esi[0x2] = *eax;
    esi[0x3] = eax[0x1];
    esi[0x4] = eax[0x2];
    esp = (esp - 0xac) + 0x4;
    esi[0x5] = eax[0x3];
    sub_467490();
    edi = arg_0;
    if (edi != 0x0) {
            eax = esi[0x5];
            bool_2 = eax >= 0x0;
            if (eax > 0x0) {
                    esp = esp - 0x4;
                    sub_47c8f9();
                    esp = esp + 0x4;
            }
            else {
                    if (!bool_2) {
                            esp = esp - 0x4;
                            sub_47c8f9();
                            esp = esp + 0x4;
                    }
            }
            esi[0x4] = edi;
            esi[0x5] = -arg_10 - -arg_10 + CARRY(EFLAGS(cf));
    }
    *0x0 = saved_fp;
    eax = sub_47ad69();
    return eax;
}
