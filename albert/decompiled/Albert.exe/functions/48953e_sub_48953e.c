// sub_48953e @ 0x48953e
// hopper name: sub_48953e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48953e() {
    esp = esp - 0x8;
    decomp_var_8 = 0x4c38f0;
    sub_47f31c(0x4c38f0, 0x20);
    decomp_var_1c = 0x0;
    ebx = arg_4;
    bool_106 = ebx == 0xb;
    if (ebx > 0xb) goto loc_4895a6;
    goto loc_48955a;

loc_4895a6:
    eax = ebx - 0xf;
    if (eax != 0x0) {
            eax = eax - 0x6;
            if (eax != 0x0) {
                    if (eax != 0x1) {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            eax = sub_47f361();
                    }
                    else {
                            decomp_var_1c = 0x1;
                            esp = esp - 0x4;
                            decomp_var_c = *dword_bc6e2c;
                            eax = sub_47fe7c(*dword_bc6e2c);
                            decomp_var_20 = eax;
                            esp = esp + 0x4;
                            if (decomp_var_20 != 0x1) {
                                    eax = 0x0;
                                    if (decomp_var_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_c = 0x3;
                                            eax = sub_47dae3(0x3);
                                    }
                                    if (decomp_var_1c != eax) {
                                            sub_487c06(eax);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    switch (ebx) {
                                        case 8:
                                            decomp_var_2c = *0x60;
                                            *0x60 = 0x0;
                                            if (ebx == 0x8) {
                                                    edi = 0x0;
                                                    decomp_var_30 = *0x64;
                                                    *0x64 = 0x8c;
                                                    if (ebx == 0x8) {
                                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc6e2c = sub_47fe73();
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e2c = sub_47fe73();
                                            }
                                            break;
                                        case 11:
                                            decomp_var_2c = *0x60;
                                            *0x60 = 0x0;
                                            if (ebx == 0x8) {
                                                    edi = 0x0;
                                                    decomp_var_30 = *0x64;
                                                    *0x64 = 0x8c;
                                                    if (ebx == 0x8) {
                                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc6e2c = sub_47fe73();
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e2c = sub_47fe73();
                                            }
                                            break;
                                        default:
                                            if (ebx == 0x4) {
                                                    decomp_var_2c = *0x60;
                                                    *0x60 = 0x0;
                                                    if (ebx == 0x8) {
                                                            edi = 0x0;
                                                            decomp_var_30 = *0x64;
                                                            *0x64 = 0x8c;
                                                            if (ebx == 0x8) {
                                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    *dword_bc6e2c = sub_47fe73();
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc6e2c = sub_47fe73();
                                                    }
                                            }
                                            else {
                                                    if (ebx == 0x8) {
                                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                                    *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc6e2c = sub_47fe73();
                                                    }
                                            }
                                            break;
                                    }
                                    sub_4896b2();
                                    if (ebx == 0x8) {
                                            (decomp_var_20)(ebx, *0x64);
                                            esp = (esp - 0x8) + 0x4;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            (decomp_var_20)(ebx);
                                    }
                                    switch (ebx) {
                                        case 8:
                                            *0x60 = decomp_var_2c;
                                            if (ebx == 0x8) {
                                                    *0x64 = decomp_var_30;
                                            }
                                            break;
                                        case 11:
                                            *0x60 = decomp_var_2c;
                                            if (ebx == 0x8) {
                                                    *0x64 = decomp_var_30;
                                            }
                                            break;
                                        default:
                                            if (ebx == 0x4) {
                                                    *0x60 = decomp_var_2c;
                                                    if (ebx == 0x8) {
                                                            *0x64 = decomp_var_30;
                                                    }
                                            }
                                            break;
                                    }
                            }
                            eax = sub_47f361();
                    }
            }
            else {
                    decomp_var_1c = 0x1;
                    esp = esp - 0x4;
                    decomp_var_c = *dword_bc6e28;
                    eax = sub_47fe7c(*dword_bc6e28);
                    decomp_var_20 = eax;
                    esp = esp + 0x4;
                    if (decomp_var_20 != 0x1) {
                            eax = 0x0;
                            if (decomp_var_20 == 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_c = 0x3;
                                    eax = sub_47dae3(0x3);
                            }
                            if (decomp_var_1c != eax) {
                                    sub_487c06(eax);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            switch (ebx) {
                                case 8:
                                    decomp_var_2c = *0x60;
                                    *0x60 = 0x0;
                                    if (ebx == 0x8) {
                                            edi = 0x0;
                                            decomp_var_30 = *0x64;
                                            *0x64 = 0x8c;
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e28 = sub_47fe73();
                                            }
                                    }
                                    else {
                                            *dword_bc6e28 = sub_47fe73();
                                    }
                                    break;
                                case 11:
                                    decomp_var_2c = *0x60;
                                    *0x60 = 0x0;
                                    if (ebx == 0x8) {
                                            edi = 0x0;
                                            decomp_var_30 = *0x64;
                                            *0x64 = 0x8c;
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e28 = sub_47fe73();
                                            }
                                    }
                                    else {
                                            *dword_bc6e28 = sub_47fe73();
                                    }
                                    break;
                                default:
                                    if (ebx == 0x4) {
                                            decomp_var_2c = *0x60;
                                            *0x60 = 0x0;
                                            if (ebx == 0x8) {
                                                    decomp_var_30 = *0x64;
                                                    *0x64 = 0x8c;
                                                    if (ebx == 0x8) {
                                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                                    *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *dword_bc6e28 = sub_47fe73();
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e28 = sub_47fe73();
                                            }
                                    }
                                    else {
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e28 = sub_47fe73();
                                            }
                                    }
                                    break;
                            }
                            sub_4896b2();
                            if (ebx == 0x8) {
                                    (decomp_var_20)(ebx, *0x64);
                                    esp = (esp - 0x8) + 0x4;
                            }
                            else {
                                    esp = esp - 0x4;
                                    (decomp_var_20)(ebx);
                            }
                            switch (ebx) {
                                case 8:
                                    *0x60 = decomp_var_2c;
                                    if (ebx == 0x8) {
                                            *0x64 = decomp_var_30;
                                    }
                                    break;
                                case 11:
                                    *0x60 = decomp_var_2c;
                                    if (ebx == 0x8) {
                                            *0x64 = decomp_var_30;
                                    }
                                    break;
                                default:
                                    if (ebx == 0x4) {
                                            *0x60 = decomp_var_2c;
                                            if (ebx == 0x8) {
                                                    *0x64 = decomp_var_30;
                                            }
                                    }
                                    break;
                            }
                    }
                    eax = sub_47f361();
            }
    }
    else {
            decomp_var_1c = 0x1;
            esp = esp - 0x4;
            decomp_var_c = *dword_bc6e30;
            eax = sub_47fe7c(*dword_bc6e30);
            decomp_var_20 = eax;
            esp = esp + 0x4;
            if (decomp_var_20 != 0x1) {
                    eax = 0x0;
                    if (decomp_var_20 == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_c = 0x3;
                            eax = sub_47dae3(0x3);
                    }
                    if (decomp_var_1c != eax) {
                            sub_487c06(eax);
                            esp = (esp - 0x4) + 0x4;
                    }
                    switch (ebx) {
                        case 8:
                            decomp_var_2c = *0x60;
                            *0x60 = 0x0;
                            if (ebx == 0x8) {
                                    edi = 0x0;
                                    decomp_var_30 = *0x64;
                                    *0x64 = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *dword_bc6e30 = sub_47fe73();
                                    }
                            }
                            else {
                                    *dword_bc6e30 = sub_47fe73();
                            }
                            break;
                        case 11:
                            decomp_var_2c = *0x60;
                            *0x60 = 0x0;
                            if (ebx == 0x8) {
                                    edi = 0x0;
                                    decomp_var_30 = *0x64;
                                    *0x64 = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *dword_bc6e30 = sub_47fe73();
                                    }
                            }
                            else {
                                    *dword_bc6e30 = sub_47fe73();
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    decomp_var_2c = *0x60;
                                    *0x60 = 0x0;
                                    if (ebx == 0x8) {
                                            decomp_var_30 = *0x64;
                                            *0x64 = 0x8c;
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *dword_bc6e30 = sub_47fe73();
                                            }
                                    }
                                    else {
                                            *dword_bc6e30 = sub_47fe73();
                                    }
                            }
                            else {
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *dword_bc6e30 = sub_47fe73();
                                    }
                            }
                            break;
                    }
                    sub_4896b2();
                    if (ebx == 0x8) {
                            (decomp_var_20)(ebx, *0x64);
                            esp = (esp - 0x8) + 0x4;
                    }
                    else {
                            esp = esp - 0x4;
                            (decomp_var_20)(ebx);
                    }
                    switch (ebx) {
                        case 8:
                            *0x60 = decomp_var_2c;
                            if (ebx == 0x8) {
                                    *0x64 = decomp_var_30;
                            }
                            break;
                        case 11:
                            *0x60 = decomp_var_2c;
                            if (ebx == 0x8) {
                                    *0x64 = decomp_var_30;
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    *0x60 = decomp_var_2c;
                                    if (ebx == 0x8) {
                                            *0x64 = decomp_var_30;
                                    }
                            }
                            break;
                    }
            }
            eax = sub_47f361();
    }
    return eax;

