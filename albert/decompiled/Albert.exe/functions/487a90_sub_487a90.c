// sub_487a90 @ 0x487a90
// hopper name: sub_487a90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487a90() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    esi = 0x0;
    edi = 0xbc68a0;
    while (true) {
            if (*(esi * 0x8 + 0x4c9984) != 0x1) {
                    esi = esi + 0x1;
                    if (esi < 0x24) {
                            continue;
                    }
                    eax = 0x1;
                    break;
            }
            *(esi * 0x8 + 0x4c9980) = edi;
            edi = edi + 0x18;
            esp = (esp - 0x8) + 0x8;
            if (sub_489876() == 0x0) {
                    *(esi * 0x8 + 0x4c9980) = *(esi * 0x8 + 0x4c9980) & 0x0;
                    eax = 0x0;
                    break;
            }
            esi = esi + 0x1;
            if (esi < 0x24) {
                    continue;
            }
            eax = 0x1;
            break;
    }
    return eax;
}
