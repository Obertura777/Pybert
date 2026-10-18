// sub_422960 @ 0x422960
// hopper name: sub_422960
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_422960() {
    var_C = *0x0;
    decomp_var_20 = edi;
    *0x0 = &var_C;
    eax = sub_401e30();
    *(ecx + 0x10) = eax;
    eax[0x11] = 0x1;
    eax = *(ecx + 0x10);
    eax[0x1] = eax;
    eax = *(ecx + 0x10);
    *eax = eax;
    eax = *(ecx + 0x10);
    eax[0x2] = eax;
    *(ecx + 0x14) = 0x0;
    eax = sub_40fd90();
    *(ecx + 0x1c) = eax;
    eax[0x1d] = 0x1;
    eax = *(ecx + 0x1c);
    eax[0x1] = eax;
    eax = *(ecx + 0x1c);
    *eax = eax;
    eax = *(ecx + 0x1c);
    eax[0x2] = eax;
    *(ecx + 0x20) = 0x0;
    eax = sub_40fd90();
    *(ecx + 0x28) = eax;
    eax[0x1d] = 0x1;
    eax = *(ecx + 0x28);
    eax[0x1] = eax;
    eax = *(ecx + 0x28);
    *eax = eax;
    eax = *(ecx + 0x28);
    eax[0x2] = eax;
    *(ecx + 0x2c) = 0x0;
    sub_465870();
    sub_465870();
    ecx[0x5c] = 0x0;
    sub_465870();
    eax = ecx;
    *0x0 = var_C;
    return eax;
}
