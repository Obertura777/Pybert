// sub_46ddfb @ 0x46ddfb
// hopper name: sub_46ddfb
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ddfb() {
    var_4 = *dword_4c8db8 ^ ebp;
    eax = *ecx;
    esp = esp - 0xc;
    eax = (eax[0x3])(&var_204, 0x200, &var_208);
    if (eax != 0x0) {
            sub_4700ea(&var_204, arg_0, var_208);
    }
    else {
            if (arg_4 == 0x0) {
                    arg_4 = 0xf020;
            }
            sub_470133();
    }
    eax = sub_47ad69();
    return eax;
}
