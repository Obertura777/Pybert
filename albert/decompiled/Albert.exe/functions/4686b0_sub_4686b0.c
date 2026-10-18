// sub_4686b0 @ 0x4686b0
// hopper name: sub_4686b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4686b0() {
    eax = arg_4;
    edx = arg_c;
    *(int8_t *)eax = 0x25;
    ecx = eax + 0x1;
    if ((edx & 0x20) != 0x0) {
            *(int8_t *)ecx = 0x2b;
            ecx = ecx + 0x1;
    }
    if ((edx & 0x8) != 0x0) {
            *(int8_t *)ecx = 0x23;
            ecx = ecx + 0x1;
    }
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_8;
    ebx = *(int8_t *)edi;
    if (ebx != 0x4c) {
            *(int8_t *)ecx = ebx;
    }
    else {
            *(int8_t *)ecx = 0x49;
            ecx[0x1] = 0x36;
            ecx = ecx + 0x2;
            *(int8_t *)ecx = 0x34;
    }
    esi = edx & 0xe00;
    ecx = ecx + 0x1;
    if (esi == 0x400) {
            *(int8_t *)ecx = 0x6f;
            ecx[0x1] = 0x0;
    }
    else {
            if (esi != 0x800) {
                    *(int8_t *)ecx = edi[0x1];
                    ecx[0x1] = 0x0;
            }
            else {
                    *(int8_t *)ecx = !(edx + edx + edx + edx + edx + edx + edx + edx) & 0x20 | 0x58;
                    ecx[0x1] = 0x0;
            }
    }
    return eax;
}
