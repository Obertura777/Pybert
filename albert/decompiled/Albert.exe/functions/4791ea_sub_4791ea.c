// sub_4791ea @ 0x4791ea
// hopper name: sub_4791ea
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4791ea() {
    if (ecx == 0x0) {
            sub_46dedc();
    }
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx[0x1];
    if (esi != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            edi = arg_0;
            for (edx = *(esi + (edi >> 0x4) % ecx[0x2] * 0x4); edx != 0x0; edx = *edx) {
                    if (edx[0x1] == edi) {
                            break;
                    }
            }
            esp = esp + 0x4;
    }
    return;
}
