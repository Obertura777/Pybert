// sub_40b470 @ 0x40b470
// hopper name: sub_40b470
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b470() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (esi[0x93c] != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            do {
                    eax = esi[0x93b];
                    edi = *eax;
                    if (edi == eax) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_40b350(edi[0x3]);
            } while (esi[0x93c] != 0x0);
            esp = esp + 0x4;
    }
    return;
}
