// sub_476336 @ 0x476336
// hopper name: sub_476336
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476336() {
    eax = sub_4715ba();
    var_4 = eax;
    arg_0 = arg_0 & !eax[0x6];
    if (arg_0 == 0x0) {
            eax = 0x1;
    }
    else {
            decomp_var_38 = ebx;
            decomp_var_3c = esi;
            decomp_var_40 = edi;
            esi = 0x0;
            eax = sub_47ba40(&var_34, 0x0, 0x28);
            *(sub_4715ba() + 0x8);
            esp = ((esp - 0x18) + 0xc - 0x4) + 0x4;
            var_C = 0x8;
            if ((arg_0 & 0x1) != 0x0) {
                    esp = esp - 0x4;
                    var_34 = 0xb;
                    if (sub_476152() != 0x0) {
                            esi = 0x1;
                    }
            }
            if ((arg_0 & 0x20) != 0x0) {
                    var_34 = var_34 | 0x8b;
                    esp = esp - 0x4;
                    if (sub_476152() != 0x0) {
                            esi = esi | 0x20;
                    }
            }
            if ((arg_0 & 0x2) != 0x0) {
                    esp = esp - 0x4;
                    if (sub_476152() != 0x0) {
                            esi = esi | 0x2;
                    }
            }
            if ((arg_0 & 0x4) != 0x0) {
                    esp = esp - 0xc;
                    var_34 = 0x8;
                    eax = sub_4762f5(&var_34, "AfxMDIFrame80s", 0x7a01);
                    bool_23 = eax == 0x0;
                    if (eax != 0x0) {
                            esi = esi | 0x4;
                    }
            }
            if (!bool_23) {
                    esp = esp - 0xc;
                    var_34 = 0xb;
                    eax = sub_4762f5(&var_34, "AfxFrameOrView80s", 0x7a02);
                    if (eax != 0x0) {
                            esi = esi | 0x8;
                    }
            }
            if ((arg_0 & 0x10) != 0x0) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x3fc0);
                    esi = esi | eax;
                    arg_0 = arg_0 & 0xffffc03f;
            }
            if ((arg_0 & 0x40) != 0x0) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x40);
                    esi = esi | eax;
            }
            bool_19 = (arg_0 & 0x80) == 0x0;
            bool_18 = (arg_0 & 0x80) == 0x0;
            bool_17 = (arg_0 & 0x80) == 0x0;
            bool_16 = (arg_0 & 0x80) == 0x0;
            bool_15 = (arg_0 & 0x80) == 0x0;
            bool_14 = (arg_0 & 0x80) == 0x0;
            bool_13 = (arg_0 & 0x80) == 0x0;
            bool_12 = (arg_0 & 0x80) == 0x0;
            bool_11 = (arg_0 & 0x80) == 0x0;
            bool_10 = (arg_0 & 0x80) == 0x0;
            bool_9 = (arg_0 & 0x80) == 0x0;
            if ((arg_0 & 0x80) != 0x0) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x80);
                    esi = esi | eax;
            }
            if (!bool_19) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x100);
                    esi = esi | eax;
            }
            if (!bool_18) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x200);
                    esi = esi | eax;
            }
            if (!bool_17) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x400);
                    esi = esi | eax;
            }
            if (!bool_16) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x800);
                    esi = esi | eax;
            }
            if (!bool_15) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x1000);
                    esi = esi | eax;
            }
            if (!bool_14) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x2000);
                    esi = esi | eax;
            }
            if (!bool_13) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x4000);
                    esi = esi | eax;
            }
            if (!bool_12) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x8000);
                    esi = esi | eax;
            }
            if (!bool_11) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x10000);
                    esi = esi | eax;
            }
            if (!bool_10) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x20000);
                    esi = esi | eax;
            }
            if (!bool_9) {
                    esp = esp - 0x8;
                    eax = sub_474019(&var_C, 0x40000);
                    esi = esi | eax;
            }
            ecx = var_4;
            ecx[0x6] = ecx[0x6] | esi;
            eax = ecx[0x6];
            if ((eax & 0x3fc0) == 0x3fc0) {
                    ecx[0x6] = eax | 0x10;
                    esi = esi | 0x10;
            }
            eax = (-((esi & arg_0) - arg_0) - -((esi & arg_0) - arg_0) + CARRY(EFLAGS(cf))) + 0x1;
    }
    return eax;
}
