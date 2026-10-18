// sub_46bed0 @ 0x46bed0
// hopper name: sub_46bed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46bed0() {
    var_C = *0x0;
    decomp_var_2c = esi;
    decomp_var_30 = edi;
    decomp_var_34 = *dword_4c8db8 ^ &decomp_var_30;
    *0x0 = &var_C;
    ebp = arg_0;
    esi = ecx;
    ebx = esi[0x1];
    esp = esp - 0x3c;
    var_4 = 0x0;
    eax = sub_467570(&var_1C, ebp, decomp_var_34, decomp_var_30, decomp_var_2c);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebx) {
            edi = esi + 0xc;
            var_18 = esi[0x4];
            esp = esp - 0x8;
            eax = sub_4675e0(&var_14, &arg_4, decomp_var_34, decomp_var_30, decomp_var_2c);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (ebx[0x1] == var_18) {
                    sub_4273a0(ebp);
                    eax = sub_4024f0(&arg_4, 0x0, 0xffffffff);
                    esi = *(int16_t *)ebp & 0xffff;
                    esp = esp - 0x14;
                    eax = sub_45f570(&var_4);
                    ebx = var_29;
                    *(int16_t *)eax = esi;
            }
            else {
                    ebx = 0x0;
            }
    }
    else {
            ebx = 0x0;
    }
    if (arg_30 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = ebx;
    *0x0 = arg_4;
    return eax;
}
