// sub_47d87a @ 0x47d87a
// hopper name: sub_47d87a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d87a() {
    esp = esp - 0x4;
    eax = GetModuleHandleA("mscoree.dll");
    if (eax != 0x0) {
            esp = esp - 0x8;
            eax = GetProcAddress(eax, "CorExitProcess");
            if (eax != 0x0) {
                    (eax)(saved_fp);
            }
    }
    return;
}
