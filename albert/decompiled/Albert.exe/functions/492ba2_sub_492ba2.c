// sub_492ba2 @ 0x492ba2
// hopper name: sub_492ba2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492ba2() {
    decomp_var_4 = esi;
    esi = arg_0;
    eax = sub_48e43c(esi);
    esp = (esp - 0x8) + 0x4;
    if (eax == 0xffffffff) {
            eax = sub_47d812();
            *eax = 0x9;
            eax = eax | 0xffffffff;
    }
    else {
            decomp_var_8 = edi;
            esp = esp - 0x14;
            edi = SetFilePointer(eax, arg_4, 0x0, arg_8);
            if (edi == 0xffffffff) {
                    eax = GetLastError();
            }
            else {
                    eax = 0x0;
            }
            if (eax != 0x0) {
                    eax = sub_47d838(eax);
                    esp = (esp - 0x4) + 0x4;
                    eax = eax | 0xffffffff;
            }
            else {
                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfd;
                    eax = edi;
            }
    }
    return eax;
}
