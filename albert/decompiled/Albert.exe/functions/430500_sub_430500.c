// sub_430500 @ 0x430500
// hopper name: sub_430500
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_430500() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    ebx = ecx;
    esi = edi;
    if (edi[0xe9] == 0x0) {
            do {
                    sub_430500(esi[0x2]);
                    esi = *esi;
                    sub_41cc50();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0xe9] == 0x0);
    }
    return;
}
