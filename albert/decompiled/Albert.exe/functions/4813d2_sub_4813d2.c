// sub_4813d2 @ 0x4813d2
// hopper name: sub_4813d2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4813d2() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    decomp_var_10 = edi;
    esi = eax;
    ebx = esi + 0x1c;
    esp = esp - 0x1c;
    sub_47ba40(ebx, 0x0, 0x101);
    esi[0x1] = 0x0;
    esi[0x2] = 0x0;
    esi[0x3] = 0x0;
    eax = 0x0;
    edi = esi + 0x10;
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    esp = esp + 0xc;
    eax = 0x4c8ff0 - esi;
    do {
            *(int8_t *)ebx = *(int8_t *)(eax + ebx);
            ebx = ebx + 0x1;
    } while (&decomp_var_1 != 0x0);
    ecx = esi + 0x11d;
    esi = 0x100;
    do {
            *(int8_t *)ecx = *(int8_t *)(ecx + eax);
            ecx = ecx + 0x1;
            esi = esi - 0x1;
    } while (esi != 0x0);
    return;
}
