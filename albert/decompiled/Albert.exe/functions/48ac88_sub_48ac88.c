// sub_48ac88 @ 0x48ac88
// hopper name: sub_48ac88
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48ac88() {
    ecx = eax[0x21] & 0xffff;
    var_4 = ecx;
    var_8 = eax[0x22] & 0xffff;
    if (esi == 0x0) {
            eax = eax | 0xffffffff;
    }
    else {
            edi = sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x58) + 0x50 - 0x4;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8() | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x4c) + 0x50 - 0x10;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x40) + 0x50 - 0x1c;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x34) + 0x50 - 0x28;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x28) + 0x50 - 0x34;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x1c) + 0x50 - 0x40;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = (esp - 0x10) + 0x50 - 0x4c;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            esp = ((esp - 0x4) + 0x50 - 0x50) + 0x50 - 0x4;
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            edi = edi | sub_4896f8();
            eax = sub_4896f8();
            eax = edi | eax;
            esi[0x2b] = var_8;
    }
    return eax;
}
