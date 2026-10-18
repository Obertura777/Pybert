// sub_47435e @ 0x47435e
// hopper name: sub_47435e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47435e() {
    if (ecx != 0x0) {
            eax = ecx[0x8];
            if (eax == 0x0) {
                    eax = 0x0;
            }
            else {
                    decomp_var_4 = esi;
                    decomp_var_8 = edi;
                    esp = esp - 0xc;
                    decomp_var_c = eax;
                    while (true) {
                            eax = GetParent(decomp_var_c, decomp_var_8, decomp_var_4);
                            esp = esp - 0x4;
                            eax = sub_473aee(eax);
                            esi = eax;
                            if (esi == 0x0) {
                                    break;
                            }
                            if ((*(*esi + 0x120))() == 0x0) {
                                    esp = esp - 0x4;
                                    continue;
                            }
                            eax = esi;
                            break;
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
