// sub_47ff4f @ 0x47ff4f
// hopper name: sub_47ff4f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ff4f() {
    decomp_var_4 = 0xc;
    sub_47f31c(0x4c3590, 0xc);
    esp = esp - 0xc;
    eax = GetModuleHandleA("KERNEL32.DLL");
    decomp_var_1c = eax;
    esi = arg_4;
    esi[0x17] = 0x4c9b60;
    esi[0x5] = 0x1;
    if (eax != 0x0) {
            esi[0x7e] = GetProcAddress(eax, "EncodePointer");
            esp = esp - 0x10;
            esi[0x7f] = GetProcAddress(decomp_var_1c, "DecodePointer");
    }
    esi[0x1c] = 0x1;
    esi[0xc8] = 0x43;
    esi[0x14b] = 0x43;
    esi[0x1a] = 0x4c8ff0;
    InterlockedIncrement(0x4c8ff0);
    sub_487c06(0xc);
    esp = (esp - 0x8) + 0x4;
    esi[0x1b] = arg_8;
    if (arg_8 == 0x0) {
            esi[0x1b] = *dword_4c95f8;
    }
    sub_481b72(esi[0x1b]);
    sub_47fffa();
    eax = sub_47f361();
    return eax;
}
