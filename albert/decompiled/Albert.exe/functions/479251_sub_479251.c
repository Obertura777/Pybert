// sub_479251 @ 0x479251
// hopper name: sub_479251
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479251() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx[0x1];
    if (esi == 0x0) {
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            edi = arg_0;
            edx = esi + (edi >> 0x4) % ecx[0x2] * 0x4;
            eax = *edx;
            while (eax != 0x0) {
                    if (eax[0x1] != edi) {
                            edx = eax;
                            eax = *eax;
                            continue;
                    }
                    esp = esp - 0x4;
                    *edx = *eax;
                    sub_479199(eax);
                    eax = 0x1;
                    break;
            }
            esp = esp + 0x4;
    }
    return eax;
}
