// sub_477cbb @ 0x477cbb
// hopper name: sub_477cbb
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477cbb() {
    var_4 = *dword_4c8db8 ^ ebp;
    ebx = arg_4;
    esi = ecx;
    esp = esp - 0xc;
    edi = arg_0;
    if (esi[0x15] != 0x0) {
            esp = esp - 0x4;
            esi = sub_477c75(edi);
            if (esi != 0x0) {
                    eax = RegSetValueExA(esi, ebx, 0x0, 0x4, &arg_8, 0x4);
                    esp = esp - 0x1c;
                    RegCloseKey(esi);
            }
    }
    else {
            sub_47d366(&var_14, 0x10, 0x4b34e8, arg_8);
            esp = (esp - 0x10) + 0x10 - 0x10;
            eax = WritePrivateProfileStringA(edi, ebx, &var_14, esi[0x1a]);
    }
    eax = sub_47ad69();
    return eax;
}
