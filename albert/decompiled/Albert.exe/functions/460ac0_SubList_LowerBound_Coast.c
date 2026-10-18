// SubList_LowerBound_Coast @ 0x460ac0
// hopper name: sub_460ac0
// pybert name: SubList_LowerBound_Coast
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

SubList_LowerBound_Coast() {
    decomp_var_14 = ebx;
    ebx = arg_4;
    esp = esp - 0x20;
    esi = ecx;
    edi = sub_40fab0(ebx);
    var_C = edi;
    if (esi == 0x0) {
            sub_47a948();
    }
    edx = esi[0x1];
    var_10 = esi;
    if (edi != edx) {
            eax = *ebx;
            ecx = edi[0x3];
            bool_2 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_2 && ebx[0x2] < edi[0x8]) {
                            var_8 = esi;
                            ecx = &var_8;
                    }
                    else {
                            ecx = &var_10;
                    }
            }
            else {
                    var_8 = esi;
                    ecx = &var_8;
            }
    }
    else {
            var_8 = esi;
            ecx = &var_8;
    }
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
