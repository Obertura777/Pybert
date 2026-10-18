// sub_4ac27a @ 0x4ac27a
// hopper name: sub_4ac27a
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_e41e03f52e8d11a579d3f07a670615b5498a477b1a79ea69d8a397696ef7f69f
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4ac27a() {
    DeleteCriticalSection(saved_fp);
    ecx = ecx + 0x30;
    esi = saved_fp;
    esp = (esp - 0x8) + 0x4;
    esp = esp - 0x4;
    esi = ecx;
    eax = *esi;
    if (eax != 0x0) {
            sub_47c8f9();
            *esi = *esi & 0x0;
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x1] = esi[0x1] & 0x0;
    esi[0x2] = esi[0x2] & 0x0;
    return;
}
