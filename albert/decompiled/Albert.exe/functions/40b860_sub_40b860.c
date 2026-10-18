// sub_40b860 @ 0x40b860
// hopper name: sub_40b860
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b860() {
    eax = *ecx;
    edx = arg_0;
    eax = eax - 0x10;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = eax[0x1];
    if (esi > edx) {
            edx = esi;
    }
    if (eax[0x3] > 0x1) {
            eax = sub_40b6e0(saved_fp, edx, arg_4, arg_8, arg_c);
    }
    else {
            eax = eax[0x2];
            if (eax < edx) {
                    if (eax > 0x400) {
                            eax = eax + 0x400;
                    }
                    else {
                            eax = eax + eax;
                    }
                    if (eax < edx) {
                            eax = edx;
                    }
                    eax = sub_40b760(arg_0);
            }
    }
    return eax;
}
