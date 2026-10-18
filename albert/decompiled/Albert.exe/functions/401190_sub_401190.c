// sub_401190 @ 0x401190
// hopper name: sub_401190
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401190() {
    edx = arg_0;
    eax = *edx;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    *edx = eax[0x2];
    esi = eax[0x2];
    if (esi[0x7d] == 0x0) {
            esi[0x1] = edx;
    }
    eax[0x1] = edx[0x1];
    ecx = ecx[0x1];
    if (edx == ecx[0x1]) {
            ecx[0x1] = eax;
            eax[0x2] = edx;
            edx[0x1] = eax;
    }
    else {
            ecx = edx[0x1];
            if (edx == ecx[0x2]) {
                    ecx[0x2] = eax;
                    eax[0x2] = edx;
                    edx[0x1] = eax;
            }
            else {
                    *ecx = eax;
                    eax[0x2] = edx;
                    edx[0x1] = eax;
            }
    }
    return eax;
}
