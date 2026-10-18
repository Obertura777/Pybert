// sub_41c0b0 @ 0x41c0b0
// hopper name: sub_41c0b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c0b0() {
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_0;
    esi = ecx;
    if (esi != edi) {
            eax = esi[0x1];
            sub_403430(&var_8, esi, *eax, esi, eax);
            esp = esp - 0x18;
            sub_402210(edi);
    }
    eax = esi;
    return eax;
}
