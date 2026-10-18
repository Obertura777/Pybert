// sub_467c60 @ 0x467c60
// hopper name: sub_467c60
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467c60() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = ebp;
    ebp = arg_10;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_4;
    esi = edi - ebx;
    if (ebp < esi) {
            sub_47a948();
    }
    sub_47a5af(arg_c, ebp, ebx, esi);
    eax = edi;
    return eax;
}
