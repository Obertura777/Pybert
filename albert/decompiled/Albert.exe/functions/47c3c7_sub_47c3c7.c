// sub_47c3c7 @ 0x47c3c7
// hopper name: sub_47c3c7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c3c7() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    if (esi == 0x0) {
            sub_47c409();
    }
    else {
            eax = sub_47c365(esi);
            esp = (esp - 0x4) + 0x4;
            if (eax == 0x0 && (esi[0x6] & 0x4000) != 0x0) {
                    sub_4867ae(esi);
                    sub_4879af();
            }
    }
    return;
}
