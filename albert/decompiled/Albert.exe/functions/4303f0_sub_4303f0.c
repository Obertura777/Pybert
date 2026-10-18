// sub_4303f0 @ 0x4303f0
// hopper name: sub_4303f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4303f0() {
    var_C = *0x0;
    decomp_var_10 = ebx;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    eax = &var_C;
    *0x0 = eax;
    ebx = ecx;
    edi = arg_0;
    esi = edi;
    if (edi[0x61] == 0x0) {
            do {
                    sub_4303f0(esi[0x2]);
                    esi = *esi;
                    sub_421400();
                    sub_465fa0();
                    eax = sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x61] == 0x0);
    }
    *0x0 = var_C;
    return eax;
}