loc_48955a:
    if (bool_106) goto .l3;
    goto loc_48955c;

.l3:
    eax = sub_480003();
    edi = eax;
    if (edi == 0x0) {
            eax = sub_47f361();
    }
    else {
            esp = esp - 0x4;
            decomp_var_c = edi[0x17];
            esi = sub_4894fd(decomp_var_c) + 0x8;
            eax = *esi;
            decomp_var_20 = eax;
            esp = esp + 0x4;
            if (decomp_var_20 != 0x1) {
                    eax = 0x0;
                    if (decomp_var_20 == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_c = 0x3;
                            eax = sub_47dae3(0x3);
                    }
                    if (decomp_var_1c != eax) {
                            sub_487c06(eax);
                            esp = (esp - 0x4) + 0x4;
                    }
                    switch (ebx) {
                        case 8:
                            decomp_var_2c = edi[0x18];
                            edi[0x18] = 0x0;
                            if (ebx == 0x8) {
                                    decomp_var_30 = edi[0x19];
                                    edi[0x19] = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    *esi = sub_47fe73();
                            }
                            break;
                        case 11:
                            decomp_var_2c = edi[0x18];
                            edi[0x18] = 0x0;
                            if (ebx == 0x8) {
                                    decomp_var_30 = edi[0x19];
                                    edi[0x19] = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    *esi = sub_47fe73();
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    decomp_var_2c = edi[0x18];
                                    edi[0x18] = 0x0;
                                    if (ebx == 0x8) {
                                            decomp_var_30 = edi[0x19];
                                            edi[0x19] = 0x8c;
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *esi = sub_47fe73();
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            break;
                    }
                    sub_4896b2();
                    if (ebx == 0x8) {
                            (decomp_var_20)(ebx, edi[0x19]);
                            esp = (esp - 0x8) + 0x4;
                    }
                    else {
                            esp = esp - 0x4;
                            (decomp_var_20)(ebx);
                    }
                    switch (ebx) {
                        case 8:
                            edi[0x18] = decomp_var_2c;
                            if (ebx == 0x8) {
                                    edi[0x19] = decomp_var_30;
                            }
                            break;
                        case 11:
                            edi[0x18] = decomp_var_2c;
                            if (ebx == 0x8) {
                                    edi[0x19] = decomp_var_30;
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    edi[0x18] = decomp_var_2c;
                                    if (ebx == 0x8) {
                                            edi[0x19] = decomp_var_30;
                                    }
                            }
                            break;
                    }
            }
            eax = sub_47f361();
    }
    return eax;

loc_48955c:
    esp = (esp - 0x4) + 0x4;
    eax = ebx - 0x2;
    if (eax == 0x0) goto loc_489587;
    goto loc_489565;

loc_489587:
    decomp_var_1c = 0x1;
    esp = esp - 0x4;
    decomp_var_c = *dword_bc6e24;
    eax = sub_47fe7c(*dword_bc6e24);
    decomp_var_20 = eax;
    esp = esp + 0x4;
    if (decomp_var_20 != 0x1) {
            eax = 0x0;
            if (decomp_var_20 == 0x0) {
                    esp = esp - 0x4;
                    decomp_var_c = 0x3;
                    eax = sub_47dae3(0x3);
            }
            if (decomp_var_1c != eax) {
                    sub_487c06(eax);
                    esp = (esp - 0x4) + 0x4;
            }
            switch (ebx) {
                case 8:
                    decomp_var_2c = *0x60;
                    *0x60 = 0x0;
                    if (ebx == 0x8) {
                            edi = 0x0;
                            decomp_var_30 = *0x64;
                            *0x64 = 0x8c;
                            if (ebx == 0x8) {
                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                    }
                            }
                            else {
                                    *dword_bc6e24 = sub_47fe73();
                            }
                    }
                    else {
                            *dword_bc6e24 = sub_47fe73();
                    }
                    break;
                case 11:
                    decomp_var_2c = *0x60;
                    *0x60 = 0x0;
                    if (ebx == 0x8) {
                            edi = 0x0;
                            decomp_var_30 = *0x64;
                            *0x64 = 0x8c;
                            if (ebx == 0x8) {
                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                    }
                            }
                            else {
                                    *dword_bc6e24 = sub_47fe73();
                            }
                    }
                    else {
                            *dword_bc6e24 = sub_47fe73();
                    }
                    break;
                default:
                    if (ebx == 0x4) {
                            decomp_var_2c = *0x60;
                            *0x60 = 0x0;
                            if (ebx == 0x8) {
                                    decomp_var_30 = *0x64;
                                    *0x64 = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *dword_bc6e24 = sub_47fe73();
                                    }
                            }
                            else {
                                    *dword_bc6e24 = sub_47fe73();
                            }
                    }
                    else {
                            if (ebx == 0x8) {
                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                            *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                                    }
                            }
                            else {
                                    *dword_bc6e24 = sub_47fe73();
                            }
                    }
                    break;
            }
            sub_4896b2();
            if (ebx == 0x8) {
                    (decomp_var_20)(ebx, *0x64);
                    esp = (esp - 0x8) + 0x4;
            }
            else {
                    esp = esp - 0x4;
                    (decomp_var_20)(ebx);
            }
            switch (ebx) {
                case 8:
                    *0x60 = decomp_var_2c;
                    if (ebx == 0x8) {
                            *0x64 = decomp_var_30;
                    }
                    break;
                case 11:
                    *0x60 = decomp_var_2c;
                    if (ebx == 0x8) {
                            *0x64 = decomp_var_30;
                    }
                    break;
                default:
                    if (ebx == 0x4) {
                            *0x60 = decomp_var_2c;
                            if (ebx == 0x8) {
                                    *0x64 = decomp_var_30;
                            }
                    }
                    break;
            }
    }
    eax = sub_47f361();
    return eax;

