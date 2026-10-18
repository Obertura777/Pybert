// sub_477476 @ 0x477476
// hopper name: sub_477476
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477476() {
    ecx[0x2] = GetSystemMetrics(saved_fp);
    ecx[0x3] = GetSystemMetrics(saved_fp);
    *dword_bc61e8 = GetSystemMetrics(saved_fp) + 0x1;
    *dword_bc61ec = GetSystemMetrics(saved_fp) + 0x1;
    GetDC(saved_fp);
    ecx[0x6] = GetDeviceCaps(saved_fp, arg_0);
    ecx[0x7] = GetDeviceCaps(saved_fp, arg_0);
    ReleaseDC(saved_fp, arg_0);
    return;
}
