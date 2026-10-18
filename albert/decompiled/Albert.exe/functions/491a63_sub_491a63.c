// sub_491a63 @ 0x491a63
// hopper name: sub_491a63
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_491a63() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    esp = esp - 0x20;
    decomp_var_20 = edi;
    asm { wait };
    asm { fnstcw     word [esp+0x20+var_C] };
    ebx = var_C;
    edx = 0x0;
    if ((ebx & 0x1) != 0x0) {
            edx = 0x10;
            esp = (esp - 0x4) + 0x4;
    }
    if ((ebx & 0x4) != 0x0) {
            edx = edx | 0x8;
    }
    if ((ebx & 0x8) != 0x0) {
            edx = edx | 0x4;
    }
    if ((ebx & 0x10) != 0x0) {
            edx = edx | 0x2;
    }
    if ((ebx & 0x20) != 0x0) {
            edx = edx | 0x1;
    }
    if ((ebx & 0x2) != 0x0) {
            edx = edx | 0x80000;
    }
    ecx = ebx & 0xffff;
    eax = ecx & 0xc00;
    if (eax != 0x0) {
            switch (eax) {
                case 1024:
                    edx = edx | 0x100;
                    break;
                case 2048:
                    edx = edx | 0x200;
                    break;
                case 3072:
                    edx = edx | 0x300;
                    break;
            }
    }
    ecx = ecx & 0x300;
    if (ecx != 0x0) {
            if (ecx == 0x200) {
                    edx = edx | 0x10000;
            }
    }
    else {
            edx = edx | 0x20000;
    }
    if ((ebx & 0x1000) != 0x0) {
            edx = edx | 0x40000;
    }
    esi = arg_4;
    eax = !esi & edx | arg_0 & esi;
    var_4 = eax;
    if (eax != edx) {
            var_10 = sub_491935() & 0xffff;
            asm { fldcw      word [esp+0x20+var_10] };
            asm { wait };
            asm { fnstcw     word [esp+0x20+var_10] };
            ebx = var_10;
            edx = 0x0;
            if ((ebx & 0x1) != 0x0) {
                    edx = 0x10;
                    esp = (esp - 0x4) + 0x4;
            }
            if ((ebx & 0x4) != 0x0) {
                    edx = edx | 0x8;
            }
            if ((ebx & 0x8) != 0x0) {
                    edx = edx | 0x4;
            }
            if ((ebx & 0x10) != 0x0) {
                    edx = edx | 0x2;
            }
            if ((ebx & 0x20) != 0x0) {
                    edx = edx | 0x1;
            }
            if ((ebx & 0x2) != 0x0) {
                    edx = edx | 0x80000;
            }
            ecx = ebx & 0xffff;
            eax = ecx & 0xc00;
            if (eax != 0x0) {
                    switch (eax) {
                        case 1024:
                            edx = edx | 0x100;
                            break;
                        case 2048:
                            edx = edx | 0x200;
                            break;
                        case 3072:
                            edx = edx | 0x300;
                            break;
                    }
            }
            ecx = ecx & 0x300;
            if (ecx != 0x0) {
                    if (ecx == 0x200) {
                            edx = edx | 0x10000;
                    }
            }
            else {
                    edx = edx | 0x20000;
            }
            if ((ebx & 0x1000) != 0x0) {
                    edx = edx | 0x40000;
            }
            eax = edx;
            var_4 = edx;
    }
    if (*dword_bc8368 != 0x0) {
            edi = esi & 0x308031f;
            asm { stmxcsr    dword [esp+0x20+var_8] };
            eax = var_8;
            esi = 0x0;
            if (eax < 0x0) {
                    esi = 0x10;
                    esp = (esp - 0x4) + 0x4;
            }
            if ((eax & 0x200) != 0x0) {
                    esi = esi | 0x8;
            }
            if ((eax & 0x400) != 0x0) {
                    esi = esi | 0x4;
            }
            if ((eax & 0x800) != 0x0) {
                    esi = esi | 0x2;
            }
            if ((eax & 0x1000) != 0x0) {
                    esi = esi | 0x1;
            }
            if ((eax & 0x100) != 0x0) {
                    esi = esi | 0x80000;
            }
            ecx = eax & 0x6000;
            if (ecx != 0x0) {
                    switch (ecx) {
                        case 8192:
                            esi = esi | 0x100;
                            break;
                        case 16384:
                            esi = esi | 0x200;
                            break;
                        case 24576:
                            esi = esi | 0x300;
                            break;
                    }
            }
            eax = (eax & 0x8040) - 0x40;
            if (eax != 0x0) {
                    eax = eax - 0x7fc0;
                    if (eax != 0x0) {
                            if (eax == 0x40) {
                                    esi = esi | 0x1000000;
                            }
                    }
                    else {
                            esi = esi | 0x3000000;
                    }
            }
            else {
                    esi = esi | 0x2000000;
            }
            if ((!edi & esi | edi & arg_0) == esi) {
                    eax = esi;
            }
            else {
                    arg_4 = sub_4919c3();
                    sub_4922fe();
                    esp = (esp - 0x4) + 0x4;
                    asm { stmxcsr    dword [esp+0x20+arg_4] };
                    eax = arg_4;
                    edx = 0x0;
                    if (eax < 0x0) {
                            edx = 0x10;
                            esp = (esp - 0x4) + 0x4;
                    }
                    if ((0x200 & eax) != 0x0) {
                            edx = edx | 0x8;
                    }
                    if ((eax & 0x400) != 0x0) {
                            edx = edx | 0x4;
                    }
                    if ((eax & 0x800) != 0x0) {
                            edx = edx | 0x2;
                    }
                    if ((eax & 0x1000) != 0x0) {
                            edx = edx | 0x1;
                    }
                    if ((0x100 & eax) != 0x0) {
                            edx = edx | 0x80000;
                    }
                    ecx = eax & 0x6000;
                    if (ecx != 0x0) {
                            switch (ecx) {
                                case 8192:
                                    edx = edx | 0x100;
                                    break;
                                case 16384:
                                    edx = edx | 0x200;
                                    break;
                                case 24576:
                                    edx = edx | 0x300;
                                    break;
                            }
                    }
                    eax = (eax & 0x8040) - 0x40;
                    if (eax != 0x0) {
                            eax = eax - 0x7fc0;
                            if (eax != 0x0) {
                                    if (eax == 0x40) {
                                            edx = edx | 0x1000000;
                                    }
                            }
                            else {
                                    edx = edx | 0x3000000;
                            }
                    }
                    else {
                            edx = edx | 0x2000000;
                    }
                    eax = edx;
            }
            edx = eax ^ var_4;
            eax = eax | var_4;
            if ((edx & 0x8031f) != 0x0) {
                    eax = eax | 0x80000000;
            }
    }
    return eax;
}
