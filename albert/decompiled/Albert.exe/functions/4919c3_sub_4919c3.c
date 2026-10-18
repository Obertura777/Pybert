// sub_4919c3 @ 0x4919c3
// hopper name: sub_4919c3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4919c3() {
    eax = 0x0;
    if ((edx & 0x10) != 0x0) {
            eax = 0x80;
    }
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if ((edx & 0x8) != 0x0) {
            eax = eax | 0x200;
    }
    if ((edx & 0x4) != 0x0) {
            eax = eax | 0x400;
    }
    if ((edx & 0x2) != 0x0) {
            eax = eax | 0x800;
    }
    if ((edx & 0x1) != 0x0) {
            eax = eax | 0x1000;
    }
    if ((edx & 0x80000) != 0x0) {
            eax = eax | 0x100;
    }
    ecx = edx & 0x300;
    if (ecx != 0x0) {
            switch (ecx) {
                case 256:
                    eax = eax | 0x2000;
                    break;
                case 512:
                    eax = eax | 0x4000;
                    break;
                case 768:
                    eax = eax | 0x6000;
                    break;
            }
    }
    edx = edx & 0x3000000;
    switch (edx) {
        case 16777216:
            eax = eax | 0x8040;
            break;
        case 33554432:
            eax = eax | 0x40;
            break;
        default:
            if (edx == 0x3000000) {
                    eax = eax | 0x8000;
            }
            break;
    }
    return eax;
}
