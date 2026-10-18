// sub_47550c @ 0x47550c
// hopper name: sub_47550c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47550c() {
    esp = esp - 0x8;
    decomp_var_8 = 0x46def6;
    esi = sub_477aab();
    if (esi == 0x0) {
            sub_46dedc();
    }
    esp = esp - 0x4;
    decomp_var_c = edi;
    edi = saved_fp;
    if (esi[0x5] != edi) {
            if (esi[0xa] == 0x0) {
                    eax = GetCurrentThreadId();
                    esp = esp - 0x10;
                    eax = SetWindowsHookExA(0x5, 0x4752b9, 0x0, eax);
                    esi[0xa] = eax;
                    if (eax == 0x0) {
                            sub_46dea8();
                    }
                    esi[0x5] = edi;
            }
            else {
                    esi[0x5] = edi;
            }
    }
    return;
}
