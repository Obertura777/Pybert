// sub_402e30 @ 0x402e30
// hopper name: sub_402e30
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402e30() {
    var_C = *0x0;
    *0x0 = &var_C;
    sub_47a6e4(arg_0);
    *ecx = 0x4af470;
    *(ecx + 0x24) = 0xf;
    *(ecx + 0x20) = 0x0;
    *(int8_t *)(ecx + 0x10) = 0x0;
    sub_4024f0(arg_0 + 0xc, 0x0, 0xffffffff);
    eax = ecx;
    *0x0 = edi;
    return eax;
}
