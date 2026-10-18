// sub_491935 @ 0x491935
// hopper name: sub_491935
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_491935() {
    eax = 0x0;
    if ((ebx & 0x10) != 0x0) {
            eax = 0x1;
    }
    if ((ebx & 0x8) != 0x0) {
            eax = eax | 0x4;
    }
    if ((ebx & 0x4) != 0x0) {
            eax = eax | 0x8;
    }
    if ((ebx & 0x2) != 0x0) {
            eax = eax | 0x10;
    }
    if ((ebx & 0x1) != 0x0) {
            eax = eax | 0x20;
    }
    if ((ebx & 0x80000) != 0x0) {
            eax = eax | 0x2;
    }
    ecx = ebx & 0x300;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (ecx != 0x0) {
            switch (ecx) {
                case 256:
                    eax = eax | 0x400;
                    break;
                case 512:
                    eax = eax | 0x800;
                    break;
                case 768:
                    eax = eax | 0xc00;
                    break;
            }
    }
    ecx = ebx & 0x30000;
    if (ecx != 0x0) {
            if (ecx == 0x10000) {
                    eax = eax | 0x200;
            }
    }
    else {
            eax = eax | 0x300;
    }
    if ((ebx & 0x40000) != 0x0) {
            eax = eax | 0x1000;
    }
    return eax;
}
