// sub_40b800 @ 0x40b800
// hopper name: sub_40b800
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b800() {
    decomp_var_4 = esi;
    esi = ecx;
    ecx = *esi;
    bool_0 = *(ecx - 0xc) == 0x0;
    eax = ecx - 0x10;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = *eax;
    if (!bool_0) {
            edx = eax + 0xc;
            if (eax[0x3] < 0x0) {
                    if (*(ecx - 0x8) < 0x0) {
                            sub_40b5a0(0x80070057);
                    }
                    else {
                            *(ecx - 0xc) = 0x0;
                            *(int8_t *)*esi = 0x0;
                    }
            }
            else {
                    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *esi = (*(*edi + 0xc))() + 0x10;
            }
    }
    return;
}
