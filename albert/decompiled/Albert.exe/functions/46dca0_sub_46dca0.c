// sub_46dca0 @ 0x46dca0
// hopper name: sub_46dca0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46dca0() {
    eax = arg_8;
    esp = esp - 0x4;
    if (eax != 0x0) {
            *eax = 0x0;
    }
    esp = esp - 0x1c;
    eax = FormatMessageA(0x1100, 0x0, ecx[0x2], 0x800, &arg_8, 0x0, 0x0);
    if (eax == 0x0) {
            *(int8_t *)arg_0 = 0x0;
            eax = 0x0;
    }
    else {
            sub_46dc28(arg_0, arg_4, arg_8, 0xffffffff);
            esp = (esp - 0x10) + 0x10 - 0x4;
            LocalFree(arg_8);
            eax = 0x1;
    }
    return eax;
}
