// sub_46be00 @ 0x46be00
// hopper name: sub_46be00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46be00() {
    decomp_var_8 = ebx;
    decomp_var_c = esi;
    esp = esp - 0x10;
    esi = ecx;
    sub_46bc00(0x41);
    ebx = 0x50;
    var_4 = 0x50;
    do {
            esp = esp - 0x4;
            eax = sub_46bc00(var_4);
            ebx = ebx + 0x1;
            var_4 = ebx;
    } while (ebx <= 0x57);
    return eax;
}
