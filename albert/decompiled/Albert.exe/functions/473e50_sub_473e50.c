// sub_473e50 @ 0x473e50
// hopper name: sub_473e50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473e50() {
    esp = esp - 0x8;
    edi = arg_4;
    esi = *edi;
    while (true) {
            if (esi == 0x0) {
                    temp_0 = 0x0;
                    break;
            }
            else {
                    esp = esp - 0x4;
                    eax = sub_473b15();
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            eax = (*(*eax + 0x100))(edi);
                            if (eax == 0x0) {
                                    if (esi != arg_8) {
                                            esp = esp - 0x4;
                                            eax = GetParent(esi);
                                            esi = eax;
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            else {
                                    eax = 0x1;
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
                    else {
                            if (esi != arg_8) {
                                    esp = esp - 0x4;
                                    eax = GetParent(esi);
                                    esi = eax;
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
            }
    }
    if (temp_0 == 0x0) {
            eax = 0x0;
    }
    return eax;
}
