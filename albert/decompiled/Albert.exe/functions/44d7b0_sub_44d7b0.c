// sub_44d7b0 @ 0x44d7b0
// hopper name: sub_44d7b0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44d7b0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    var_DEC = ebx;
    decomp_var_df4 = esi;
    decomp_var_df8 = edi;
    esp = esp - 0xdfc;
    *0x0 = &var_C;
    edi = ecx;
    var_DE0 = 0x0;
    eax = sub_410050();
    var_6E4 = eax;
    eax[0x31] = 0x1;
    var_6E4[0x1] = var_6E4;
    *var_6E4 = var_6E4;
    var_6E4[0x2] = var_6E4;
    var_6E0 = 0x0;
    sub_465870();
    ecx = edi[0x2];
    eax = 0x0;
    if (ecx[0x901] > 0x0) {
            ecx = ecx[0x901];
            do {
                    *(&decomp_var_df8 + eax * 0x4 + 0x778) = 0x0;
                    *(&decomp_var_df8 + eax * 0x4 + 0x724) = 0x0;
                    eax = eax + 0x1;
            } while (eax < ecx);
    }
    esi = 0x0;
    eax = sub_466f80(&var_DA4, 0xbc1e0c);
    esp = esp - 0xc;
    sub_465ff0(eax);
    sub_465fa0();
    asm { fldz };
    ecx = var_6E0;
    asm { fst        dword [esp+0xdf8+var_CA8] };
    asm { fld        dword [dword_value_1176256512] };
    asm { fstp       dword [esp+0xdf8+var_CD0] };
    asm { fstp       dword [esp+0xdf8+var_B3C] };
    var_CE4 = esi;
    edx = ecx[0x1];
    esp = esp - 0x4;
    ecx = &var_6E4;
    sub_41c480(edx);
    var_6E0[0x1] = var_6E0;
    *var_6E0 = var_6E0;
    var_6E0[0x2] = var_6E0;
    var_DE4 = esi;
    if (*(edi[0x2] + 0x2404) > esi) {
            do {
                    *(&decomp_var_df8 + var_DE4 * 0x4 + 0x2c0) = 0x0;
                    ebx = arg_BB6F24[0x1];
                    esi = &arg_BB6F20;
                    edi = ebx;
                    if (ebx[0x11] == 0x0) {
                            do {
                                    sub_401950(edi[0x2]);
                                    edi = *edi;
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x4;
                                    ebx = edi;
                            } while (edi[0x11] == 0x0);
                    }
                    eax = esi[0x1];
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    ebx = arg_BB7024[0x1];
                    esi = &arg_BB7020;
                    edi = ebx;
                    if (ebx[0x11] == 0x0) {
                            do {
                                    sub_401950(edi[0x2]);
                                    edi = *edi;
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x4;
                                    ebx = edi;
                            } while (edi[0x11] == 0x0);
                    }
                    eax = esi[0x1];
                    ecx = var_DE0;
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    bool_29 = var_DE4 + 0x1 < *(ecx[0x2] + 0x2404);
                    var_DE4 = var_DE4 + 0x1;
            } while (bool_29);
    }
    eax = 0x0;
    ecx = ecx | 0xffffffff;
    if (arg_0[0x900] > 0x0) {
            do {
                    *(eax * 0x4 + 0xba2f70) = ecx;
                    *(&decomp_var_df8 + eax * 0x4 + 0x314) = 0x0;
                    eax = eax + 0x1;
            } while (eax < arg_0[0x900]);
    }
    asm { fldz };
    eax = 0x0;
    do {
            ebx = 0x0;
            asm { fst        dword [esp+eax*4+0xdf8+var_CA4] };
            *(&decomp_var_df8 + eax * 0x4 + 0x1cc) = ebx;
            *(&decomp_var_df8 + eax * 0x4 + 0x244) = ebx;
            eax = eax + 0x1;
    } while (eax < 0x1e);
    eax = &var_DB4;
    asm { fstp       st0 };
    sub_465f60(eax);
    sub_446540(&var_CE4);
    esp = esp - 0x10;
    sub_44d6c0(&var_DC8, &var_628, decomp_var_df8);
    saved_fp = 0x1;
    sub_42ee00();
    edi = *(*dword_bb7134 + 0x4);
    esi = edi;
    if (edi[0x19] == 0x0) {
            do {
                    sub_40fb70(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x19] == 0x0);
    }
    eax = *dword_bb7134;
    eax[0x1] = eax;
    eax = *dword_bb7134;
    *dword_bb7138 = 0x0;
    *eax = eax;
    eax = *dword_bb7134;
    eax[0x2] = eax;
    var_DD8 = 0x0;
    if (arg_0[0x900] <= 0x0) goto loc_44dc70;
    goto loc_44db57;

