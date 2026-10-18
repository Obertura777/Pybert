// sub_465890 @ 0x465890
// hopper name: sub_465890
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465890() {
    eax = *ecx;
    esp = esp - 0x4;
    decomp_var_4 = ebx;
    if (eax != 0x0) {
            ecx = ecx[0x1];
            if (arg_4 <= ecx) {
                    eax = 0x0;
            }
            else {
                    sub_47c000(arg_0, eax, ecx + ecx + 0x2);
                    eax = 0x1;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
