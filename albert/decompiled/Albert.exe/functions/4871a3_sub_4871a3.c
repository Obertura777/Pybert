// sub_4871a3 @ 0x4871a3
// hopper name: sub_4871a3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4871a3() {
    var_4 = edi;
    var_8 = esi;
    esi = arg_4;
    edi = arg_0;
    ecx = arg_8 >> 0x7;
    do {
            xmm0 = intrinsic_movdqa(xmm0, *(int128_t *)esi);
            xmm1 = intrinsic_movdqa(xmm1, esi[0x1]);
            xmm2 = intrinsic_movdqa(xmm2, esi[0x2]);
            xmm3 = intrinsic_movdqa(xmm3, esi[0x3]);
            *(int128_t *)edi = intrinsic_movdqa(*(int128_t *)edi, xmm0);
            edi[0x1] = intrinsic_movdqa(edi[0x1], xmm1);
            edi[0x2] = intrinsic_movdqa(edi[0x2], xmm2);
            edi[0x3] = intrinsic_movdqa(edi[0x3], xmm3);
            xmm4 = intrinsic_movdqa(xmm4, esi[0x4]);
            xmm5 = intrinsic_movdqa(xmm5, esi[0x5]);
            xmm6 = intrinsic_movdqa(xmm6, esi[0x6]);
            xmm7 = intrinsic_movdqa(xmm7, esi[0x7]);
            edi[0x4] = intrinsic_movdqa(edi[0x4], xmm4);
            edi[0x5] = intrinsic_movdqa(edi[0x5], xmm5);
            edi[0x6] = intrinsic_movdqa(edi[0x6], xmm6);
            edi[0x7] = intrinsic_movdqa(edi[0x7], xmm7);
            esi = esi + 0x80;
            edi = edi + 0x80;
            ecx = ecx - 0x1;
    } while (ecx != 0x0);
    &var_8 = ebp;
    return;
}
