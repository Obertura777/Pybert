// sub_401c20 @ 0x401c20
// hopper name: sub_401c20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401c20() {
    decomp_var_8 = sub_493e30;
    var_C = *0x0;
    esp = esp - 0x28;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    var_10 = &decomp_var_28;
    edi = ecx;
    eax = arg_0;
    esi = eax | 0xf;
    if (esi > 0xfffffffe) {
            esi = eax;
    }
    else {
            ebx = edi[0x6];
            ecx = ebx >> 0x1;
            if (HIDWORD(0xaaaaaaab * esi) >> 0x1 < ecx) {
                    if (ebx <= 0xfffffffe - ecx) {
                            esi = ecx + ebx;
                    }
            }
    }
    var_4 = 0x0;
    esp = (esp - 0x8) + 0x8;
    arg_0 = sub_401620(esi + 0x1);
    ebx = arg_4;
    if (ebx > 0x0) {
            if (edi[0x6] >= 0x10) {
                    eax = edi[0x1];
            }
            else {
                    eax = edi + 0x4;
            }
            sub_47a5af(arg_0, esi + 0x1, eax, ebx);
            esp = (esp - 0x10) + 0x10;
    }
    if (edi[0x6] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    ecx = arg_0;
    eax = edi + 0x4;
    *(int8_t *)eax = 0x0;
    *eax = ecx;
    edi[0x6] = esi;
    edi[0x5] = ebx;
    if (esi >= 0x10) {
            eax = ecx;
    }
    *(int8_t *)(eax + ebx) = 0x0;
    *0x0 = var_C;
    &saved_fp = ebp;
    return eax;
}
