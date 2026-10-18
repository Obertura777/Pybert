// sub_4060c0 @ 0x4060c0
// hopper name: sub_4060c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4060c0() {

sub_4060c0:
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    esi = ebx[0x5];
    eax = ebx + 0x10;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (arg_4c == esi) goto loc_406223;
    goto loc_4060e7;

loc_406223:
    sub_401590();
    eax = loc_406080(saved_fp);
    return eax;

loc_4060e7:
    arg_7C = arg_2c;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (arg_4c == edi[0x1]) {
            sub_47a948();
    }
    esi = arg_4c + 0xc;
    esp = esp - 0x8;
    eax = sub_402140(&arg_80, esi, saved_fp, arg_0, arg_4);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != &arg_28) {
            sub_47a948();
    }
    if (ebx[0x1] == arg_7C) {
            arg_74 = arg_14;
            if (arg_4c == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402140(&arg_88, esi, saved_fp, arg_0, arg_4);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != &arg_10) {
                    sub_47a948();
            }
            if (ebx[0x1] == arg_74) {
                    ebx = arg_4c;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    arg_54 = *esi;
                    esp = esp - 0x8;
                    eax = sub_404fd0(&arg_98, &arg_54, saved_fp);
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = *esi;
                    ebx = *(arg_50 + (eax + eax * 0x8) * 0x4 + 0x18);
                    esi = arg_50 + (eax + eax * 0x8) * 0x4 + 0x14;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&arg_90, arg_5C, saved_fp, arg_0, arg_4);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
            }
    }
    sub_40f400();
    edi = arg_48;
    esi = arg_3c;
    ebx = arg_40;
    goto sub_4060c0;
}
