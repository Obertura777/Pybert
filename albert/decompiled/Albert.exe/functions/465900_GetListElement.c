// GetListElement @ 0x465900
// hopper name: sub_465900
// pybert name: GetListElement
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

GetListElement() {
    edx = arg_4;
    bool_0 = edx >= ecx[0x1];
    eax = arg_0;
    *(int16_t *)eax = 0x0;
    if (!bool_0 && edx >= 0x0) {
            *(int16_t *)eax = *(int16_t *)(*ecx + edx * 0x2);
    }
    else {
            *(int16_t *)eax = *(int16_t *)word_4c7d14;
    }
    return eax;
}
