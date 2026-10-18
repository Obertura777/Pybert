// sub_483d0a @ 0x483d0a
// hopper name: sub_483d0a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483d0a() {
    esp = esp - 0x4;
    eax = GetModuleHandleA("KERNEL32");
    if (eax != 0x0) {
            esp = esp - 0x8;
            eax = GetProcAddress(eax, 0x4b3b78);
            if (eax != 0x0) {
                    (eax)(0x0);
            }
            else {
                    sub_483cce();
            }
    }
    else {
            sub_483cce();
    }
    return;
}
