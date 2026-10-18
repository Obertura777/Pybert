// sub_40bb60 @ 0x40bb60
// hopper name: sub_40bb60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bb60() {
    esp = esp - 0x4;
    esi = arg_0;
    if (esi == 0x0) {
            eax = sub_40ba60();
    }
    else {
            eax = esi;
            esp = esp - 0x4;
            var_8 = edi;
            edi = eax + 0x1;
            &var_8 = &var_8;
            do {
                    edx = *(int8_t *)eax;
                    eax = eax + 0x1;
            } while (edx != 0x0);
            eax = sub_40ba60();
    }
    return eax;
}
