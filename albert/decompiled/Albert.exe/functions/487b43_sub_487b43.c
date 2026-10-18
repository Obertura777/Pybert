// sub_487b43 @ 0x487b43
// hopper name: sub_487b43
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487b43() {
    esp = esp - 0x8;
    sub_47f31c(0x4c38b0, 0xc);
    decomp_var_1c = 0x1;
    if (*dword_bc69f4 == 0x0) {
            sub_488a85();
            sub_4888e5(0x1e);
            sub_47d8a0(0xff);
    }
    esi = arg_4 * 0x8 + 0x4c9980;
    if (*esi == 0x0) {
            ebx = 0x0;
            esp = (esp - 0x4) + 0x4;
            edi = sub_481280(0x18);
            if (edi == 0x0) {
                    *sub_47d812() = 0xc;
            }
            else {
                    sub_487c06(0xa);
                    esp = (esp - 0x4) + 0x4;
                    if (*esi == ebx) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_489876() == 0x0) {
                                    sub_47c8f9();
                                    *sub_47d812() = 0xc;
                                    decomp_var_1c = ebx;
                            }
                            else {
                                    *esi = edi;
                            }
                    }
                    else {
                            sub_47c8f9();
                    }
                    sub_487bfd();
            }
    }
    sub_47f361();
    return;
}
