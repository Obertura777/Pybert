// sub_49354a @ 0x49354a
// hopper name: sub_49354a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49354a() {
    decomp_var_4 = esi;
    esi = arg_0;
    decomp_var_8 = edi;
    esp = esp - 0xc;
    sub_493528(0x0, decomp_var_8);
    eax = esi[0x7];
    if (eax != 0x0) {
            do {
                    edi = *eax;
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    eax = edi;
            } while (edi != 0x0);
    }
    eax = esi[0x8];
    esi[0x7] = esi[0x7] & 0x0;
    if (eax != 0x0) {
            edi = *eax;
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            eax = edi;
            if (edi != 0x0) {
                    continue;
            }
            break;
    }
    esi[0x8] = esi[0x8] & 0x0;
    return eax;
}
