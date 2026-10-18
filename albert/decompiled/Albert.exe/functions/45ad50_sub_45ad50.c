// sub_45ad50 @ 0x45ad50
// hopper name: sub_45ad50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ad50() {
    var_C = *0x0;
    decomp_var_30 = ebx;
    decomp_var_34 = esi;
    decomp_var_38 = edi;
    decomp_var_3c = *dword_4c8db8 ^ &decomp_var_38;
    *0x0 = &var_C;
    esi = ecx;
    ebx = arg_0;
    esp = esp - 0x40;
    eax = sub_465470(ebx);
    edi = edi | 0xffffffff;
    if (eax != edi) {
            sub_45f930("Failed to set map - Error location %d", eax);
            esp = (esp - 0x8) + 0x8;
    }
    esp = esp - 0x4;
    (*(*esi + 0xdc))(ebx);
    ecx = &var_2C;
    if (esi[0x3c] == 0x0) {
            sub_45a9b0(sub_466f80(ecx, esi + 0x2c));
            eax = sub_465fa0();
            *0x0 = var_C;
    }
    else {
            sub_45a9b0(sub_465f30(word_4c7080));
            sub_465fa0();
            sub_45a9b0(sub_465f30(word_4c70b4));
            sub_465fa0();
            sub_45a9b0(sub_465f30(word_4c70c4));
            sub_465fa0();
            sub_45a9b0(sub_465f30(word_4c70a8));
            eax = sub_465fa0();
            esi[0x3c] = 0x0;
            *0x0 = var_C;
    }
    return eax;
}
