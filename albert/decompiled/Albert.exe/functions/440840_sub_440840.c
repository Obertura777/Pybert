// sub_440840 @ 0x440840
// hopper name: sub_440840
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_440840() {
    decomp_var_4 = ecx;
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    ebp = ecx;
    decomp_var_14 = edi;
    esp = esp - 0x18;
    var_1 = 0x0;
    eax = sub_407720(&arg_4);
    edi = eax;
    if (*(int16_t *)word_4c6c08 == edi[0x2]) {
            var_1 = 0x1;
    }
    ebx = arg_4;
    sub_460670(ebx);
    esi = ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx);
    esi[0x2ebb68] = 0x1;
    esi[0x2ebb6a] = *edi;
    ecx = edi[0x1];
    esp = esp - 0x8;
    decomp_var_18 = edi;
    edi = arg_0;
    esi[0x2ebb6b] = ecx;
    esi[0x2ebb75] = 0x1;
    eax = sub_41c1e0(decomp_var_18);
    esi[0x2ebb6e] = *eax;
    esi[0x2ebb6f] = eax[0x1];
    if (var_1 == 0x1) {
            esi[0x2ebb80] = 0x0;
            esi[0x2ebb81] = 0x0;
    }
    eax = sub_437510(edi, ebx);
    return eax;
}
