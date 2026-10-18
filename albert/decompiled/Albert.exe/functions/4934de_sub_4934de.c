// sub_4934de @ 0x4934de
// hopper name: sub_4934de
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4934de() {
    eax = sub_482823();
    esp = (esp - 0x8) + 0x8;
    if (eax == 0x0) {
            eax = 0x4b1973;
    }
    esi = arg_0;
    esp = esp - 0x8;
    sub_402900(eax);
    if (arg_0 != 0x0) {
            decomp_var_c = arg_0;
            eax = sub_482823();
            esp = (esp - 0x8) + 0x8;
            if (eax == 0x0) {
                    eax = 0x4b812c;
            }
    }
    else {
            eax = 0x4b812c;
    }
    sub_402900(eax);
    return;
}
