// sub_40b560 @ 0x40b560
// hopper name: sub_40b560
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b560() {
    eax = ecx[0x1225] & 0xffff;
    if (*(int16_t *)word_4c60e4 != eax && *(int16_t *)word_4c60ec != eax) {
            if (*(int16_t *)word_4c60e8 != eax) {
                    if (*(int16_t *)word_4c60f0 != eax) {
                            eax = sub_40a9f0();
                    }
                    else {
                            eax = sub_4098b0(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34);
                    }
            }
            else {
                    eax = sub_4098b0(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34);
            }
    }
    else {
            eax = sub_40b4b0();
    }
    return eax;
}
