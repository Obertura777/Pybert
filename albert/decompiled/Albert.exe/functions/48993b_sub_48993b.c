// sub_48993b @ 0x48993b
// hopper name: sub_48993b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48993b() {
    eax = *esi;
    if (arg_0 == eax) {
            ecx = *edi;
            esp = esp - 0x8;
            if (ecx == arg_4) {
                    eax = sub_4812c0(saved_fp, arg_0);
                    esp = esp + 0x8;
                    *edi = eax;
                    if (eax == 0x0) {
                            *arg_8 = 0x1;
                            sub_47c000(saved_fp, arg_0, arg_4);
                            loc_489989();
                    }
                    else {
                            (null)();
                    }
            }
            else {
                    sub_481353();
            }
    }
    else {
            (null)();
    }
    return;
}
