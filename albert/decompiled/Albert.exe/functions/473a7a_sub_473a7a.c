// sub_473a7a @ 0x473a7a
// hopper name: sub_473a7a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473a7a() {
    esp = esp - 0x4;
    decomp_var_4 = 0x0;
    sub_47d6bb(0x0);
    esi = sub_4715ed();
    if (esi[0x5] == 0x0 && arg_4 != 0x0) {
            ebx = sub_46dbbc(0x477e2d);
            esp = (esp - 0x8) + 0x4;
            decomp_var_4 = decomp_var_4 & 0x0;
            if (sub_46dbce(0x60) != 0x0) {
                    esp = esp - 0x14;
                    eax = sub_47819a();
            }
            else {
                    eax = 0x0;
            }
            esi[0x5] = eax;
            sub_46dbbc(ebx);
    }
    eax = sub_47d75a();
    return eax;
}
