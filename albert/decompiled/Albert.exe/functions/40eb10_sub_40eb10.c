// sub_40eb10 @ 0x40eb10
// hopper name: sub_40eb10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40eb10() {
    edx = arg_0;
    eax = *edx;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    *edx = eax[0x2];
    esi = eax[0x2];
    if (esi[0x21] == 0x0) {
            esi[0x1] = edx;
    }
    eax[0x1] = edx[0x1];
    ecx = ecx[0x1];
    if (edx == ecx[0x1]) {
            ecx[0x1] = eax;
            eax[0x2] = edx;
            edx[0x1] = eax;
    }
    else {
            ecx = edx[0x1];
            if (edx == ecx[0x2]) {
                    ecx[0x2] = eax;
                    eax[0x2] = edx;
                    edx[0x1] = eax;
            }
            else {
                    *ecx = eax;
                    eax[0x2] = edx;
                    edx[0x1] = eax;
            }
    }
    return eax;
}
