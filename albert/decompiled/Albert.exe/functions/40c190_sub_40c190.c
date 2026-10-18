// sub_40c190 @ 0x40c190
// hopper name: sub_40c190
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c190() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = esi[0x6];
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (edx <= 0x0) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    eax = esi[0x1];
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    esp = esp + 0x4;
    if (edx <= 0x1) {
            decomp_var_4 = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_4);
    }
    return eax;
}
