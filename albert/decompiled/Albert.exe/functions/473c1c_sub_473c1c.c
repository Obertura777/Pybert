// sub_473c1c @ 0x473c1c
// hopper name: sub_473c1c
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473c1c() {
    esp = esp - 0xc;
    esi = ecx;
    edi = sub_46f313();
    if (edi != 0x0) {
            if (edi[0x8] == esi) {
                    if (*(int8_t *)(sub_4715ba() + 0x14) == 0x0 && (edi != *(sub_4715ba() + 0x4) || sub_477f30() != 0x0)) {
                            esp = esp - 0x4;
                            sub_46e3eb();
                    }
                    edi[0x8] = 0x0;
            }
            if (edi[0x9] == esi) {
                    edi[0x9] = 0x0;
            }
    }
    ecx = esi[0x12];
    if (ecx != 0x0) {
            (*(*ecx + 0x50))();
            esi[0x12] = 0x0;
    }
    ecx = esi[0x13];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            decomp_var_44 = 0x1;
            (*(*ecx + 0x4))(0x1);
    }
    esi[0x13] = esi[0x13] & 0x0;
    if (esi[0x13] != 0x0) {
            edi = *(sub_4715ed() + 0x3c);
            if (edi != 0x0 && edi[0x8] != 0x0) {
                    sub_47ba40(&var_30, 0x0, 0x30);
                    decomp_var_44 = &var_30;
                    decomp_var_48 = 0x0;
                    decomp_var_4c = 0x405;
                    esp = (esp - 0xc) + 0xc - 0x10;
                    SendMessageA(edi[0x8], 0x405, 0x0, decomp_var_44);
            }
    }
    ebx = GetWindowLongA(esi[0x8], 0xfffffffc);
    sub_473a4a();
    esp = esp - 0x10;
    if (GetWindowLongA(esi[0x8], 0xfffffffc) == ebx) {
            eax = *esi;
            eax = (eax[0x3c])();
            eax = *eax;
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    SetWindowLongA(esi[0x8], 0xfffffffc, eax);
            }
    }
    sub_473b68();
    eax = *esi;
    eax = (eax[0x45])();
    return eax;
}
