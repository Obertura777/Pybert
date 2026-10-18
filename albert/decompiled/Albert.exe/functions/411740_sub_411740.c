// sub_411740 @ 0x411740
// hopper name: sub_411740
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_411740() {
    esp = esp - 0xc;
    decomp_var_c = ebx;
    ebx = 0x1;
    if (*(int8_t *)byte_baed46 != 0x1) goto loc_4117bc;
    goto loc_41174e;

loc_4117bc:
    eax = ebx;
    return eax;

loc_41174e:
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esi = 0xbb65ec;
    ebp = **dword_bb65f0;
    esp = esp - 0xc;
    decomp_var_18 = edi;
    var_8 = 0xbb65ec;
    var_4 = **dword_bb65f0;
    goto loc_411770;

loc_411770:
    if (esi == 0x0 || esi != 0xbb65ec) {
            sub_47a948();
    }
    if (ebp != *dword_bb65f0) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            if (arg_14 == 0x0) {
                    ebx = 0x0;
            }
            sub_40f470();
            ebp = var_4;
            esi = var_8;
            continue;
    }
    break;
    esp = esp + 0xc;
    goto loc_4117bc;
}
