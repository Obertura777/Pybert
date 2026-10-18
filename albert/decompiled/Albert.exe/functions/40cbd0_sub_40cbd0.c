// sub_40cbd0 @ 0x40cbd0
// hopper name: sub_40cbd0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40cbd0() {
    decomp_var_c = *0x0;
    *0x0 = &decomp_var_c;
    esi = ecx;
    sub_4706e0();
    SendMessageA(esi[0x8], 0x80, 0x1, esi[0x32]);
    esp = esp - 0x58;
    SendMessageA(esi[0x8], 0x80, 0x0, esi[0x32]);
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            (*(*eax + 0xc))() + 0x10;
            eax = sub_47020b();
            if (eax == 0x0) {
                    eax = sub_40b5a0(0x80004005);
            }
            else {
                    (*(*eax + 0xc))() + 0x10;
                    sub_476779(0x7);
                    sub_40c620();
                    decomp_var_8 = 0x0;
                    decomp_var_c = esi;
                    edx = &arg_4;
                    esp = esp - 0x14;
                    decomp_var_10 = edx;
                    if (sub_45ecd0() == 0x0) {
                            esp = esp - 0xc;
                            sub_4700ea("Couldn't initialise Bot", 0x0, 0x0);
                            edx = *(*esi + 0x154);
                            (edx)();
                    }
                    eax = arg_10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = saved_fp - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    eax = 0x1;
                    *0x0 = arg_18;
            }
    }
    return eax;
}
