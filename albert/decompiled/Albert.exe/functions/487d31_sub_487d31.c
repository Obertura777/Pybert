// sub_487d31 @ 0x487d31
// hopper name: sub_487d31
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487d31() {
    var_8 = 0x0;
    eax = HeapAlloc(*dword_bc69f4, 0x0, 0x140);
    *dword_bc7214 = eax;
    if (eax != 0x0) {
            *dword_bc69f0 = *dword_bc69f0 & 0x0;
            *dword_bc7210 = *dword_bc7210 & 0x0;
            *dword_bc721c = eax;
            *dword_bc7218 = var_8;
            *dword_bc7220 = 0x10;
    }
    return;
}
