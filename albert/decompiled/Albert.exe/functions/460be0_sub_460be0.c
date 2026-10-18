// sub_460be0 @ 0x460be0
// hopper name: sub_460be0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460be0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    ebp = *ecx[0x915];
    decomp_var_1c = esi;
    esp = esp - 0x20;
    var_20 = edi;
    edi = ecx + 0x2450;
    esi = edi;
    var_C = ecx;
    var_8 = esi;
    var_4 = ebp;
    &var_20 = &var_20;
    goto loc_460c10;

loc_460c10:
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
            sub_401390();
            ebp = var_4;
            esi = var_8;
            continue;
    }
    break;
    ebp = *var_C[0x918];
    edi = var_C + 0x245c;
    esi = edi;
    var_8 = esi;
    var_4 = ebp;
    goto loc_460c70;

loc_460c70:
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
            sub_401390();
            ebp = var_4;
            esi = var_8;
            continue;
    }
    break;
    ebx = var_C;
    ebp = *(ebx[0x91e] + 0x4);
    edi = ebx + 0x2474;
    esi = ebp;
    if (arg_11 == 0x0) {
            &var_20 = &var_20;
            do {
                    sub_40fb70(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = esi;
            } while (esi[0x19] == 0x0);
    }
    eax = edi[0x1];
    eax[0x1] = eax;
    eax = edi[0x1];
    edi[0x2] = 0x0;
    *eax = eax;
    edi = edi[0x1];
    edi[0x2] = edi;
    ebx[0x920] = 0x0;
    &decomp_var_10 = decomp_var_18;
    return eax;
}
