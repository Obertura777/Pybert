// sub_45e820 @ 0x45e820
// hopper name: sub_45e820
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45e820() {
    var_C = *0x0;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    *0x0 = &var_C;
    esi = ecx;
    var_14 = esi;
    *esi = 0x4b197c;
    sub_45f9e0();
    eax = esi[0x19];
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (edx <= 0x0) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    eax = esi[0x14];
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_45bc50();
    sub_47c8f9();
    *(esi + 0x44) = 0x0;
    sub_465fa0();
    sub_401900();
    eax = esi[0x4];
    sub_41a200(&var_14, esi + 0xc, *eax, esi + 0xc, eax);
    eax = sub_47c8f9();
    *(esi + 0x10) = 0x0;
    *(esi + 0x14) = 0x0;
    *0x0 = var_C;
    return eax;
}
