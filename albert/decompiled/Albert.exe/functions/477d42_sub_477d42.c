// sub_477d42 @ 0x477d42
// hopper name: sub_477d42
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477d42() {
    decomp_var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_10c = ebx;
    ebx = arg_4;
    decomp_var_110 = esi;
    esi = arg_8;
    esp = esp - 0xc;
    decomp_var_114 = edi;
    if (ebx == 0x0) {
            sub_46dedc();
    }
    if (esi == 0x0) {
            sub_46dedc();
    }
    edi = lstrlenA(esi);
    decomp_var_104 = 0x0;
    sub_47ba40(&decomp_var_103, 0x0, 0xff);
    esp = (esp - 0x10) + 0xc;
    if (edi <= 0x100) {
            esp = esp - 0xc;
            eax = GetWindowTextA(ebx, &decomp_var_104, 0x100);
            if (eax == edi) {
                    esp = esp - 0x8;
                    eax = lstrcmpA(&decomp_var_104, esi);
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            SetWindowTextA(ebx, esi);
                    }
            }
            else {
                    esp = esp - 0x8;
                    SetWindowTextA(ebx, esi);
            }
    }
    else {
            esp = esp - 0x8;
            SetWindowTextA(ebx, esi);
    }
    eax = sub_47ad69();
    return eax;
}
