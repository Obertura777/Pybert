// sub_4805e7 @ 0x4805e7
// hopper name: sub_4805e7
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4805e7() {
    decomp_var_4 = 0x8;
    esp = esp - 0x8;
    sub_47f31c(0x4c3600, 0x8);
    ecx = arg_4;
    if (ecx != 0x0 && *ecx == 0xe06d7363) {
            eax = ecx[0x7];
            if (eax != 0x0) {
                    eax = eax[0x1];
                    if (eax != 0x0) {
                            sub_47a9d2(ecx[0x6], eax);
                    }
            }
    }
    sub_47f361();
    return;
}
