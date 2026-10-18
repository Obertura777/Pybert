// sub_448760 @ 0x448760
// hopper name: sub_448760
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_448760() {

sub_448760:
    esi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi == esi) goto loc_448958;
    goto loc_448778;

loc_448958:
    sub_401390();
    eax = loc_4486e0();
    return eax;

loc_448778:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x3] == arg_18) goto loc_448925;
    goto loc_448798;

loc_448925:
    esi = arg_24;
    if (esi == arg_20[0x1]) {
            sub_47a948();
    }
    arg_18 = esi[0x3];
    sub_40f400();
    edi = arg_24;
    ebx = arg_20;
    eax = arg_14;
    goto sub_448760;

loc_448798:
    esi = arg_24;
    if (esi == arg_20[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    bool_25 = *(eax * 0x8 + 0x4d2e14) > 0x0;
    bool_4 = *(eax * 0x8 + 0x4d2e14) < 0x0;
    if (bool_25 || !bool_4 && *(eax * 0x8 + 0x4d2e10) >= 0x0) goto loc_448925;

loc_4487cb:
    esi = arg_24;
    edi = arg_20;
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(arg_24 + 0x10, saved_fp);
    edi = *eax[0x1];
    ebx = eax;
    arg_38 = eax;
    arg_A8 = ebx;
    arg_AC = edi;
    goto loc_448820;

loc_448820:
    esi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi == esi) goto loc_448925;

loc_448838:
    if (arg_40 == arg_3c[0x1]) {
            sub_47a948();
    }
    eax = arg_40[0x4];
    esi = arg_10 << 0x8;
    eax = eax + esi;
    if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            if ((*((eax + esi) * 0x8 + 0x520ce8) | *((eax + esi) * 0x8 + 0x520cec)) == 0x0) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    *((eax + esi) * 0x8 + 0x5850e8) = *((eax + esi) * 0x8 + 0x5850e8) + 0x1;
                    *((eax + esi) * 0x8 + 0x5850ec) = *((eax + esi) * 0x8 + 0x5850ec) + 0x0 + CARRY(EFLAGS(cf));
            }
    }
    if (arg_40 == arg_3c[0x1]) {
            sub_47a948();
    }
    if (arg_40[0x6] != arg_10) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + esi) * 0x8 + 0x57a8e8) = *((eax + esi) * 0x8 + 0x57a8e8) + 0x1;
            *((eax + esi) * 0x8 + 0x57a8ec) = *((eax + esi) * 0x8 + 0x57a8ec) + 0x0 + CARRY(EFLAGS(cf));
    }
    sub_40f400();
    edi = arg_AC;
    ebx = arg_A8;
    eax = arg_38;
    goto loc_448820;
}