loc_44dc70:
    var_DD4 = 0x0;
    if (arg_0[0x900] <= 0x0) goto loc_44de11;
    goto loc_44dc95;

loc_44db57:
    var_DE4 = 0x0;
    var_DBC = &arg_2A14;
    goto loc_44db70;

loc_44de11:
    edi = 0x0;
    var_DB0 = 0x0;
    if (*(var_DD4[0x2] + 0x2404) <= 0x0) goto loc_44df93;
    goto loc_44de2a;

loc_44dc95:
    var_DD8 = 0x0;
    ebp = &arg_2A14;
    goto loc_44dcb0;

loc_44db70:
    eax = var_DE0 + arg_0;
    if (*(int8_t *)(var_DE0 + arg_0 + 0x3) != 0x0) {
            var_DD8 = var_DD8 + 0x1;
    }
    ecx = eax[0x3];
    eax = eax + 0x8;
    esi = eax;
    edi = *ecx;
    var_DD0 = eax;
    var_DCC = esi;
    var_DC8 = edi;
    goto loc_44dba0;

loc_44df93:
    esi = var_DD4;
    sub_43ee00(var_DEC, decomp_var_de8);
    ebx = 0x0;
    if (*(esi[0x2] + 0x2404) > 0x0) {
            edi = 0x0;
            do {
                    edx = 0x0;
                    if (*(esi[0x2] + 0x2400) > 0x0) {
                            do {
                                    ecx = 0x0;
                                    if (*(esi[0x2] + 0x2400) > 0x0) {
                                            eax = (edi + edx << 0xa) + 0x635578;
                                            do {
                                                    *eax = 0x0;
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x4;
                                            } while (ecx < arg_23F8);
                                    }
                                    edx = edx + 0x1;
                            } while (edx < *(esi[0x2] + 0x2400));
                    }
                    ebx = ebx + 0x1;
                    edi = edi + 0x100;
            } while (ebx < *(esi[0x2] + 0x2404));
    }
    sub_465fa0();
    sub_4225b0(&var_DBC, &var_6D8, *var_6D4, &var_6D8, var_6D4);
    eax = sub_47c8f9();
    *0x0 = ret_addr;
    &var_DD8 = var_DE0;
    return eax;

loc_44de2a:
    eax = 0x0;
    var_DD8 = 0x0;
    goto loc_44de30;

loc_44dcb0:
    edx = var_DD8[0x2];
    esi = var_DD4 + edx;
    if (*(int8_t *)(var_DD4 + edx + 0x3) == 0x0) goto loc_44ddeb;
    goto loc_44dcc9;

loc_44dba0:
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l16;
    goto loc_44dbb8;

loc_44de30:
    edx = var_DD4;
    *(edi * 0x8 + 0x4cf4c0) = 0x0;
    *(edi * 0x8 + 0x4cf4c4) = 0x0;
    ecx = 0x0;
    if (*(edx[0x2] + 0x2404) > 0x0) {
            eax[0x18a8be] = 0x0;
            eax[0x2e8a22] = 0x0;
            ecx = ecx + 0x1;
            eax = eax + 0x4;
            if (ecx < *(edx[0x2] + 0x2404)) {
                    continue;
            }
            break;
    }
    if (*(edx[0x2] + 0x2400) <= 0x0) goto loc_44df6e;
    goto loc_44de7f;

