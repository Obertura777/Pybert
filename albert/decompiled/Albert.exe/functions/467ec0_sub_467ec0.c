// sub_467ec0 @ 0x467ec0
// hopper name: sub_467ec0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467ec0() {
    var_4 = ecx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = ecx;
    decomp_var_10 = edi;
    esi[0x9] = 0x0;
    esi[0x3] = 0x0;
    esi[0x4] = 0x201;
    esi[0x5] = 0x6;
    esi[0x6] = 0x0;
    esi[0x7] = 0x0;
    esi[0x8] = 0x0;
    sub_467d70(0x0, 0x0);
    edi = sub_46dbce(0x4);
    esp = (esp - 0x1c) + 0x4;
    if (edi != 0x0) {
            decomp_var_14 = ebx;
            *edi = sub_493444();
            esp = esp - 0x8;
            ebx = sub_493278();
            sub_4931ea(0x0);
            eax = ebx[0x1];
            if (eax < 0xffffffff) {
                    ebx[0x1] = eax + 0x1;
            }
            sub_49320b();
            esi[0x9] = edi;
    }
    else {
            esi[0x9] = 0x0;
    }
    return;
}
