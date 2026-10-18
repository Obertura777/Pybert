// sub_491d66 @ 0x491d66
// hopper name: sub_491d66
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_491d66() {
    ecx = arg_8;
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    arg_0[0x1] = 0x0;
    arg_0[0x2] = 0x0;
    arg_0[0x3] = 0x0;
    if ((ecx & 0x10) != 0x0) {
            arg_0[0x1] = arg_0[0x1] | 0x1;
            arg_8 = 0xc000008f;
    }
    if ((ecx & 0x2) != 0x0) {
            arg_0[0x1] = arg_0[0x1] | 0x2;
            arg_8 = 0xc0000093;
    }
    if ((0x1 & ecx) != 0x0) {
            arg_0[0x1] = arg_0[0x1] | 0x4;
            arg_8 = 0xc0000091;
    }
    if ((ecx & 0x4) != 0x0) {
            arg_0[0x1] = arg_0[0x1] | 0x8;
            arg_8 = 0xc000008e;
    }
    if ((ecx & 0x8) != 0x0) {
            arg_0[0x1] = arg_0[0x1] | 0x10;
            arg_8 = 0xc0000090;
    }
    esi = arg_4;
    arg_0[0x2] = arg_0[0x2] ^ (!(*esi << 0x4) ^ arg_0[0x2]) & 0x10;
    ecx = *esi;
    arg_0[0x2] = arg_0[0x2] ^ (!(ecx + ecx) ^ arg_0[0x2]) & 0x8;
    arg_0[0x2] = arg_0[0x2] ^ (!(*esi >> 0x1) ^ arg_0[0x2]) & 0x4;
    arg_0[0x2] = arg_0[0x2] ^ (!(*esi >> 0x3) ^ arg_0[0x2]) & 0x2;
    arg_0[0x2] = arg_0[0x2] ^ (!(*esi >> 0x5) ^ arg_0[0x2]) & 0x1;
    eax = sub_49226a();
    if ((0x1 & eax) != 0x0) {
            arg_0[0x3] = arg_0[0x3] | 0x10;
    }
    if ((eax & 0x4) != 0x0) {
            arg_0[0x3] = arg_0[0x3] | 0x8;
    }
    if ((eax & 0x8) != 0x0) {
            arg_0[0x3] = arg_0[0x3] | 0x4;
    }
    if ((eax & 0x10) != 0x0) {
            arg_0[0x3] = arg_0[0x3] | 0x2;
    }
    if ((eax & 0x20) != 0x0) {
            arg_0[0x3] = arg_0[0x3] | 0x1;
    }
    eax = *esi;
    eax = eax & 0xc00;
    switch (eax) {
        case 0:
            *arg_0 = *arg_0 & 0xfffffffc;
            break;
        case 1024:
            eax = arg_0;
            ecx = *eax;
            ecx = ecx & 0xfffffffd | 0x1;
            *eax = ecx;
            break;
        case 2048:
            eax = arg_0;
            ecx = *eax;
            ecx = ecx & 0xfffffffe | 0x2;
            *eax = ecx;
            break;
        case 3072:
            *arg_0 = *arg_0 | 0x3;
            break;
    }
    eax = *esi;
    eax = eax & 0x300;
    switch (eax) {
        case 0:
            eax = arg_0;
            ecx = *eax;
            ecx = ecx & 0xffffffeb | 0x8;
            *eax = ecx;
            break;
        case 512:
            eax = arg_0;
            ecx = *eax;
            ecx = ecx & 0xffffffe7 | 0x4;
            *eax = ecx;
            break;
        case 768:
            *arg_0 = *arg_0 & 0xffffffe3;
            break;
    }
    *arg_0 = *arg_0 ^ (arg_c << 0x5 ^ *arg_0) & 0x1ffe0;
    arg_0[0x8] = arg_0[0x8] | 0x1;
    eax = arg_0;
    edi = arg_14;
    if (arg_18 != 0x0) {
            ebx = 0x1;
            eax[0x8] = eax[0x8] & 0xffffffe1;
            asm { fld        dword [eax] };
            asm { fstp       dword [eax+0x10] };
            arg_0[0x18] = arg_0[0x18] | ebx;
            arg_0[0x18] = arg_0[0x18] & 0xffffffe1;
            asm { fld        dword [edi] };
            asm { fstp       dword [eax+0x50] };
    }
    else {
            ebx = 0x1;
            eax[0x8] = eax[0x8] & 0xffffffe3 | 0x2;
            asm { fld        qword [eax] };
            asm { fstp       qword [eax+0x10] };
            arg_0[0x18] = arg_0[0x18] | ebx;
            arg_0[0x18] = arg_0[0x18] & 0xffffffe3 | 0x2;
            asm { fld        qword [edi] };
            asm { fstp       qword [eax+0x50] };
    }
    sub_492275();
    esp = esp - 0x10;
    RaiseException(arg_8, 0x0, 0x1, &arg_0);
    ecx = arg_0;
    if ((ecx[0x8] & 0x10) != 0x0) {
            *esi = *esi & 0xfffffffe;
    }
    if ((ecx[0x8] & 0x8) != 0x0) {
            *esi = *esi & 0xfffffffb;
    }
    if ((ecx[0x8] & 0x4) != 0x0) {
            *esi = *esi & 0xfffffff7;
    }
    bool_18 = (ecx[0x8] & 0x2) == 0x0;
    bool_17 = (ecx[0x8] & 0x2) == 0x0;
    if (!bool_18) {
            *esi = *esi & 0xffffffef;
    }
    if (!bool_17) {
            *esi = *esi & 0xffffffdf;
    }
    eax = *ecx;
    eax = (eax & 0x3) - 0x0;
    if (eax != 0x0) {
            eax = eax - 0x1;
            if (eax != 0x0) {
                    eax = eax - 0x1;
                    if (eax != 0x0) {
                            if (eax == 0x1) {
                                    *esi = *esi | 0xc00;
                            }
                    }
                    else {
                            eax = *esi;
                            eax = eax & 0xfffffbff | 0x800;
                            *esi = eax;
                    }
            }
            else {
                    eax = *esi;
                    eax = eax & 0xfffff7ff | 0x400;
                    *esi = eax;
            }
    }
    else {
            *esi = *esi & 0xfffff3ff;
    }
    eax = *ecx;
    eax = (eax >> 0x2 & 0x7) - 0x0;
    if (eax != 0x0) {
            eax = eax - 0x1;
            if (eax != 0x0) {
                    eax = eax - 0x1;
                    if (eax == 0x0) {
                            *esi = *esi & 0xfffff3ff;
                    }
            }
            else {
                    eax = *esi;
                    eax = eax & 0xfffff3ff | 0x200;
                    *esi = eax;
            }
    }
    else {
            eax = *esi;
            eax = eax & 0xfffff3ff | 0x300;
            *esi = eax;
    }
    if (arg_18 != 0x0) {
            asm { fld        dword [ecx+0x50] };
            asm { fstp       dword [edi] };
    }
    else {
            asm { fld        qword [ecx+0x50] };
            asm { fstp       qword [edi] };
    }
    return eax;
}
