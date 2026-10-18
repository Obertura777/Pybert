// sub_47bf20 @ 0x47bf20
// hopper name: sub_47bf20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bf20() {
    esp = esp - 0x4;
    decomp_var_4 = ecx;
    ecx = &saved_fp - eax & !(eax - eax + CARRY(EFLAGS(cf)));
    for (eax = &decomp_var_4 & 0xfffff000; ecx < eax; eax = eax - 0x1000) {
    }
    &saved_fp = intrinsic_xchg(&saved_fp, ecx);
    eax = *eax;
    return eax;
}
