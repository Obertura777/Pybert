// sub_48df70 @ 0x48df70
// hopper name: sub_48df70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48df70() {
    decomp_var_c = esi;
    esi = arg_0;
    var_8 = arg_4;
    decomp_var_10 = edi;
    var_4 = arg_8;
    eax = sub_48e43c(esi);
    edi = edi | 0xffffffff;
    esp = (esp - 0xc) + 0x4;
    if (eax == edi) {
            *sub_47d812() = 0x9;
            eax = edi;
    }
    else {
            esp = esp - 0x10;
            eax = SetFilePointer(eax, var_8, &var_4, arg_c);
            var_8 = eax;
            if (eax == edi) {
                    eax = GetLastError();
                    if (eax != 0x0) {
                            sub_47d838(eax);
                            esp = (esp - 0x4) + 0x4;
                            eax = edi;
                    }
                    else {
                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfd;
                            eax = var_8;
                    }
            }
            else {
                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfd;
                    eax = var_8;
            }
    }
    return eax;
}
