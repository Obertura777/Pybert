// sub_446630 @ 0x446630
// hopper name: sub_446630
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_446630() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    ebx = ecx;
    esi = edi;
    if (edi[0x629] == 0x0) {
            do {
                    sub_446630(esi[0x2]);
                    esi = *esi;
                    sub_42ee00();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x629] == 0x0);
    }
    return;
}