loc_44ddeb:
    var_DD0 = var_DD0 + 0x24;
    ebp = &arg_4;
    bool_10 = var_DCC + 0x1 < *(var_DD4[0x2] + 0x2400);
    var_DCC = var_DCC + 0x1;
    if (bool_10) {
            continue;
    }
    break;

loc_44dcc9:
    eax = esi[0x10];
    if (HIBYTE(eax) == 0x41) {
            var_DDC = eax & 0xff;
    }
    else {
            var_DDC = 0x14;
    }
    ebx = esi[0x6];
    esi = esi + 0x14;
    esp = esp - 0x8;
    var_DC8 = var_DD8;
    eax = sub_401ff0(&var_DB0, &var_DC8, var_DEC, decomp_var_de8, var_DE4);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebx) goto loc_44ddeb;
    goto loc_44dd1c;

.l16:
    break;

loc_44dbb8:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    ebx = *edi[0x5];
    edi = edi + 0x10;
    esi = edi;
    var_DC4 = esi;
    var_DC0 = ebx;
    goto loc_44dbe0;

loc_44df6e:
    edi = edi + 0x1;
    eax = var_DD8 + 0x54;
    var_DB0 = edi;
    var_DD8 = eax;
    if (edi < *(var_DD4[0x2] + 0x2404)) {
            continue;
    }
    break;

loc_44de7f:
    ebx = 0x0;
    var_DD0 = 0x0;
    goto loc_44de83;

loc_44dd1c:
    *(var_DCC * 0x4 + 0xba2f70) = var_DD8;
    edi = ebp;
    esi = *ret_addr;
    var_DBC = edi;
    var_DB8 = esi;
    &var_DEC = &var_DEC;
    goto loc_44dd40;
    var_DE0 = var_DE0 + 0x24;
    var_DB8 = var_DB8 + 0xc;
    bool_32 = var_DD4 + 0x1 < arg_0[0x900];
    var_DD4 = var_DD4 + 0x1;
    if (bool_32) {
            continue;
    }
    break;

loc_44dbe0:
    ebp = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (ebx != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&var_DA0, ebx + 0xc, decomp_var_df4);
            sub_40f400();
            ebx = var_DC0;
            esi = var_DC4;
            continue;
    }
    break;

loc_44de83:
    edx = var_DD4[0x2];
    eax = var_DD0 + edx + 0x8;
    esi = eax;
    edi = **(var_DD0 + edx + 0xc);
    var_DC8 = eax;
    var_DC4 = esi;
    var_DC0 = edi;
    goto loc_44dea8;

loc_44dd40:
    ebx = ret_addr;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (*(esi[0x3] * 0x4 + 0xba2f70) == 0xffffffff) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    *(esi[0x3] * 0x4 + 0xba2f70) = var_DD8;
                    sub_401520();
                    esi = var_DB8;
                    edi = var_DBC;
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (*(esi[0x3] * 0x4 + 0xba2f70) != var_DD8) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            *(esi[0x3] * 0x4 + 0xba2f70) = 0xfffffffe;
                    }
                    sub_401520();
                    esi = var_DB8;
                    edi = var_DBC;
            }
            continue;
    }
    break;
    sub_401590();
    edi = var_DC8;
    esi = var_DCC;
    eax = var_DD0;
    continue;

loc_44dea8:
    ebp = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            bool_53 = true;
            bool_52 = true;
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            var_D88 = ebx;
            var_D80 = var_6C8;
            eax = sub_419150(&var_D98, &var_D88);
            var_D88 = ebx;
            var_D80 = var_6C8;
            esp = esp - 0x10;
            eax = sub_419150(&var_DBC, &var_D88);
            sub_401590();
            edi = var_DC0;
            esi = var_DC4;
            eax = var_DC8;
            continue;
    }
    break;
    var_DD0 = var_DD0 + 0x24;
    ebx = ebx + 0x1;
    if (ebx < *(var_DD4[0x2] + 0x2400)) {
            continue;
    }
    break;
    edi = var_DB0;
    goto loc_44df6e;
}
