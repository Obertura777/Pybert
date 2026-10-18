// sub_406440 @ 0x406440
// hopper name: sub_406440
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_406440() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = ecx[0x19];
    sub_405260(&var_14, ecx + 0x60, *eax, ecx + 0x60, eax);
    sub_47c8f9();
    *(ecx + 0x64) = 0x0;
    *(ecx + 0x68) = 0x0;
    eax = ecx[0xe];
    sub_403430(&var_14, ecx + 0x34, *eax, ecx + 0x34, eax);
    sub_47c8f9();
    *(ecx + 0x38) = 0x0;
    *(ecx + 0x3c) = 0x0;
    eax = sub_401900();
    *0x0 = var_C;
    return eax;
}
