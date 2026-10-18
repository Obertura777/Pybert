// sub_4619f0 @ 0x4619f0
// hopper name: sub_4619f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4619f0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_88 = ebx;
    decomp_var_8c = esi;
    decomp_var_90 = edi;
    var_94 = *dword_4c8db8 ^ &decomp_var_90;
    *0x0 = &var_C;
    esi = ecx;
    var_78 = esi;
    eax = sub_401e30();
    var_30 = eax;
    eax[0x11] = 0x1;
    var_30[0x1] = var_30;
    *var_30 = var_30;
    var_30[0x2] = var_30;
    eax = sub_401e30();
    var_3C = eax;
    eax[0x11] = 0x1;
    var_3C[0x1] = var_3C;
    *var_3C = var_3C;
    var_3C[0x2] = var_3C;
    var_38 = 0x0;
    ebx = arg_0;
    esp = esp - 0x9c;
    eax = sub_460a10(ebx, arg_4);
    var_7D = eax;
    if (eax != 0x0 || *(int16_t *)word_4c7670 != ebx[0x6] || *(int8_t *)(esi + (arg_4 + arg_4 * 0x8) * 0x4 + 0x4) == 0x0) goto loc_461c87;
    goto loc_461ac5;

loc_461c87:
    sub_403430(&var_4C, &var_40, *var_3C, &var_40, var_3C);
    sub_47c8f9();
    sub_403430(&var_4C, &var_34, *var_30, &var_34, var_30);
    sub_47c8f9();
    eax = var_7D;
    *0x0 = var_C;
    &decomp_var_84 = ebp;
    return eax;

loc_461ac5:
    esp = esp - 0x8;
    eax = sub_404ce0(&var_4C, ebx, var_94);
    eax = *ebx;
    edi = esi + (eax + eax * 0x8) * 0x4 + 0x8;
    var_74 = edi;
    var_70 = **(esi + (eax + eax * 0x8) * 0x4 + 0xc);
    &var_94 = &var_94;
    goto loc_461af0;

loc_461af0:
    eax = *ebx;
    eax = esi + (eax + eax * 0x8) * 0x4 + 0x8;
    esi = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (var_70 == esi) goto .l20;
    goto loc_461b13;

.l20:
    break;

loc_461b13:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (var_70 == edi[0x1]) {
            sub_47a948();
    }
    ebx = var_70 + 0x10;
    esi = ebx;
    var_6C = esi;
    var_68 = *var_70[0x5];
    goto loc_461b40;
    if (arg_8 != 0xffffffff) {
            esp = esp - 0x8;
            eax = sub_404ce0(&var_4C, &arg_8, var_94);
    }
    if (var_38 == 0x0) goto loc_461c87;
    goto loc_461be0;

loc_461b40:
    if (var_70 == edi[0x1]) {
            sub_47a948();
    }
    edi = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (var_68 != edi) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (var_68 == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&var_4C, var_68 + 0xc, var_94);
            sub_40f400();
            esi = var_6C;
            edi = var_74;
            continue;
    }
    break;

loc_461be0:
    if (var_7D != 0x0) goto .l17;
    goto loc_461beb;
    sub_401590();
    esi = var_78;
    edi = var_74;
    ebx = arg_0;
    continue;

.l17:
    break;

loc_461beb:
    eax = var_3C;
    esi = *eax;
    if (esi == eax) {
            sub_47a948();
            eax = var_3C;
    }
    eax = *eax;
    ebx = esi[0x3];
    eax = sub_402b70(&var_5C, &var_40, eax, var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, ebx, var_78, var_74, var_70, var_6C, var_68, decomp_var_64, var_60, var_5C);
    edi = var_30;
    esp = esp - 0x14;
    eax = sub_401ff0(&var_54, &var_7C, var_94, decomp_var_90, decomp_var_8c);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != &var_34) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_461c7a;
    goto loc_461c48;

loc_461c7a:
    if (var_38 != 0x0) {
            continue;
    }
    break;

loc_461c48:
    esp = esp - 0x8;
    eax = sub_404ce0(&var_28, &var_7C, var_94);
    esi = var_78;
    edi = esi + (ebx + ebx * 0x8) * 0x4;
    if (*(int8_t *)(esi + (ebx + ebx * 0x8) * 0x4 + 0x4) == 0x0) goto loc_461d0c;
    goto loc_461c70;

loc_461d0c:
    eax = esi[0x915];
    esi = esi + 0x2450;
    esp = esp - 0x8;
    var_60 = eax;
    eax = sub_402060(&var_4C, &var_7C, var_94, decomp_var_90, decomp_var_8c);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (ebx[0x1] == var_60) goto loc_461c7a;
    goto loc_461d4b;

loc_461c70:
    if (ebx == arg_4) {
            var_7D = 0x1;
    }
    goto loc_461c7a;

loc_461d4b:
    eax = edi + 0x8;
    ebx = eax;
    esi = *edi[0x3];
    var_7C = eax;
    var_74 = ebx;
    var_70 = esi;
    goto loc_461d63;

loc_461d63:
    edi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == edi) goto .l11;
    goto loc_461d7b;

.l11:
    break;

loc_461d7b:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = *esi[0x5];
    edi = esi + 0x10;
    esi = edi;
    var_6C = esi;
    var_68 = eax;
    goto loc_461da0;

loc_461da0:
    if (var_70 == ebx[0x1]) {
            sub_47a948();
    }
    ebx = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (var_68 != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (var_68 == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&var_1C, var_68 + 0xc, var_94);
            sub_40f400();
            esi = var_6C;
            ebx = var_74;
            continue;
    }
    break;
    sub_401590();
    eax = var_7C;
    ebx = var_74;
    esi = var_70;
    continue;
}