loc_489565:
    eax = eax - 0x2;
    if (eax == 0x0) goto .l2;
    goto loc_489569;

.l2:
    eax = sub_480003();
    edi = eax;
    if (edi == 0x0) {
            eax = sub_47f361();
    }
    else {
            esp = esp - 0x4;
            decomp_var_c = edi[0x17];
            esi = sub_4894fd(decomp_var_c) + 0x8;
            eax = *esi;
            decomp_var_20 = eax;
            esp = esp + 0x4;
            if (decomp_var_20 != 0x1) {
                    eax = 0x0;
                    if (decomp_var_20 == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_c = 0x3;
                            eax = sub_47dae3(0x3);
                    }
                    if (decomp_var_1c != eax) {
                            sub_487c06(eax);
                            esp = (esp - 0x4) + 0x4;
                    }
                    switch (ebx) {
                        case 8:
                            decomp_var_2c = edi[0x18];
                            edi[0x18] = 0x0;
                            if (ebx == 0x8) {
                                    decomp_var_30 = edi[0x19];
                                    edi[0x19] = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    *esi = sub_47fe73();
                            }
                            break;
                        case 11:
                            decomp_var_2c = edi[0x18];
                            edi[0x18] = 0x0;
                            if (ebx == 0x8) {
                                    decomp_var_30 = edi[0x19];
                                    edi[0x19] = 0x8c;
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    *esi = sub_47fe73();
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    decomp_var_2c = edi[0x18];
                                    edi[0x18] = 0x0;
                                    if (ebx == 0x8) {
                                            decomp_var_30 = edi[0x19];
                                            edi[0x19] = 0x8c;
                                            if (ebx == 0x8) {
                                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                                    }
                                            }
                                            else {
                                                    *esi = sub_47fe73();
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            else {
                                    if (ebx == 0x8) {
                                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                            }
                                    }
                                    else {
                                            *esi = sub_47fe73();
                                    }
                            }
                            break;
                    }
                    sub_4896b2();
                    if (ebx == 0x8) {
                            (decomp_var_20)(ebx, edi[0x19]);
                            esp = (esp - 0x8) + 0x4;
                    }
                    else {
                            esp = esp - 0x4;
                            (decomp_var_20)(ebx);
                    }
                    switch (ebx) {
                        case 8:
                            edi[0x18] = decomp_var_2c;
                            if (ebx == 0x8) {
                                    edi[0x19] = decomp_var_30;
                            }
                            break;
                        case 11:
                            edi[0x18] = decomp_var_2c;
                            if (ebx == 0x8) {
                                    edi[0x19] = decomp_var_30;
                            }
                            break;
                        default:
                            if (ebx == 0x4) {
                                    edi[0x18] = decomp_var_2c;
                                    if (ebx == 0x8) {
                                            edi[0x19] = decomp_var_30;
                                    }
                            }
                            break;
                    }
            }
            eax = sub_47f361();
    }
    return eax;

loc_489569:
    ecx = 0x2;
    eax = eax - 0x2;
    if (eax == 0x0) goto loc_4895d1;
    goto loc_48956d;

loc_4895d1:
    decomp_var_1c = 0x1;
    esp = esp - 0x4;
    decomp_var_c = *dword_bc6e2c;
    eax = sub_47fe7c(*dword_bc6e2c);
    decomp_var_20 = eax;
    esp = esp + 0x4;
    if (decomp_var_20 != 0x1) {
            eax = 0x0;
            if (decomp_var_20 == 0x0) {
                    esp = esp - 0x4;
                    decomp_var_c = 0x3;
                    eax = sub_47dae3(0x3);
            }
            if (decomp_var_1c != eax) {
                    sub_487c06(eax);
                    esp = (esp - 0x4) + 0x4;
            }
            if (ebx != 0x8 && ebx != 0xb && ebx != 0x4) {
                    if (ebx == 0x8) {
                            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                    *(decomp_var_24 * 0xc + *0x5c + 0x8) = 0x0;
                            }
                    }
                    else {
                            *dword_bc6e2c = sub_47fe73();
                    }
            }
            else {
                    decomp_var_2c = *0x60;
                    *0x60 = 0x0;
                    if (ebx == 0x8) {
                            edi = 0x0;
                            decomp_var_30 = *0x64;
                            *0x64 = 0x8c;
                            if (ebx == 0x8) {
                                    for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                                            *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
                                    }
                            }
                            else {
                                    *dword_bc6e2c = sub_47fe73();
                            }
                    }
                    else {
                            *dword_bc6e2c = sub_47fe73();
                    }
            }
            sub_4896b2();
            if (ebx == 0x8) {
                    (decomp_var_20)(ebx, *0x64);
                    esp = (esp - 0x8) + 0x4;
            }
            else {
                    esp = esp - 0x4;
                    (decomp_var_20)(ebx);
            }
            if (ebx != 0x8 && ebx != 0xb) {
                    if (ebx == 0x4) {
                            *0x60 = decomp_var_2c;
                            if (ebx == 0x8) {
                                    *0x64 = decomp_var_30;
                            }
                    }
            }
            else {
                    *0x60 = decomp_var_2c;
                    if (ebx == 0x8) {
                            *0x64 = decomp_var_30;
                    }
            }
    }
    eax = sub_47f361();
    return eax;

