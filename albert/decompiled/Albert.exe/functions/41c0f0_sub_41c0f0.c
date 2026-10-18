// sub_41c0f0 @ 0x41c0f0
// hopper name: sub_41c0f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c0f0() {
    decomp_var_c = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ &decomp_var_24;
    *0x0 = &decomp_var_c;
    ebx = sub_465930();
    esp = esp - 0x2c;
    sub_410c30(*(*((arg_10 + arg_10 * 0x2) * 0x4 + 0xbb6e14) + 0x4));
    eax = *((arg_10 + arg_10 * 0x2) * 0x4 + 0xbb6e14);
    eax[0x1] = eax;
    eax = *((arg_10 + arg_10 * 0x2) * 0x4 + 0xbb6e14);
    *((arg_10 + arg_10 * 0x2) * 0x4 + 0xbb6e18) = 0x0;
    *eax = eax;
    eax = *((arg_10 + arg_10 * 0x2) * 0x4 + 0xbb6e14);
    eax[0x2] = eax;
    if (ebx > 0x0) {
            sub_41c160(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
    }
    sub_465fa0();
    *0x0 = decomp_var_c;
    return;
}
