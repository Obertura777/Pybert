// sub_4700ea @ 0x4700ea
// hopper name: sub_4700ea
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4700ea() {
    eax = sub_4715ba();
    eax = eax[0x1];
    if (eax != 0x0) {
            eax = (*(*eax + 0x98))();
    }
    else {
            eax = sub_46ff8f();
    }
    return eax;
}
