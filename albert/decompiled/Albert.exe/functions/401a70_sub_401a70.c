// sub_401a70 @ 0x401a70
// hopper name: sub_401a70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401a70() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    esi = ecx;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (esi[0x5] < ebx) {
            sub_492fd5();
    }
    eax = esi[0x5];
    edi = arg_4;
    eax = eax - ebx;
    if (eax < edi) {
            edi = eax;
    }
    if (edi > 0x0) {
            ecx = esi[0x6];
            esp = esp - 0x4;
            decomp_var_10 = ebp;
            ebp = esi + 0x4;
            if (ecx >= 0x10) {
                    arg_0 = *ebp;
            }
            else {
                    arg_0 = ebp;
            }
            if (ecx >= 0x10) {
                    edx = *ebp;
            }
            else {
                    edx = ebp;
            }
            sub_47a62a(edx + ebx, ecx - ebx, arg_0 + ebx + edi, eax - edi);
            eax = esi[0x5];
            eax = eax - edi;
            esp = (esp - 0x10) + 0x10;
            bool_4 = esi[0x6] < 0x10;
            esi[0x5] = eax;
            if (!bool_4) {
                    ebp = *ebp;
            }
            *(int8_t *)(eax + ebp) = 0x0;
            esp = esp + 0x4;
    }
    return;
}
