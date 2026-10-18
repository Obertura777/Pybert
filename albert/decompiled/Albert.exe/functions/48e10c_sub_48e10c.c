// sub_48e10c @ 0x48e10c
// hopper name: sub_48e10c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e10c() {
    *dword_bc6894 = *dword_bc6894 + 0x1;
    eax = sub_481280(0x1000);
    ecx = arg_0;
    ecx[0x2] = eax;
    if (eax != 0x0) {
            ecx[0x3] = ecx[0x3] | 0x8;
            ecx[0x6] = 0x1000;
    }
    else {
            ecx[0x3] = ecx[0x3] | 0x4;
            ecx[0x2] = ecx + 0x14;
            ecx[0x6] = 0x2;
    }
    eax = ecx[0x2];
    ecx[0x1] = ecx[0x1] & 0x0;
    *ecx = eax;
    return eax;
}
