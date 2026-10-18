// sub_40bb20 @ 0x40bb20
// hopper name: sub_40bb20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bb20() {
    esp = esp - 0x4;
    edi = ecx;
    ecx = arg_0;
    eax = 0x0;
    if (ecx != 0x0 && (ecx & 0xffff0000) == 0x0) {
            esi = ecx & 0xffff;
            esp = esp - 0x8;
            decomp_var_c = esi;
            eax = sub_4701df();
            if (eax != 0x0) {
                    decomp_var_c = esi;
                    esp = esp - 0x8;
                    decomp_var_10 = eax;
                    sub_40b990();
            }
            eax = 0x1;
            esp = esp + 0x4;
    }
    return eax;
}
