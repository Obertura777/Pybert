// sub_44a840 @ 0x44a840
// hopper name: sub_44a840
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44a840() {

sub_44a840:
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l1;
    goto .l2;

.l1:
    eax = (null)();
    return eax;

.l2:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x10, saved_fp);
    esi = *eax[0x1];
    ebx = eax;
    arg_28 = eax;
    arg_4c = ebx;
    arg_50 = esi;
    goto loc_44a8a2;

loc_44a8a2:
    eax = arg_28;
    arg_A0 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == arg_A0) goto loc_44a9a2;
    goto loc_44a8ca;

loc_44a9a2:
    sub_40f400();
    edi = arg_1c;
    esi = arg_18;
    eax = arg_14;
    goto sub_44a840;

loc_44a8ca:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(arg_c[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = *(int16_t *)(arg_c[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
            bool_14 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_14) {
                    eax = 0x14;
            }
            ecx = arg_10;
            if (eax != ecx && *((ecx * 0x15 + eax) * 0x4 + 0x634e90) < 0xa) {
                    if (edi == arg_18[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    esi = arg_10 << 0x8;
                    eax = eax + esi;
                    if (*(eax * 0x8 + 0x5ee8e8) == 0x1 && *(eax * 0x8 + 0x5ee8ec) == 0x0) {
                            if (edi == arg_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x3];
                            *((eax + esi) * 0x8 + 0x5ee8e8) = 0xfffffff6;
                            *((eax + esi) * 0x8 + 0x5ee8ec) = 0xffffffff;
                    }
            }
    }
    sub_40f400();
    esi = arg_50;
    ebx = arg_4c;
    goto loc_44a8a2;
}
