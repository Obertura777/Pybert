// sub_465c70 @ 0x465c70
// hopper name: sub_465c70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465c70() {
    decomp_var_4 = esi;
    esi = ecx;
    eax = esi[0x3];
    decomp_var_8 = edi;
    edi = 0x0;
    esi[0x2] = sub_46dbce(-(OVERFLOW((eax + 0x1) * 0x4) ? 0x1 : 0x0) | (eax + 0x1) * 0x4);
    eax = 0x0;
    esp = (esp - 0xc) + 0x4;
    if (esi[0x1] > 0x0) {
            edx = 0x0;
            do {
                    if (edi == 0x0) {
                            *(edx + esi[0x2]) = eax;
                            edx = edx + 0x4;
                    }
                    ecx = *esi;
                    ecx = *(int16_t *)(ecx + eax * 0x2) & 0xffff;
                    if (*(int16_t *)word_4c79b4 == ecx) {
                            edi = edi + 0x1;
                    }
                    if (*(int16_t *)word_4c79b8 == ecx) {
                            edi = edi - 0x1;
                    }
                    eax = eax + 0x1;
            } while (eax < esi[0x1]);
    }
    edx = esi[0x3];
    eax = esi[0x2];
    *(eax + edx * 0x4) = esi[0x1];
    return eax;
}
