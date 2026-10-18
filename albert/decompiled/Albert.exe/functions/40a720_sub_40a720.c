// sub_40a720 @ 0x40a720
// hopper name: sub_40a720
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40a720() {
    decomp_var_10 = ebx;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    esp = esp - 0x1c;
    decomp_var_1c = edi;
    edi = ecx;
    ebx = *edi[0x950];
    esi = edi + 0x253c;
    var_8 = esi;
    var_4 = ebx;
    goto loc_40a740;

loc_40a740:
    ebp = edi[0x950];
    eax = edi + 0x253c;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (ebx != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            ebp = sub_407720(ebx + 0xc);
            eax = sub_407720(&arg_10);
            esi = eax;
            esp = esp - 0x10;
            ebx = sub_409640(*esi, 0x1, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
            eax = *ebp;
            if (ebx == eax) {
                    sub_404bc0(esi);
                    esp = esp - 0x8;
                    sub_409250(*ebp);
                    esi[0x5a] = 0x1;
                    esi[0x14] = *ebp;
                    sub_401520();
                    ebx = var_4;
                    esi = var_8;
                    continue;
            }
            esp = esp - 0xc;
            var_C = sub_409640(eax, 0x1, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
            sub_404bc0(esi);
            if (ebx != 0xffffffff) {
                    esp = esp - 0x4;
                    sub_409250(ebx);
                    esi[0x5a] = 0x1;
                    esi[0x14] = ebx;
            }
            else {
                    esp = esp - 0x4;
                    sub_4093f0(*esi, decomp_var_1c, decomp_var_18, decomp_var_14);
            }
            ebx = var_C;
            if (ebx == 0xffffffff) {
                    esp = esp - 0x4;
                    sub_4093f0(*ebp, decomp_var_1c, decomp_var_18, decomp_var_14);
                    sub_401520();
                    ebx = var_4;
                    esi = var_8;
                    continue;
            }
            if (ebx != *esi) {
                    esp = esp - 0x4;
                    sub_409250(ebx);
                    sub_401520();
                    ebx = var_4;
                    esi = var_8;
                    continue;
            }
            esp = esp - 0x4;
            sub_4093f0(*ebp, decomp_var_1c, decomp_var_18, decomp_var_14);
            sub_401520();
            ebx = var_4;
            esi = var_8;
            continue;
    }
    break;
    return eax;
}
