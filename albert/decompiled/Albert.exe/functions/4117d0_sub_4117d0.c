// sub_4117d0 @ 0x4117d0
// hopper name: sub_4117d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4117d0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_58 = ebx;
    decomp_var_5c = esi;
    esi = **dword_bb65cc;
    esp = esp - 0x60;
    decomp_var_60 = edi;
    edi = 0xbb65c8;
    var_4D = 0x0;
    var_40 = 0xbb65c8;
    var_3C = **dword_bb65cc;
    goto loc_4117f5;

loc_4117f5:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi == *dword_bb65cc) goto .l8;
    goto loc_411814;

.l8:
    break;

loc_411814:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x20] != 0x0) {
            sub_40f860();
            esi = var_3C;
            edi = var_40;
            continue;
    }
    if (arg_0 != 0xffffffff) goto loc_411906;
    goto loc_41183b;
    eax = var_4D;
    &decomp_var_54 = ebp;
    return eax;

loc_411906:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_10 = esi != edi[0x1];
    ebx = esi + 0x30;
    var_24 = esi[0xd];
    if (!bool_10) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&var_10, &arg_0, decomp_var_60, decomp_var_5c, decomp_var_58);
    ecx = *eax;
    var_4C = eax;
    if (ecx == 0x0 || ecx != ebx) {
            sub_47a948();
            eax = var_4C;
    }
    if (eax[0x1] != var_24) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_4 = esi != edi[0x1];
            ebx = esi + 0x3c;
            var_1C = esi[0x10];
            if (!bool_4) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_8, &arg_0, decomp_var_60, decomp_var_5c, decomp_var_58);
            esi = eax;
            eax = *esi;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (esi[0x1] == var_1C) {
                    var_4D = 0x1;
            }
    }
    goto loc_4119a1;

loc_41183b:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = esi + 0x30;
    var_48 = ebx;
    var_44 = *esi[0xd];
    goto loc_411855;

loc_4119a1:
    sub_40f860();
    esi = var_3C;
    edi = var_40;
    continue;

loc_411855:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi + 0x30;
    var_34 = esi[0xd];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (var_44 != var_34) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edi = esi + 0x3c;
            var_2C = esi[0x10];
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_44 == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = var_44 + 0xc;
            if (esi == var_40[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_18, ebx, decomp_var_60, decomp_var_5c, decomp_var_58);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (ebx[0x1] == var_2C) {
                    var_4D = 0x1;
            }
            sub_401520();
            ebx = var_48;
            edi = var_40;
            continue;
    }
    break;
}
