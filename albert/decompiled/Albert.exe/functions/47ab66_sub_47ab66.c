// sub_47ab66 @ 0x47ab66
// hopper name: sub_47ab66
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ab66() {
    asm { cld };
    sub_47ad69();
    if ((arg_0[0x1] & 0x66) != 0x0) {
            arg_4[0x9] = 0x1;
            eax = 0x1;
    }
    else {
            sub_480fad(arg_0, arg_4[0x4], arg_8, 0x0, arg_4[0x3], arg_4[0x5], arg_4[0x6], 0x1);
            esp = (esp - 0x20) + 0x20;
            if (arg_4[0x9] == 0x0) {
                    esp = esp - 0x8;
                    sub_47a9d9(arg_4, arg_0);
            }
            sub_47aa91(0x123, &var_4, 0x0, 0x0, 0x0, 0x0, 0x0);
            &decomp_var_8 = arg_4[0x7];
            eax = (var_4)();
    }
    return eax;
}
