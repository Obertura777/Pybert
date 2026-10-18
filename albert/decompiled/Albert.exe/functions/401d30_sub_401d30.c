// sub_401d30 @ 0x401d30
// hopper name: sub_401d30
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401d30() {
    esi = decomp_var_14;
    if (esi[0x6] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x6] = 0xf;
    esi[0x5] = 0x0;
    esi[0x4] = 0x0;
    sub_47a958(0x0, 0x0);
    asm { int3 };
    return;
}
