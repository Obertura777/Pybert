// sub_406740 @ 0x406740
// hopper name: sub_406740
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_406740() {
    *ecx = *arg_0;
    sub_405e40(arg_4);
    *(ecx + 0x10) = arg_4[0x3];
    *(ecx + 0x14) = arg_4[0x4];
    eax = ecx;
    *(int8_t *)(ecx + 0x18) = arg_4[0x14];
    return eax;
}
