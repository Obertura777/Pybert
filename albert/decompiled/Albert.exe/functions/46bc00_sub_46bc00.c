// sub_46bc00 @ 0x46bc00
// hopper name: sub_46bc00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46bc00() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_70 = ebx;
    var_74 = esi;
    decomp_var_78 = edi;
    esp = esp - 0x7c;
    var_7C = *dword_4c8db8 ^ &decomp_var_78;
    *0x0 = &var_C;
    HIBYTE(edx) = arg_0 & 0xff;
    esi = ecx;
    var_68 = esi;
    var_6C = 0x0;
    edx = edx & 0xffff;
    var_4 = 0x0;
    ecx = esi[0x1];
    eax = ecx[0x1];
    if (eax[0x2d] == 0x0) {
            &var_7C = &var_7C;
            do {
                    if (eax[0x6] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x2d] == 0x0);
    }
    ebx = ecx;
    edi = esi;
    var_54 = ebx;
    goto loc_46bca0;

loc_46bca0:
    var_40 = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebx != var_40) {
            var_68 = var_68 | 0x1;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x6] < var_50) {
                    eax = 0x1;
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    if ((var_64 & 0x1) != 0x0) {
            var_64 = var_64 & 0xfffffffe;
    }
    if (eax == 0x0) goto .l5;
    goto loc_46bcf7;

.l5:
    break;

loc_46bcf7:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    decomp_var_78 = 0xffffffff;
    var_7C = 0x0;
    var_80 = ebx + 0x10;
    sub_4024f0(var_80, 0x0, 0xffffffff);
    esi = esi + 0xc;
    esp = esp - 0x10;
    eax = sub_46b2a0(&var_34, var_80);
    ebx = eax;
    if (esi == 0x0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_45bcf0(&var_34, var_80);
    var_50 = eax;
    if (esi == 0x0) {
            sub_47a948();
    }
    eax = esi;
    var_68 = eax;
    var_64 = var_50;
    &var_80 = &var_80;
    goto loc_46bd60;
    if (var_10 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_4;
    eax = sub_47ad69();
    &var_64 = ebp;
    return eax;

loc_46bd60:
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (var_64 != ebx) {
            sub_40f5f0();
            eax = var_68;
            continue;
    }
    break;
    eax = sub_46bab0(&var_3C, esi, var_50, esi, ebx);
    esp = esp - 0x20;
    eax = sub_46b3a0(&var_44, edi, var_5C, var_80, var_7C, decomp_var_78, var_74, decomp_var_70, var_6C, var_68, var_64, var_60, var_5C, var_58, var_54, var_50, decomp_var_4c, decomp_var_48);
    ecx = eax[0x1];
    edi = *eax;
    esi = var_6C;
    var_5C = ecx;
    ebx = ecx;
    continue;
}
