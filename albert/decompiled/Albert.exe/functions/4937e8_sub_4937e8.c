// sub_4937e8 @ 0x4937e8
// hopper name: sub_4937e8
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4937e8() {
    var_4 = *dword_4c8db8 ^ ebp;
    esi = 0x0;
    eax = GetThreadLocale();
    esp = esp - 0x14;
    eax = GetLocaleInfoA(eax, 0x1004, &var_C, 0x7);
    if (eax != 0x0) {
            ecx = var_C;
            eax = &var_C;
            if (ecx != 0x0) {
                    do {
                            eax = eax + 0x1;
                            esi = esi * 0xa + (sign_extend_32(ecx) - 0x30);
                            ecx = *(int8_t *)eax;
                    } while (ecx != 0x0);
                    if (esi == 0x0) {
                            esi = GetACP();
                    }
            }
            else {
                    esi = GetACP();
            }
    }
    else {
            esi = GetACP();
    }
    eax = sub_47ad69();
    return eax;
}
