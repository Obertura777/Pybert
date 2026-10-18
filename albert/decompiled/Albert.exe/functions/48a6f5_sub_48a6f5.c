// sub_48a6f5 @ 0x48a6f5
// hopper name: sub_48a6f5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48a6f5() {
    esp = esp - 0x32c;
    decomp_var_330 = esi;
    if ((*(int8_t *)byte_4c9be8 & 0x1) != 0x0) {
            sub_4888e5(0xa);
            ecx = decomp_var_334;
            esp = (esp - 0x4) + 0x4;
    }
    eax = sub_489531();
    if (eax != 0x0) {
            eax = sub_48953e();
            ecx = decomp_var_334;
            esp = (esp - 0x4) + 0x4;
    }
    if ((*(int8_t *)byte_4c9be8 & 0x2) != 0x0) {
            asm { pushfd };
            sub_47ba40(&decomp_var_80, 0x0, 0x50);
            decomp_var_30 = &decomp_var_80;
            SetUnhandledExceptionFilter(0x0);
            esp = (esp + 0x4 - 0xc) + 0xc - 0x8;
            UnhandledExceptionFilter(&decomp_var_30);
    }
    eax = sub_47dae3(0x3);
    asm { int3 };
    return eax;
}
