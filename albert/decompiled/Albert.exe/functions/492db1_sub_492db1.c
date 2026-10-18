// sub_492db1 @ 0x492db1
// hopper name: sub_492db1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492db1() {
    var_4 = *dword_4c8db8 ^ ebp;
    eax = arg_8;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    bool_13 = true;
    bool_12 = true;
    bool_11 = true;
    esp = esp - 0xc;
    decomp_var_24 = edi;
    var_18 = 0x404e;
    *eax = 0x0;
    eax[0x1] = 0x0;
    eax[0x2] = 0x0;
    if (arg_4 <= 0x0) goto .l2;
    goto loc_492de1;

.l2:
    while (eax[0x2] == 0x0) {
            ecx = eax[0x1];
            eax[0x2] = ecx >> 0x10;
            edx = *eax;
            var_18 = var_18 + 0xfff0;
            eax[0x1] = ecx << 0x10 | edx >> 0x10;
            *eax = edx << 0x10;
    }
    goto loc_492f2c;

loc_492de1:
    edx = *eax;
    ebx = eax[0x1];
    var_10 = *eax;
    var_10 = *eax;
    var_10 = *eax;
    edi = edx + edx;
    edx = ebx + ebx | edx >> 0x1f;
    ecx = eax[0x2];
    var_14 = edi & 0x0;
    ecx = (ecx + ecx | ebx >> 0x1f) + (ecx + ecx | ebx >> 0x1f) | edx >> 0x1f;
    ebx = var_10;
    esi = edi + edi;
    edx = edx + edx | edi >> 0x1f;
    edi = esi + ebx;
    *eax = esi;
    eax[0x1] = edx;
    eax[0x2] = ecx;
    if (edi < esi || edi < ebx) {
            var_14 = 0x1;
    }
    ebx = 0x0;
    *eax = edi;
    if (var_14 != 0x0) {
            esi = edx + 0x1;
            if (esi < edx || esi < 0x1) {
                    ebx = 0x1;
            }
            eax[0x1] = esi;
            if (ebx != 0x0) {
                    eax[0x2] = ecx + 0x1;
            }
    }
    ecx = eax[0x1];
    edx = var_C;
    ebx = ecx + edx;
    esi = 0x0;
    if (ebx < ecx || ebx < edx) {
            esi = 0x1;
    }
    eax[0x1] = ebx;
    if (esi != 0x0) {
            eax[0x2] = eax[0x2] + 0x1;
    }
    eax[0x2] = eax[0x2] + var_8;
    var_14 = var_14 & 0x0;
    ecx = edi + edi;
    edi = ebx + ebx | edi >> 0x1f;
    edx = eax[0x2];
    ebx = edx + edx | ebx >> 0x1f;
    *eax = ecx;
    eax[0x1] = edi;
    eax[0x2] = ebx;
    edx = sign_extend_32(*(int8_t *)arg_0);
    esi = ecx + edx;
    var_10 = edx;
    if (esi < ecx || esi < edx) {
            var_14 = 0x1;
    }
    *eax = esi;
    if (var_14 != 0x0) {
            ecx = edi + 0x1;
            edx = 0x0;
            if (ecx < edi || ecx < 0x1) {
                    edx = 0x1;
            }
            eax[0x1] = ecx;
            if (edx != 0x0) {
                    eax[0x2] = ebx + 0x1;
            }
    }
    arg_4 = arg_4 - 0x1;
    arg_0 = arg_0 + 0x1;
    if (arg_4 > 0x0) {
            continue;
    }
    break;

loc_492f2c:
    if (!bool_1) {
            do {
                    esi = *eax;
                    edi = eax[0x1];
                    var_18 = var_18 + 0xffff;
                    *eax = esi + esi;
                    ecx = eax[0x2];
                    eax[0x1] = edi + edi | esi >> 0x1f;
                    eax[0x2] = ecx + ecx | edi >> 0x1f;
            } while ((0x8000 & (ecx + ecx | edi >> 0x1f)) == 0x0);
    }
    eax[0x5] = var_18;
    sub_47ad69();
    return;
    bool_2 = eax[0x2] == 0x0;
    bool_1 = eax[0x2] != 0x0;
    if (bool_2) goto loc_492f01;
    goto loc_492f2c;

loc_492f01:
    ecx = eax[0x1];
    eax[0x2] = ecx >> 0x10;
    edx = *eax;
    var_18 = var_18 + 0xfff0;
    eax[0x1] = ecx << 0x10 | edx >> 0x10;
    *eax = edx << 0x10;
    goto .l3;

.l3:
    if (eax[0x2] == 0x0) {
            ecx = eax[0x1];
            eax[0x2] = ecx >> 0x10;
            edx = *eax;
            var_18 = var_18 + 0xfff0;
            eax[0x1] = ecx << 0x10 | edx >> 0x10;
            *eax = edx << 0x10;
            continue;
    }
    break;
}
