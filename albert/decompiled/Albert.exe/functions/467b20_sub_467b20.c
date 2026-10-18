// sub_467b20 @ 0x467b20
// hopper name: sub_467b20
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467b20() {
    decomp_var_4 = ebx;
    ebx = arg_4;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = arg_0;
    if (esi != ebx) {
            esp = esp - 0x4;
            decomp_var_c = edi;
            edi = ecx + 0x8;
            do {
                    *(int8_t *)esi = sub_493014(*(int8_t *)esi & 0xff, edi);
                    esi = esi + 0x1;
                    esp = (esp - 0x8) + 0x8;
            } while (esi != ebx);
            esp = esp + 0x4;
    }
    eax = esi;
    return eax;
}
