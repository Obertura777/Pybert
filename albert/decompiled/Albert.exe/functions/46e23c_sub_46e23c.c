// sub_46e23c @ 0x46e23c
// hopper name: sub_46e23c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e23c() {
    esp = esp - 0x4;
    sub_47d6bb(0x4);
    esi = ecx;
    *esi = 0x4b250c;
    ecx = esi[0x16];
    decomp_var_4 = 0x0;
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x4))(0x1);
    }
    ecx = esi[0x22];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x18))(0x1);
    }
    if (*(int8_t *)(sub_4715ba() + 0x14) == 0x0) {
            if (*dword_bc46cc != 0x0) {
                    esp = esp - 0x4;
                    (*(**dword_bc46cc + 0x4))(0x1);
                    *dword_bc46cc = 0x0;
            }
            if (*dword_bc46c8 != 0x0) {
                    esp = esp - 0x4;
                    (*(**dword_bc46c8 + 0x4))(0x1);
                    *dword_bc46c8 = 0x0;
            }
    }
    eax = esi[0x1c];
    if (eax != 0x0) {
            esp = esp - 0x4;
            sub_477dfa(eax);
    }
    eax = esi[0x1d];
    if (eax != 0x0) {
            esp = esp - 0x4;
            sub_477dfa(eax);
    }
    eax = esi[0x48] & 0xffff;
    if (eax != 0x0) {
            esp = esp - 0x4;
            GlobalDeleteAtom(eax);
    }
    eax = esi[0x49] & 0xffff;
    if (eax != 0x0) {
            esp = esp - 0x4;
            GlobalDeleteAtom(eax);
    }
    ecx = esi[0x23];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (*(*ecx + 0x4))(0x1);
    }
    eax = sub_4715ba();
    if (eax[0x4] == esi[0x14]) {
            eax[0x4] = 0x0;
    }
    if (eax[0x1] == esi) {
            eax[0x1] = 0x0;
    }
    sub_47c8f9();
    sub_47c8f9();
    sub_47c8f9();
    sub_47c8f9();
    sub_47c8f9();
    esi[0xb] = 0x0;
    sub_46f397();
    eax = sub_47d75a();
    return eax;
}
