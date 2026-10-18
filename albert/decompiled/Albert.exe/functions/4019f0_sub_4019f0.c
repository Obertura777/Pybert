// sub_4019f0 @ 0x4019f0
// hopper name: sub_4019f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4019f0() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    ebx = ecx;
    esi = edi;
    if (edi[0x15] == 0x0) {
            do {
                    sub_4019f0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x15] == 0x0);
    }
    return;
}
