// sub_42ee00 @ 0x42ee00
// hopper name: sub_42ee00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42ee00() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = ecx[0x185];
    sub_4225b0(&var_14, ecx + 0x610, *eax, ecx + 0x610, eax);
    sub_47c8f9();
    *(ecx + 0x614) = 0x0;
    *(ecx + 0x618) = 0x0;
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
