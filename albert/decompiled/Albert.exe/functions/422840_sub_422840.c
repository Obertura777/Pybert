// sub_422840 @ 0x422840
// hopper name: sub_422840
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_422840() {
    var_C = *0x0;
    *0x0 = &var_C;
    *ecx = 0x4afc74;
    eax = ecx[0x1340];
    sub_413ad0(&var_14, ecx + 0x4cfc, *eax, ecx + 0x4cfc, eax);
    sub_47c8f9();
    *(ecx + 0x4d00) = 0x0;
    *(ecx + 0x4d04) = 0x0;
    sub_47b6f8();
    sub_47b6f8();
    sub_47b6f8();
    sub_47b6f8();
    sub_465fa0();
    eax = sub_45e820();
    *0x0 = var_C;
    return eax;
}
