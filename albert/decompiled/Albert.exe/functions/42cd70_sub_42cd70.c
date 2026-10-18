// sub_42cd70 @ 0x42cd70
// hopper name: sub_42cd70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42cd70() {
    decomp_var_c = *0x0;
    decomp_var_70 = esi;
    decomp_var_74 = edi;
    esp = esp - 0x78;
    decomp_var_78 = *dword_4c8db8 ^ &decomp_var_74;
    *0x0 = &decomp_var_c;
    decomp_var_5c = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_60 = (*(*eax + 0xc))() + 0x10;
            esi = sub_4658d0();
            edi = esi + 0x1;
            eax = sub_46dbce(-((-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) + 0x4);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    ebp = eax + 0x4;
                    decomp_var_88 = 0x2;
                    esp = esp - 0x14;
                    decomp_var_8c = ebp;
                    *eax = edi;
                    sub_47bba4();
            }
            else {
                    ebp = 0x0;
            }
            ebx = 0x0;
            esp = esp - 0x8;
            sub_465890(ebp, edi);
            ecx = 0x0;
            eax = 0x0;
            if (esi > 0x0) {
                    do {
                            if (*(int16_t *)word_4c6d5c == *(int16_t *)(ebp + eax * 0x2)) {
                                    ecx = ecx + 0x1;
                            }
                            eax = eax + 0x1;
                    } while (eax < esi);
            }
            esi = esi - ecx;
            edi = esi + 0x1;
            eax = sub_46dbce(-((-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) + 0x4);
            esp = (esp - 0x4) + 0x4;
            if (eax != ebx) {
                    ebx = eax + 0x4;
                    decomp_var_88 = 0x2;
                    esp = esp - 0x14;
                    decomp_var_8c = ebx;
                    *eax = edi;
                    sub_47bba4();
            }
            edx = 0x0;
            eax = 0x0;
            decomp_var_64 = ebx;
            if (esi > 0x0) {
                    ecx = ebx;
                    edi = ebp - ebx;
                    &decomp_var_78 = &decomp_var_78;
                    do {
                            if (*(int16_t *)word_4c6d5c == *(int16_t *)(edi + ecx)) {
                                    edx = edx + 0x1;
                            }
                            *(int16_t *)ecx = *(int16_t *)(ebp + (eax + edx) * 0x2);
                            eax = eax + 0x1;
                            ecx = ecx + 0x2;
                    } while (eax < esi);
                    ebx = decomp_var_64;
            }
            sub_465940(ebx, esi, decomp_var_78);
            esp = esp - 0xc;
            eax = sub_46b050(&decomp_var_28, decomp_var_78, decomp_var_74);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            edx = &decomp_var_60;
            decomp_var_80 = "message :%s";
            decomp_var_84 = edx;
            sub_410c10(decomp_var_84, "message :%s", eax);
            esp = (esp - 0xc) + 0xc;
            decomp_var_4 = 0x4;
            if (decomp_var_10 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            decomp_var_14 = 0x0;
            decomp_var_24 = 0x0;
            if (ebp != 0x0) {
                    decomp_var_80 = decomp_var_4;
                    decomp_var_84 = 0x2;
                    decomp_var_88 = ebp;
                    sub_47b6f8();
                    sub_47c8f9();
                    esp = (esp - 0x14) + 0x4;
            }
            if (ebx != 0x0) {
                    edx = *(ebx - 0x4);
                    decomp_var_80 = edx;
                    decomp_var_84 = 0x2;
                    decomp_var_88 = ebx;
                    sub_47b6f8();
                    sub_47c8f9();
                    esp = (esp - 0x14) + 0x4;
            }
            ecx = &decomp_var_58;
            if (sub_4658d0() > 0x0) {
                    decomp_var_7c = ecx;
                    decomp_var_7c = *(int16_t *)word_4c6cf0;
                    edx = arg_10;
                    decomp_var_80 = edx;
                    esp = esp - 0x1c;
                    sub_465f60(&decomp_var_58);
                    sub_42c970();
            }
            eax = decomp_var_78 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            eax = sub_465fa0();
            *0x0 = decomp_var_24;
    }
    return eax;
}
