// sub_406830 @ 0x406830
// hopper name: sub_406830
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_406830() {
    *ecx = arg_0;
    ecx[0x1] = arg_4;
    ecx[0x2] = arg_8;
    ecx[0x3] = *arg_c;
    sub_405e40(arg_c + 0x4);
    *(ecx + 0x1c) = *(arg_c + 0x10);
    *(ecx + 0x20) = *(arg_c + 0x14);
    *(int8_t *)(ecx + 0x24) = *(int8_t *)(arg_c + 0x18);
    ecx[0x28] = arg_10;
    ecx[0x29] = 0x0;
    eax = ecx;
    return eax;
}
