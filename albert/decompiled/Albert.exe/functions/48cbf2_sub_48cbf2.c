// sub_48cbf2 @ 0x48cbf2
// hopper name: sub_48cbf2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48cbf2() {
    decomp_var_1c = ebx;
    var_4 = 0x0;
    esp = esp - 0x8;
    decomp_var_20 = ebx;
    asm { pushfd };
    ecx = decomp_var_20;
    esp = esp + 0x4 - 0x4;
    decomp_var_20 = decomp_var_20 ^ 0x200000;
    asm { popfd };
    asm { pushfd };
    esp = esp + 0x4;
    edx = decomp_var_20 - ecx;
    if (edx != 0x0) {
            esp = esp - 0x4;
            decomp_var_20 = ecx;
            asm { popfd };
            asm { cpuid };
            asm { cpuid };
            var_4 = edx;
    }
    esp = esp + 0x4;
    if ((var_4 & 0x4000000) != 0x0 && sub_48cba2() != 0x0) {
            eax = 0x1;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
