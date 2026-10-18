// sub_47a828 @ 0x47a828
// hopper name: sub_47a828
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a828() {
    ebp = &var_2AC;
    arg_2a0 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x32c;
    asm { pushfd };
    sub_47ba40(&decomp_var_80, 0x0, 0x50);
    decomp_var_30 = &decomp_var_80;
    esi = IsDebuggerPresent();
    SetUnhandledExceptionFilter(0x0);
    esp = (esp + 0x4 - 0xc) + 0xc - 0x8;
    eax = UnhandledExceptionFilter(&decomp_var_30);
    if (eax == 0x0 && esi == 0x0) {
            sub_47fe08();
            esp = (esp - 0x4) + 0x4;
    }
    TerminateProcess(GetCurrentProcess(), decomp_var_328);
    eax = sub_47ad69();
    return eax;
}
