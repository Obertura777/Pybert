// CCD_Handler @ 0x45e470
// hopper name: sub_45e470
// pybert name: CCD_Handler
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

CCD_Handler() {
    decomp_var_c = *0x0;
    decomp_var_38 = ebp;
    decomp_var_3c = esi;
    decomp_var_40 = edi;
    esp = esp - 0x44;
    decomp_var_44 = *dword_4c8db8 ^ &decomp_var_40;
    *0x0 = &decomp_var_c;
    edi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_28 = (*(*eax + 0xc))() + 0x10;
            decomp_var_2c = 0x0;
            sub_466060(&decomp_var_1c, 0x1);
            sub_4658f0(&decomp_var_2e);
            sub_465fa0();
            sub_45cd40(&decomp_var_34);
            esi = edi + 0xc;
            esp = esp - 0x18;
            decomp_var_20 = edi[0x4];
            eax = sub_4108a0(&decomp_var_1c, &decomp_var_34, decomp_var_44, decomp_var_40, decomp_var_3c);
            eax = *eax;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_20) {
                    esp = esp - 0x8;
                    sub_418ed0(&decomp_var_1c, &decomp_var_34, decomp_var_44);
                    decomp_var_2c = 0x1;
            }
            esp = esp - 0x8;
            (*(*edi + 0x14))(arg_0, decomp_var_2c);
            eax = decomp_var_28 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    decomp_var_48 = eax;
                    eax = *(**eax + 0x4);
                    eax = (eax)(decomp_var_48);
            }
            *0x0 = decomp_var_c;
    }
    return eax;
}
