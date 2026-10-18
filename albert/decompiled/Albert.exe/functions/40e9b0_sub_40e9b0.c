// sub_40e9b0 @ 0x40e9b0
// hopper name: sub_40e9b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e9b0() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    ebp = arg_0;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = ecx;
    if (edi[0x5] < ebp) {
            sub_492fd5();
    }
    eax = edi[0x5];
    esi = arg_4;
    eax = eax - ebp;
    if (eax < esi) {
            esi = eax;
    }
    ebx = arg_c;
    eax = esi;
    if (esi >= ebx) {
            eax = ebx;
    }
    if (edi[0x6] >= 0x10) {
            edi = edi[0x1];
    }
    else {
            edi = edi + 0x4;
    }
    eax = sub_40cd30(edi + ebp, arg_8, eax);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0 || esi < ebx) goto .l1;

.l1:
    return;
}
