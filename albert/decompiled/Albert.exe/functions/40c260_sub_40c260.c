// sub_40c260 @ 0x40c260
// hopper name: sub_40c260
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c260() {
    decomp_var_8 = esi;
    esi = arg_4;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = ecx;
    var_4 = 0x0;
    if (esi < 0x0) {
            esi = 0x0;
    }
    eax = *edi;
    if (esi >= *(eax - 0xc)) {
            ecx = sub_40bfa0(eax - 0x10);
            eax = arg_0;
            *eax = ecx + 0x10;
    }
    else {
            ecx = *(eax - 0x10);
            if (ecx != 0x0) {
                    eax = *(*ecx + 0x10);
                    eax = (eax)();
                    if (eax == 0x0) {
                            eax = sub_47020b();
                            eax = *(*eax + 0x10);
                            eax = (eax)();
                    }
            }
            else {
                    eax = sub_47020b();
                    eax = *(*eax + 0x10);
                    eax = (eax)();
            }
            sub_40bf30();
            eax = arg_0;
    }
    return eax;
}
