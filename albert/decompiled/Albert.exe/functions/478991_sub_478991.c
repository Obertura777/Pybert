// sub_478991 @ 0x478991
// hopper name: sub_478991
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478991() {
    var_4 = *dword_4c8db8 ^ ebp;
    esi = arg_4;
    esp = esp - 0x8;
    decomp_var_50 = edi;
    edi = arg_0;
    if (esi != 0x0) {
            sub_4788be();
            *esi = var_48 & 0xffff;
            esp = esp - 0x8;
            decomp_var_54 = &var_48;
            sub_4788be();
            if (var_48 < 0x40) {
                    esi = var_48 & 0xffff;
                    decomp_var_54 = esi;
                    esp = esp - 0x8;
                    eax = sub_4785b8(&var_44, decomp_var_54);
                    if (eax == esi) {
                            esp = esp - 0x4;
                            *(int8_t *)(ebp + (esi - 0x44)) = 0x0;
                            sub_478943();
                    }
            }
    }
    eax = sub_47ad69();
    return eax;
}
