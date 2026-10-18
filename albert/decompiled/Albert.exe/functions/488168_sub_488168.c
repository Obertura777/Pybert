// sub_488168 @ 0x488168
// hopper name: sub_488168
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488168() {
    ecx = arg_0;
    eax = ecx[0x2];
    decomp_var_c = ebx;
    decomp_var_10 = esi;
    esi = ecx[0x4];
    esp = esp - 0xc;
    decomp_var_14 = edi;
    ebx = 0x0;
    while (eax >= 0x0) {
            eax = eax + eax;
            ebx = ebx + 0x1;
    }
    eax = ebx * 0x204 + esi + 0x144;
    var_8 = eax;
    edx = 0x3f;
    esp = (esp - 0x4) + 0x4;
    do {
            eax[0x2] = eax;
            eax[0x1] = eax;
            eax = eax + 0x8;
            edx = edx - 0x1;
    } while (edx != 0x0);
    edi = (ebx << 0xf) + ecx[0x3];
    esp = esp - 0x10;
    eax = VirtualAlloc(edi, 0x8000, 0x1000, 0x4);
    if (eax == 0x0) {
            eax = eax | 0xffffffff;
    }
    else {
            edx = edi + 0x7000;
            var_4 = edx;
            if (edi <= edx) {
                    eax = edi + 0x10;
                    ecx = (edx - edi >> 0xc) + 0x1;
                    do {
                            *(eax - 0x8) = *(eax - 0x8) | 0xffffffff;
                            eax[0x3fb] = eax[0x3fb] | 0xffffffff;
                            *eax = eax + 0xffc;
                            *(eax - 0x4) = 0xff0;
                            eax[0x1] = eax - 0x1004;
                            eax[0x3fa] = 0xff0;
                            eax = eax + 0x1000;
                            ecx = ecx - 0x1;
                    } while (ecx != 0x0);
                    edx = var_4;
            }
            *(var_8 + 0x1fc) = edi + 0xc;
            *(edi + 0x14) = var_8 + 0x1f8;
            *(var_8 + 0x200) = edx + 0xc;
            *(edx + 0x10) = var_8 + 0x1f8;
            *(esi + ebx * 0x4 + 0x44) = *(esi + ebx * 0x4 + 0x44) & 0x0;
            *(esi + ebx * 0x4 + 0xc4) = 0x1;
            eax = esi[0x43];
            ecx = eax + 0x1;
            bool_2 = eax != 0x0;
            eax = arg_0;
            esi[0x43] = ecx;
            if (!bool_2) {
                    eax[0x1] = eax[0x1] | 0x1;
            }
            eax[0x2] = eax[0x2] & !(0x80000000 >> ebx);
            eax = ebx;
    }
    return eax;
}
