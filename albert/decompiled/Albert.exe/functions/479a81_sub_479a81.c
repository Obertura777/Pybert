// sub_479a81 @ 0x479a81
// hopper name: sub_479a81
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479a81() {
    decomp_var_4 = esi;
    esp = esp - 0xc;
    SetErrorMode(SetErrorMode(0x0) | 0x8001);
    eax = sub_4715ba();
    esi = arg_0;
    eax[0x2] = esi;
    eax[0x3] = esi;
    sub_470e1d();
    eax = sub_4715ba();
    eax = eax[0x1];
    if (eax != 0x0) {
            eax[0x12] = arg_8;
            eax[0x13] = arg_c;
            eax[0x11] = esi;
            sub_479902();
    }
    esp = esp + 0x4;
    if (*(int8_t *)(sub_4715ba() + 0x14) == 0x0) {
            sub_46f8be();
    }
    esp = esp - 0x4;
    eax = GetModuleHandleA("user32.dll");
    if (eax != 0x0) {
            *dword_bc5f44 = GetProcAddress(eax, "NotifyWinEvent");
    }
    return 0x1;
}
