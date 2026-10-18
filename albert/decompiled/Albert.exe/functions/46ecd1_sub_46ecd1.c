// sub_46ecd1 @ 0x46ecd1
// hopper name: sub_46ecd1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ecd1() {
    eax = sub_47dc9a(arg_0, arg_4, 0x10);
    eax = (--eax - --eax + CARRY(EFLAGS(cf))) + 0x1;
    return eax;
}
