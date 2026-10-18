// sub_4064f0 @ 0x4064f0
// hopper name: sub_4064f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4064f0() {
    var_C = *0x0;
    decomp_var_1c = edi;
    *0x0 = &var_C;
    ecx[0x2] = 0x0;
    ecx[0x6] = 0x0;
    ecx[0xc] = 0x0;
    *(ecx + 0x28) = sub_4018e0();
    *(ecx + 0x2c) = 0x0;
    eax = sub_401e30();
    *(ecx + 0x38) = eax;
    eax[0x11] = 0x1;
    eax = *(ecx + 0x38);
    eax[0x1] = eax;
    eax = *(ecx + 0x38);
    *eax = eax;
    eax = *(ecx + 0x38);
    eax[0x2] = eax;
    *(ecx + 0x3c) = 0x0;
    ecx[0x2f] = 0x0;
    eax = sub_40ff50();
    *(ecx + 0x64) = eax;
    eax[0x15] = 0x1;
    eax = *(ecx + 0x64);
    eax[0x1] = eax;
    eax = *(ecx + 0x64);
    *eax = eax;
    eax = *(ecx + 0x64);
    eax[0x2] = eax;
    *(ecx + 0x68) = 0x0;
    eax = ecx;
    *0x0 = var_C;
    return eax;
}
