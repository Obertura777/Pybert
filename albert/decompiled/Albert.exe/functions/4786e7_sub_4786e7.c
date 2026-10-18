// sub_4786e7 @ 0x4786e7
// hopper name: sub_4786e7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4786e7() {
    decomp_var_4 = esi;
    esi = ecx;
    bool_0 = (esi[0x18] & 0x1) == 0x0;
    eax = esi[0xa];
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (!bool_0) {
            edx = esi[0xb];
            if (edx != eax) {
                    esp = esp - 0xc;
                    (*(*esi[0x9] + 0x28))(eax - edx, eax - edx & 0x80000000 ? 0xffffffff : 0x0, 0x1);
            }
            eax = esi[0xb];
    }
    else {
            esp = esp - 0x4;
            decomp_var_c = ebx;
            bool_2 = esi[0x2] != 0x0;
            edi = esi + 0x30;
            edx = *edi;
            if (!bool_2) {
                    if (eax != edx) {
                            esp = esp - 0x8;
                            (*(*esi[0x9] + 0x38))(edx, eax - edx);
                    }
            }
            else {
                    if (eax != edx) {
                            (arg_4c)(0x2, eax - edx, 0x0, 0x0, ebp);
                            esp = (esp - 0x14) + 0x4;
                    }
                    decomp_var_c = esi + 0x2c;
                    esp = esp - 0x10;
                    (*(*esi[0x9] + 0x50))(0x1, esi[0x8], edi, decomp_var_c);
            }
            eax = *edi;
            esp = esp + 0x4;
    }
    esi[0xa] = eax;
    return eax;
}
