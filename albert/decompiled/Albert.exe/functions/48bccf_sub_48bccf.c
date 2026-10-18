// sub_48bccf @ 0x48bccf
// hopper name: sub_48bccf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bccf() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = 0x0;
    while (true) {
            ecx = *(int8_t *)edx;
            if (ecx == 0x0) {
                    break;
            }
            edx = edx + 0x1;
            if (ecx <= 0x66) {
                    ecx = ecx + 0xd9;
            }
            else {
                    if (ecx <= 0x46) {
                            ecx = ecx + 0xf9;
                    }
            }
            esi = (esi << 0x4) + (sign_extend_32(ecx) - 0x30);
    }
    eax = esi;
    return eax;
}
