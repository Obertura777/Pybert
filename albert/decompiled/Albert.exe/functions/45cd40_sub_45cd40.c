// sub_45cd40 @ 0x45cd40
// hopper name: sub_45cd40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45cd40() {
    var_C = *0x0;
    decomp_var_38 = ebx;
    decomp_var_3c = ebp;
    decomp_var_40 = esi;
    decomp_var_44 = edi;
    esp = esp - 0x48;
    decomp_var_48 = *dword_4c8db8 ^ &decomp_var_44;
    *0x0 = &var_C;
    esi = ecx;
    var_2C = esi;
    sub_465870();
    ecx = esi + 0x40;
    ebp = ecx;
    var_24 = ebp;
    esi = *esi[0x11];
    goto loc_45cd8e;

loc_45cd8e:
    edi = ecx[0x1];
    if (ebp == 0x0 || ebp != ecx) {
            sub_47a948();
    }
    if (esi != edi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_465ff0(esi + 0x18);
            var_30 = 0x0;
            ebx = 0x0;
            if (sub_4658d0() <= 0x0) {
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    esi = *esi;
                    ecx = ebp;
                    continue;
            }
            while (ebx == 0x0) {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_32, var_30);
                    edi = arg_0;
                    if (*(int16_t *)edi == *(int16_t *)eax) {
                            if (esi == arg_0) {
                                    sub_47a948();
                            }
                            if (esi[0x38] != 0x0) {
                                    esp = esp - 0x8;
                                    eax = sub_45c970(&var_24, edi);
                            }
                            else {
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    edi = esi + 0x8;
                                    if (esi == arg_0) {
                                            sub_47a948();
                                            if (esi == arg_0) {
                                                    sub_47a948();
                                            }
                                    }
                                    esp = esp - 0xc;
                                    (*(*var_2C + 0xf0))(esi[0x39] & 0xff, edi, edi + 0x20);
                            }
                            ebx = 0x1;
                    }
                    edi = var_2C + 0x1;
                    var_2C = edi;
                    if (edi >= sub_4658d0()) {
                            break;
                    }
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            esi = *esi;
            ecx = ebp;
            continue;
    }
    break;
    sub_465fa0();
    *0x0 = var_C;
    return;
}
