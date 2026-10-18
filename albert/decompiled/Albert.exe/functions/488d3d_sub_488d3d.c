// sub_488d3d @ 0x488d3d
// hopper name: sub_488d3d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488d3d() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = 0x0;
    if (*dword_bc837c == 0x0) {
            sub_481a14();
    }
    esi = *dword_bc8384;
    if (*dword_bc8384 == 0x0) {
            esi = 0x4b1973;
    }
    while (true) {
            eax = *(int8_t *)esi;
            if (eax > 0x20) {
                    if (eax == 0x22) {
                            edi = edi == 0x0 ? 0x1 : 0x0;
                    }
                    esp = (esp - 0x4) + 0x4;
                    if (sub_47f62e(eax & 0xff) != 0x0) {
                            esi = esi + 0x1;
                    }
                    esi = esi + 0x1;
                    continue;
            }
            if (eax == 0x0) {
                    temp_0 = 0x0;
                    break;
            }
            if (edi != 0x0) {
                    if (eax == 0x22) {
                            edi = edi == 0x0 ? 0x1 : 0x0;
                    }
                    esp = (esp - 0x4) + 0x4;
                    if (sub_47f62e(eax & 0xff) != 0x0) {
                            esi = esi + 0x1;
                    }
                    esi = esi + 0x1;
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 != 0x0) {
            while (true) {
                    eax = *(int8_t *)esi;
                    if (eax != 0x0) {
                            if (eax <= 0x20) {
                                    esi = esi + 0x1;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
                    temp_1 = 0x0;
                    break;
            }
    }
    eax = esi;
    return eax;
}
