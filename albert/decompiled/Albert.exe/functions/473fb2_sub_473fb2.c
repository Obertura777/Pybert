// sub_473fb2 @ 0x473fb2
// hopper name: sub_473fb2
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473fb2() {
    decomp_var_20 = ebx;
    esp = esp - 0xc;
    ebx = ecx;
    while (true) {
            esp = esp - 0x14;
            eax = PeekMessageA(&var_1C, 0x0, 0x121, 0x121, 0x1);
            if (eax == 0x0) {
                    break;
            }
            esp = esp - 0x4;
            eax = DispatchMessageA(&var_1C);
    }
    eax = sub_473a4a();
    return eax;
}
