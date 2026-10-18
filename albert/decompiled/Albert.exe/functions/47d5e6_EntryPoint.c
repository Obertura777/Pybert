// EntryPoint @ 0x47d5e6
// hopper name: EntryPoint
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

EntryPoint() {
    sub_489243();
    decomp_var_8 = 0x4c34e8;
    sub_47f31c(0x4c34e8, 0x60);
    GetStartupInfoA(&decomp_var_70);
    decomp_var_c = 0x94;
    esp = esp - 0x18;
    esi = HeapAlloc(GetProcessHeap(), decomp_var_8, 0xfffffffe);
    if (esi == 0x0) {
            sub_47d3a1(0x12);
    }
    else {
            *esi = 0x94;
            decomp_var_c = esi;
            esp = esp - 0xc;
            decomp_var_10 = 0x0;
            if (GetVersionExA(esi) == 0x0) {
                    HeapFree(GetProcessHeap(decomp_var_10, decomp_var_c), decomp_var_10, decomp_var_c);
            }
            else {
                    decomp_var_24 = esi[0x1];
                    decomp_var_28 = esi[0x2];
                    edi = esi[0x3];
                    edi = edi & 0x7fff;
                    esp = esp - 0x4;
                    HeapFree(GetProcessHeap(decomp_var_10, decomp_var_c), decomp_var_10, decomp_var_c);
                    esi = decomp_var_20;
                    if (esi != 0x2) {
                            edi = edi | 0x8000;
                    }
                    *dword_bc64bc = esi;
                    *dword_bc64c4 = (decomp_var_24 << 0x8) + decomp_var_28;
                    *dword_bc64c8 = decomp_var_24;
                    *dword_bc64cc = decomp_var_28;
                    *dword_bc64c0 = edi;
                    decomp_var_20 = sub_47d3c5();
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48888b(0x1) == 0x0) {
                            sub_47d3a1(0x1c);
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (sub_4801bf() == 0x0) {
                            sub_47d3a1(0x10);
                            esp = (esp - 0x4) + 0x4;
                    }
                    sub_4891fb();
                    decomp_var_4 = 0x1;
                    if (sub_486a47() < 0x0) {
                            sub_47d856(0x1b);
                            esp = (esp - 0x4) + 0x4;
                    }
                    *dword_bc8384 = GetCommandLineA();
                    *dword_bc64ac = sub_4890c6();
                    if (sub_48900d() < 0x0) {
                            sub_47d856(0x8);
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (sub_488d9a() < 0x0) {
                            sub_47d856(0x9);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = sub_47d972(0x1);
                    esp = (esp - 0x4) + 0x4;
                    bool_4 = eax == 0x0;
                    if (eax != 0x0) {
                            sub_47d856(eax);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = sub_488d3d();
                    if (!bool_4) {
                            ecx = decomp_var_40 & 0xffff;
                    }
                    else {
                            ecx = 0xa;
                            esp = (esp - 0x4) + 0x4;
                    }
                    esp = esp - 0x10;
                    eax = sub_493d7e(word_400000, 0x0, eax, ecx, decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4);
                    decomp_var_1c = eax;
                    if (decomp_var_20 == 0x0) {
                            sub_47dad2(eax);
                    }
                    sub_47daf4();
            }
    }
    eax = sub_47f361();
    return eax;
}
