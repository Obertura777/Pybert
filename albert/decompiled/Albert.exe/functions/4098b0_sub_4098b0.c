// sub_4098b0 @ 0x4098b0
// hopper name: sub_4098b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4098b0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_54 = ebx;
    decomp_var_58 = ebp;
    decomp_var_5c = esi;
    decomp_var_60 = edi;
    esp = esp - 0x64;
    decomp_var_64 = *dword_4c8db8 ^ &decomp_var_60;
    *0x0 = &var_C;
    ebp = ecx;
    eax = sub_40ff50();
    var_24 = eax;
    eax[0x15] = 0x1;
    var_24[0x1] = var_24;
    *var_24 = var_24;
    var_24[0x2] = var_24;
    edi = &arg_2454;
    ebx = edi;
    esi = *edi[0x1];
    var_50 = ebx;
    var_4C = esi;
    goto loc_409925;

loc_409925:
    var_3C = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (esi != var_3C) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            esi[0x10] = esi[0x8];
            esi[0x69] = 0x0;
            esi[0x6b] = 0x0;
            sub_401390();
            esi = var_4C;
            ebx = var_50;
            continue;
    }
    break;
    if (arg_24AB != 0x0) {
            sub_402360();
    }
    esi = edi;
    ebp = *edi[0x1];
    var_50 = esi;
    var_4C = ebp;
    goto loc_409994;

loc_409994:
    ebx = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (ebp != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            if (arg_38 != 0x7) {
                    sub_401390();
                    ebp = var_4C;
                    esi = var_50;
                    continue;
            }
            ebx = &arg_1c;
            esp = esp - 0x8;
            eax = sub_402140(&var_30, ebx, decomp_var_64, decomp_var_60, decomp_var_5c);
            esi = *eax;
            var_44 = eax[0x1];
            var_34 = var_24;
            if (esi == 0x0 || esi != &var_28) {
                    sub_47a948();
            }
            if (var_44 != var_34) {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (var_44 == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_407720(var_44 + 0x10);
                    eax[0x5b] = 0x0;
                    eax[0x59] = 0x1;
                    sub_401390();
                    ebp = var_4C;
                    esi = var_50;
                    continue;
            }
            var_40 = *ebx;
            esp = esp - 0x8;
            eax = sub_405120(&var_1C, &var_40, decomp_var_64);
            sub_401390();
            ebp = var_4C;
            esi = var_50;
            continue;
    }
    break;
    sub_403b00(&var_30, &var_28, *var_24, &var_28, var_24);
    eax = sub_47c8f9();
    *0x0 = var_C;
    &var_50 = decomp_var_58;
    return eax;
}
