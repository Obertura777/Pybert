// sub_4865be @ 0x4865be
// hopper name: sub_4865be
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4865be() {
    var_4 = edi;
    eax = arg_0;
    edi = ((eax ^ (eax & 0x80000000 ? 0xffffffff : 0x0)) - (eax & 0x80000000 ? 0xffffffff : 0x0) & 0xf ^ (eax & 0x80000000 ? 0xffffffff : 0x0)) - (eax & 0x80000000 ? 0xffffffff : 0x0);
    bool_4 = true;
    if (edi == 0x0) {
            ecx = arg_8;
            edx = ecx & 0x7f;
            var_C = edx;
            if (ecx != edx) {
                    sub_486567(eax, ecx - edx);
                    esp = (esp - 0x8) + 0x8;
                    eax = arg_0;
                    edx = var_C;
            }
            bool_2 = true;
            if (edx != 0x0) {
                    asm { rep stosb  byte [edi], al };
                    eax = arg_0;
            }
    }
    else {
            var_10 = -edi + 0x10;
            asm { rep stosb  byte [edi], al };
            sub_4865be(arg_0 + var_10, 0x0, arg_8 - var_10);
            esp = (esp - 0xc) + 0xc;
            eax = arg_0;
    }
    &var_10 = ebp;
    return eax;
}
