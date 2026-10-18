// sub_48722a @ 0x48722a
// hopper name: sub_48722a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48722a() {
    var_C = edi;
    var_8 = esi;
    var_4 = ebx;
    ebx = arg_4;
    eax = arg_0;
    ecx = ((ebx ^ (ebx & 0x80000000 ? 0xffffffff : 0x0)) - (ebx & 0x80000000 ? 0xffffffff : 0x0) & 0xf ^ (ebx & 0x80000000 ? 0xffffffff : 0x0)) - (ebx & 0x80000000 ? 0xffffffff : 0x0);
    edi = ((eax ^ (eax & 0x80000000 ? 0xffffffff : 0x0)) - (eax & 0x80000000 ? 0xffffffff : 0x0) & 0xf ^ (eax & 0x80000000 ? 0xffffffff : 0x0)) - (eax & 0x80000000 ? 0xffffffff : 0x0);
    if ((ecx | edi) == 0x0) {
            esi = arg_8;
            ecx = esi & 0x7f;
            var_18 = ecx;
            if (esi != ecx) {
                    sub_4871a3(eax, ebx, esi - ecx);
                    esp = (esp - 0xc) + 0xc;
                    eax = arg_0;
                    ecx = var_18;
            }
            bool_2 = true;
            if (ecx != 0x0) {
                    asm { rep movsb  byte [edi], byte [esi] };
                    eax = arg_0;
            }
    }
    else {
            bool_7 = true;
            bool_6 = true;
            bool_5 = true;
            if (ecx == edi) {
                    var_1C = -ecx + 0x10;
                    asm { rep movsb  byte [edi], byte [esi] };
                    sub_48722a(arg_0 + var_1C, arg_4 + var_1C, arg_8 - var_1C);
                    esp = (esp - 0xc) + 0xc;
                    eax = arg_0;
            }
            else {
                    *arg_0 = *arg_4;
                    asm { rep movsb  byte [edi], byte [esi] };
                    eax = arg_0;
            }
    }
    &var_1C = ebp;
    return eax;
}
