// sub_4703ba @ 0x4703ba
// hopper name: sub_4703ba
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4703ba() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if ((esi[0x3c] & 0x18) != 0x0) {
            esp = esp - 0x4;
            (*(*esi + 0x84))(arg_0);
    }
    EndDialog(esi[0x8], arg_0);
    return;
}
