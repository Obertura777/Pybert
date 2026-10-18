// sub_4734c2 @ 0x4734c2
// hopper name: sub_4734c2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4734c2() {
    esi = ecx;
    esp = esp - 0x8;
    var_8 = esi;
    var_4 = sub_476745();
    eax = arg_0;
    if (eax != 0x0) {
            edi = eax[0x8];
    }
    else {
            if ((var_4 & 0x40000000) != 0x0) {
                    esp = esp - 0x4;
                    eax = GetParent(esi[0x8]);
            }
            else {
                    esp = esp - 0x8;
                    eax = GetWindow(esi[0x8], 0x4);
            }
            edi = eax;
            if (edi != 0x0) {
                    esp = esp - 0x10;
                    eax = SendMessageA(edi, 0x36b, 0x0, 0x0);
                    if (eax != 0x0) {
                            edi = eax;
                    }
            }
    }
    esp = esp - 0xc;
    eax = GetWindowRect(esi[0x8], &var_38);
    if ((var_4 & 0x40000000) == 0x0) {
            if (edi != 0x0) {
                    esp = esp - 0x8;
                    eax = GetWindowLongA(edi, 0xfffffff0);
                    if ((eax & 0x10000000) == 0x0 || (eax & 0x20000000) != 0x0) {
                            edi = 0x0;
                    }
            }
            var_60 = 0x28;
            if (edi == 0x0) {
                    eax = sub_46e5d5();
                    if (eax != 0x0) {
                            eax = eax[0x8];
                    }
                    sub_47183d(sub_4717d2(eax, 0x1), decomp_var_68);
                    eax = CopyRect(&var_28, &var_4C);
                    esp = esp - 0x20;
                    eax = CopyRect(&var_18, &var_4C);
            }
            else {
                    eax = GetWindowRect(edi, &var_28);
                    sub_47183d(sub_4717d2(edi, 0x2), decomp_var_68);
                    esp = esp - 0x20;
                    eax = CopyRect(&var_18, &var_4C);
            }
    }
    else {
            ebx = GetParent(esi[0x8]);
            eax = GetClientRect(ebx, &var_18);
            GetClientRect(edi, &var_28);
            esp = esp - 0x24;
            eax = MapWindowPoints(edi, ebx, &var_28, 0x2);
    }
    ebx = var_38;
    edi = var_30 - ebx;
    ecx = (SAR(var_28 + var_20 - (var_28 + var_20 & 0x80000000 ? 0xffffffff : 0x0), 0x1)) - (SAR(edi - (edi & 0x80000000 ? 0xffffffff : 0x0), 0x1));
    arg_0 = var_2C - var_34;
    esi = (SAR(var_24 + var_1C - (var_24 + var_1C & 0x80000000 ? 0xffffffff : 0x0), 0x1)) - (SAR(arg_0 - (arg_0 & 0x80000000 ? 0xffffffff : 0x0), 0x1));
    if (ecx < var_18) {
            ecx = var_18;
    }
    else {
            if (edi + ecx > var_10) {
                    ecx = (ebx - var_30) + var_10;
            }
    }
    esp = esp + 0x4;
    if (esi < var_14) {
            esi = var_14;
    }
    else {
            if (arg_0 + esi > var_C) {
                    esi = (var_34 - var_2C) + var_C;
            }
    }
    eax = sub_47681c(0x0, ecx, esi, 0xffffffff, 0xffffffff, 0x15);
    return eax;
}