loc_48956d:
    if (eax != ecx) goto loc_4895b5;
    goto loc_489571;

loc_4895b5:
    *sub_47d812() = 0x16;
    eax = sub_47a924();
    eax = sub_47f361();
    return eax;

loc_489571:
    eax = sub_480003();
    edi = eax;
    if (edi != 0x0) goto loc_489593;
    goto loc_48957f;

loc_489593:
    esp = esp - 0x4;
    decomp_var_c = edi[0x17];
    esi = sub_4894fd(decomp_var_c) + 0x8;
    eax = *esi;
    decomp_var_20 = eax;
    esp = esp + 0x4;
    if (decomp_var_20 == 0x1) goto loc_4896e8;
    goto loc_489610;

loc_48957f:
    eax = sub_47f361();
    return eax;

loc_4896e8:
    eax = sub_47f361();
    return eax;

loc_489610:
    eax = 0x0;
    if (decomp_var_20 == 0x0) {
            esp = esp - 0x4;
            decomp_var_c = 0x3;
            eax = sub_47dae3(0x3);
    }
    if (decomp_var_1c != eax) {
            sub_487c06(eax);
            esp = (esp - 0x4) + 0x4;
    }
    if (ebx == 0x8 || ebx == 0xb || ebx == 0x4) goto loc_48963c;
    goto loc_489657;

