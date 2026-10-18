// sub_47f5c8 @ 0x47f5c8
// hopper name: sub_47f5c8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f5c8() {
    sub_47aea2(arg_0);
    eax = arg_4 & 0xff;
    if (!CPU_FLAGS & NE) {
            if (arg_8 != 0x0) {
                    eax = *(int16_t *)(var_10[0x32] + eax * 0x2) & 0xffff;
                    eax = eax & arg_8;
            }
            else {
                    eax = 0x0;
            }
            if (eax != 0x0) {
                    eax = 0x1;
            }
    }
    else {
            eax = 0x1;
    }
    if (var_4 != 0x0) {
            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
    }
    return eax;
}
