// sub_40a990 @ 0x40a990
// hopper name: sub_40a990
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40a990() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    esi = ecx;
    edi = sub_409640(arg_0, 0x0, decomp_var_c, decomp_var_8, decomp_var_4, saved_fp);
    esp = esp - 0x18;
    decomp_var_10 = arg_0;
    if (edi == 0xffffffff) {
            sub_4093f0(decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4);
            eax = 0x0;
    }
    else {
            sub_4095a0(decomp_var_10);
            sub_409250(edi);
            eax = sub_407720(&arg_0);
            eax[0x14] = edi;
            eax[0x5a] = 0x1;
            eax = 0x1;
    }
    return eax;
}
