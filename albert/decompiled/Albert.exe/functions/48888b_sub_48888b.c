// sub_48888b @ 0x48888b
// hopper name: sub_48888b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48888b() {
    esp = esp - 0xc;
    *dword_bc69f4 = HeapCreate(arg_0 == 0x0 ? 0x1 : 0x0, 0x1000, 0x0);
    if (arg_0 == 0x0) {
            eax = 0x0;
    }
    else {
            eax = sub_488830();
            *dword_bc720c = eax;
            if (eax == 0x3) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_487d31() == 0x0) {
                            HeapDestroy(*dword_bc69f4);
                            *dword_bc69f4 = *dword_bc69f4 & 0x0;
                            eax = 0x0;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x1;
            }
    }
    return eax;
}
