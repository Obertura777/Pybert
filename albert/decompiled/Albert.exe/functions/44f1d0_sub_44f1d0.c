// sub_44f1d0 @ 0x44f1d0
// hopper name: sub_44f1d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44f1d0() {

sub_44f1d0:
    eax = ebx[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    arg_98 = ecx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == arg_98) goto loc_44f312;
    goto loc_44f1ff;

loc_44f312:
    edx = 0x0;
    if (*(ebx[0x2] + 0x2400) <= 0x0) goto .l1;
    goto .l2;

loc_44f1ff:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4) goto loc_44f2f8;
    goto loc_44f21e;

.l1:
    eax = (null)();
    return eax;

.l2:
    esi = 0x0;
    goto loc_44f321;

loc_44f2f8:
    sub_401390();
    esi = arg_14;
    edi = arg_10;
    ebx = arg_c;
    goto sub_44f1d0;

loc_44f21e:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x2) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x6) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi + 0x14;
                    esi = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi + 0x28;
                    esi = esi[0x9];
            }
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
            }
            eax = esi + 0x28;
            esi = esi[0x9];
    }
    esp = esp - 0x4;
    edi = sub_4075b0(eax, saved_fp);
    ebx = *edi[0x1];
    esi = edi;
    arg_24 = esi;
    arg_28 = ebx;
    goto loc_44f2a0;

loc_44f321:
    ecx = ebx[0x2];
    eax = esi + ecx;
    if (*(int8_t *)(esi + ecx + 0x3) != 0x0) {
            eax = eax[0x10];
            ecx = eax & 0xff;
            if (HIBYTE(eax) != 0x41) {
                    ecx = 0x14;
            }
            eax = arg_4;
            if (eax != ecx) {
                    eax = eax * 0x15 + ecx;
                    bool_21 = *(eax * 0x8 + 0x4d552c) > 0x0;
                    if (*(eax * 0x8 + 0x4d552c) >= 0x0 && (bool_21 || *(eax * 0x8 + 0x4d5528) > 0x1)) {
                            if (*(&saved_fp + edx * 0x4 + 0x71c) > 0x1) {
                                    *dword_62be94 = *dword_62be94 + 0xa0;
                            }
                    }
            }
    }
    edx = edx + 0x1;
    esi = esi + 0x24;
    if (edx < *(ebx[0x2] + 0x2400)) goto .l3;
    goto loc_44f321;

loc_44f2a0:
    arg_90 = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (ebx == arg_90) goto loc_44f2f8;
    goto loc_44f2c0;

.l3:
    eax = (null)();
    return eax;

loc_44f2c0:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    eax = ebx[0x3];
    *(&saved_fp + eax * 0x4 + 0x71c) = *(&saved_fp + eax * 0x4 + 0x71c) + 0x1;
    sub_40f400();
    ebx = arg_28;
    esi = arg_24;
    goto loc_44f2a0;
}
