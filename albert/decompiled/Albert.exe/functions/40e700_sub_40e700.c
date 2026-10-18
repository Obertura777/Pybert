// sub_40e700 @ 0x40e700
// hopper name: sub_40e700
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e700() {
    decomp_var_4 = ebx;
    var_8 = esi;
    esi = ecx;
    sub_465ff0(arg_0);
    esp = esp - 0x10;
    if (sub_465d90(0xbbf4a8) != 0x0) {
            *dword_baed2c = *dword_baed2c + 0x1;
            bool_1 = *dword_baed2c > 0x2;
            *(int8_t *)byte_baed30 = 0x1;
            if (!bool_1) {
                    *(int8_t *)byte_baed30 = 0x0;
            }
    }
    else {
            *dword_baed2c = 0x0;
            *(int8_t *)byte_baed30 = 0x0;
    }
    esp = esp - 0x4;
    sub_465ff0(0xbbf498);
    *dword_623990 = 0x0;
    *dword_623994 = 0x0;
    *dword_623998 = 0x0;
    *dword_62399c = 0x0;
    *dword_6239a0 = 0x0;
    *dword_6239a4 = 0x0;
    *dword_6239a8 = 0x0;
    *dword_6239ac = 0x0;
    *dword_6239b0 = 0x0;
    *dword_6239b4 = 0x0;
    *dword_6239b8 = 0x0;
    *dword_6239bc = 0x0;
    *dword_6239c0 = 0x0;
    *dword_6239c4 = 0x0;
    *dword_6239c8 = 0x0;
    *dword_6239cc = 0x0;
    *dword_6239d0 = 0x0;
    *dword_6239d4 = 0x0;
    *dword_6239d8 = 0x0;
    *dword_6239dc = 0x0;
    *dword_6239e0 = 0x0;
    *dword_6239e4 = 0x0;
    eax = esi[0x2];
    edx = 0x0;
    if (eax[0x900] > 0x0) {
            ecx = 0x0;
            &var_8 = &var_8;
            do {
                    if (*(int8_t *)(ecx + eax + 0x3) != 0x0) {
                            eax = *(int16_t *)(ecx + eax + 0x20);
                            bool_4 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_4) {
                                    eax = 0x14;
                            }
                            *(eax * 0x4 + dword_623990) = *(eax * 0x4 + dword_623990) + 0x1;
                    }
                    eax = esi[0x2];
                    edx = edx + 0x1;
                    ecx = ecx + 0x24;
            } while (edx < eax[0x900]);
    }
    eax = dword_623994;
    do {
            ecx = *(eax - 0x4);
            edx = esi[0x13b0];
            edx = edx * ecx + esi[0x13b2];
            eax = eax + 0x8;
            edx = edx * ecx + esi[0x13b4];
            ecx = *(eax - 0x8);
            *(eax - 0xc) = edx;
            *(eax - 0x8) = (esi[0x13b0] * ecx + esi[0x13b2]) * ecx + esi[0x13b4];
    } while (eax < 0x6239ec);
    return eax;
}
