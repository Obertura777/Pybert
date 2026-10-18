// sub_40a870 @ 0x40a870
// hopper name: sub_40a870
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40a870() {
    decomp_var_10 = ebx;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    esp = esp - 0x1c;
    decomp_var_1c = edi;
    edi = ecx;
    ebp = *edi[0x94d];
    esi = edi + 0x2530;
    var_8 = esi;
    var_4 = ebp;
    goto loc_40a890;

loc_40a890:
    ebx = edi[0x94d];
    eax = edi + 0x2530;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (ebp != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            eax = sub_407720(&arg_8);
            esi = eax;
            ebp = sub_407720(esi + 0x14);
            ebx = sub_409640(*esi, 0x1, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
            esp = esp - 0x18;
            var_C = sub_409640(*ebp, 0x1, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
            if (ebx != *ebp && ebx != 0xffffffff) {
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
            if (ebx == *esi) {
                    esp = esp - 0x4;
                    sub_4093f0(*ebp, decomp_var_1c, decomp_var_18, decomp_var_14);
                    sub_401520();
                    ebp = var_4;
                    esi = var_8;
                    continue;
            }
            if (ebx != 0xffffffff) {
                    esp = esp - 0x4;
                    sub_409250(ebx);
                    sub_401520();
                    ebp = var_4;
                    esi = var_8;
                    continue;
            }
            esp = esp - 0x4;
            sub_4093f0(*ebp, decomp_var_1c, decomp_var_18, decomp_var_14);
            sub_401520();
            ebp = var_4;
            esi = var_8;
            continue;
    }
    break;
    return eax;
}
