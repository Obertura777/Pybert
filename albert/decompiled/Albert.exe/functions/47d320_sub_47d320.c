// sub_47d320 @ 0x47d320
// hopper name: sub_47d320
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d320() {
    esp = esp - 0x20;
    var_24 = 0x0;
    edx = arg_4;
    while (true) {
            eax = *(int8_t *)edx;
            eax = eax | eax;
            if (eax == 0x0) {
                    break;
            }
            edx = edx + 0x1;
            BIT_TEST_AND_SET(var_24, eax);
    }
    esi = arg_0;
    ecx = ecx | 0xffffffff;
    do {
            ecx = ecx + 0x1;
            eax = *(int8_t *)esi;
            eax = eax | eax;
            if (eax == 0x0) {
                    break;
            }
            esi = esi + 0x1;
            BIT_TEST(var_24, eax);
    } while (BIT_TEST(var_24, eax));
    eax = ecx;
    return eax;
}
