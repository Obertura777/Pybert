// sub_401890 @ 0x401890
// hopper name: sub_401890
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401890() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_4;
    esi = ecx;
    if (arg_0 != 0x0 && esi[0x6] >= 0x10) {
            eax = esi + 0x4;
            esp = esp - 0x4;
            decomp_var_c = ebx;
            ebx = *eax;
            if (edi > 0x0) {
                    sub_47a5af(eax, 0x10, ebx, edi);
                    esp = (esp - 0x10) + 0x10;
            }
            sub_47c8f9();
            esp = (esp - 0x4) + 0x8;
    }
    esi[0x5] = edi;
    esi[0x6] = 0xf;
    *(int8_t *)(esi + edi + 0x4) = 0x0;
    return;
}