loc_48963c:
    decomp_var_2c = edi[0x18];
    edi[0x18] = 0x0;
    if (ebx != 0x8) goto loc_48968a;
    goto loc_48964a;

loc_489657:
    if (ebx == 0x8) {
            for (decomp_var_24 = *dword_4c9bd8; decomp_var_24 < *dword_4c9bdc + *dword_4c9bd8; decomp_var_24 = decomp_var_24 + 0x1) {
                    *(decomp_var_24 * 0xc + edi[0x17] + 0x8) = 0x0;
            }
    }
    else {
            *esi = sub_47fe73();
    }
    goto loc_489691;

loc_48968a:
    *esi = sub_47fe73();
    goto loc_489691;

loc_48964a:
    decomp_var_30 = edi[0x19];
    edi[0x19] = 0x8c;
    goto loc_489657;

loc_489691:
    sub_4896b2();
    if (ebx == 0x8) {
            (decomp_var_20)(ebx, edi[0x19]);
            esp = (esp - 0x8) + 0x4;
    }
    else {
            esp = esp - 0x4;
            (decomp_var_20)(ebx);
    }
    if (ebx != 0x8 && ebx != 0xb) {
            if (ebx == 0x4) {
                    edi[0x18] = decomp_var_2c;
                    if (ebx == 0x8) {
                            edi[0x19] = decomp_var_30;
                    }
            }
    }
    else {
            edi[0x18] = decomp_var_2c;
            if (ebx == 0x8) {
                    edi[0x19] = decomp_var_30;
            }
    }
    goto loc_4896e8;
}
