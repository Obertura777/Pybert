// sub_4774d0 @ 0x4774d0
// hopper name: sub_4774d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4774d0() {
    ecx[0x15] = GetVersion() >> 0x1f;
    sub_477476();
    ecx[0x9] = 0x0;
    sub_477432();
    ecx[0xf] = LoadCursorA(saved_fp, arg_0);
    ecx[0x10] = LoadCursorA(saved_fp, arg_0);
    ecx[0x4] = saved_fp;
    ecx[0x5] = saved_fp;
    ecx[0x14] = 0x0;
    ecx[0x11] = 0x0;
    return;
}
