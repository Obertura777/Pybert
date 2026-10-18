// sub_45ebb0 @ 0x45ebb0
// hopper name: sub_45ebb0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ebb0() {
    decomp_var_c = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    *0x0 = &decomp_var_c;
    esi = ecx;
    *esi = 0x4b197c;
    eax = sub_40ff10();
    *(esi + 0x10) = eax;
    eax[0xf] = 0x1;
    eax = *(esi + 0x10);
    eax[0x1] = eax;
    eax = *(esi + 0x10);
    *eax = eax;
    eax = *(esi + 0x10);
    eax[0x2] = eax;
    *(esi + 0x14) = 0x0;
    *(esi + 0x1c) = sub_45bac0();
    *(esi + 0x20) = 0x0;
    sub_465870();
    *(esi + 0x44) = sub_45baa0();
    *(esi + 0x48) = 0x0;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            esi[0x14] = (*(*eax + 0xc))() + 0x10;
            eax = sub_47020b();
            if (eax == 0x0) {
                    eax = sub_40b5a0(0x80004005);
            }
            else {
                    esi[0x19] = (*(*eax + 0xc))() + 0x10;
                    esi[0x1] = 0x0;
                    *dword_bc2124 = esi;
                    esi[0x28] = 0x0;
                    esi[0x2] = sub_465680();
                    esi[0x3c] = 0x0;
                    eax = esi;
                    *0x0 = decomp_var_c;
            }
    }
    return eax;
}
