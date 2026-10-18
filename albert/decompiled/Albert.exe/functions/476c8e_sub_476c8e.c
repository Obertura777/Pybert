// sub_476c8e @ 0x476c8e
// hopper name: sub_476c8e
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476c8e() {
    esi = ecx;
    eax = esi[0x1];
    esp = esp - 0x4;
    decomp_var_8 = edi;
    if (eax != esi[0x2]) {
            esp = esp - 0x10;
            SetViewportExtEx(eax, arg_4, arg_8, arg_0);
    }
    esi = esi[0x2];
    if (esi != 0x0) {
            esp = esp - 0x10;
            SetViewportExtEx(esi, arg_4, arg_8, arg_0);
    }
    eax = arg_0;
    return eax;
}
