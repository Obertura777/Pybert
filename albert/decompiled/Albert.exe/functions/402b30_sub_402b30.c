// sub_402b30 @ 0x402b30
// hopper name: sub_402b30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402b30() {
    edx = arg_0;
    esi = ecx;
    eax = edx;
    esp = esp - 0x8;
    esi[0x6] = 0xf;
    esi[0x5] = 0x0;
    esi[0x4] = 0x0;
    edi = eax + 0x1;
    do {
            ecx = *(int8_t *)eax;
            eax = eax + 0x1;
    } while (ecx != 0x0);
    sub_402650(edx, eax - edi);
    eax = esi;
    return eax;
}
