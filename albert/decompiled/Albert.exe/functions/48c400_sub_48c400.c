// sub_48c400 @ 0x48c400
// hopper name: sub_48c400
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c400() {
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
    while (true) {
            eax = *(int8_t *)esi;
            eax = eax | eax;
            if (eax == 0x0) {
                    break;
            }
            esi = esi + 0x1;
            BIT_TEST(var_24, eax);
            if (BIT_TEST(var_24, eax)) {
                    continue;
            }
            eax = esi - 0x1;
            break;
    }
    return eax;
}
