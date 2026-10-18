// sub_493303 @ 0x493303
// hopper name: sub_493303
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493303() {
    esp = esp - 0x4;
    sub_4931ea(0x0);
    if (*dword_bc6fdc != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = esi;
            do {
                    eax = *dword_bc6fdc;
                    *dword_bc6fdc = *eax;
                    sub_49321d();
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            } while (*dword_bc6fdc != 0x0);
    }
    eax = sub_49320b();
    return eax;
}
