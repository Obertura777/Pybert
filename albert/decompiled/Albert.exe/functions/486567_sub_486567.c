// sub_486567 @ 0x486567
// hopper name: sub_486567
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486567() {
    var_4 = edi;
    edi = arg_0;
    ecx = arg_4 >> 0x7;
    xmm0 = intrinsic_pxor(xmm0, xmm0);
    do {
            *(int128_t *)edi = intrinsic_movdqa(*(int128_t *)edi, xmm0);
            edi[0x1] = intrinsic_movdqa(edi[0x1], xmm0);
            edi[0x2] = intrinsic_movdqa(edi[0x2], xmm0);
            edi[0x3] = intrinsic_movdqa(edi[0x3], xmm0);
            edi[0x4] = intrinsic_movdqa(edi[0x4], xmm0);
            edi[0x5] = intrinsic_movdqa(edi[0x5], xmm0);
            edi[0x6] = intrinsic_movdqa(edi[0x6], xmm0);
            edi[0x7] = intrinsic_movdqa(edi[0x7], xmm0);
            edi = edi + 0x80;
            ecx = ecx - 0x1;
    } while (ecx != 0x0);
    &var_4 = ebp;
    return;
}
