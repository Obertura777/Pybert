// sub_4773bf @ 0x4773bf
// hopper name: sub_4773bf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4773bf() {
    if (ecx[0x2] != 0x0) {
            (*(*ecx[0x2] + 0x8))();
    }
    else {
            esp = esp - 0x4;
            sub_47d6bb(saved_fp);
            esi = ecx;
            eax = esi + 0x4;
            if (*eax != 0x0) {
                    esp = esp - 0x4;
                    ebx = InterlockedDecrement();
                    if (ebx == 0x0) {
                            esp = esp - 0x4;
                            sub_471606(saved_fp);
                            (*(*esi + 0x10))();
                            if (decomp_var_10 != ebx) {
                                    sub_470ddd();
                            }
                    }
            }
            sub_47d75a();
    }
    return;
}
