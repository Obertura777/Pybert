// sub_470741 @ 0x470741
// hopper name: sub_470741
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470741() {
    edi = ecx;
    bool_0 = edi[0x16] == 0x0;
    eax = edi[0x17];
    esi = edi[0x18];
    var_4 = eax;
    if (!bool_0) {
            ebx = *(sub_4715ba() + 0xc);
            esp = esp - 0x14;
            var_4 = LoadResource(ebx, FindResourceA(ebx, edi[0x16], 0x5));
    }
    if (var_4 != 0x0) {
            esp = esp - 0x4;
            esi = LockResource(var_4);
    }
    ebx = 0x1;
    if (esi != 0x0) {
            bool_1 = esi[0x1] != 0xffff;
            edx = *esi;
            if (!bool_1) {
                    edx = esi[0x3];
                    eax = esi[0x9] & 0xffff;
                    ecx = esi[0xa] & 0xffff;
            }
            else {
                    eax = esi[0x5] & 0xffff;
                    ecx = esi[0x6] & 0xffff;
            }
            if ((edx & 0x1801) == 0x0) {
                    if (eax == 0x0) {
                            if (ecx != 0x0) {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    if (edi[0x16] != 0x0) {
            esp = esp - 0x4;
            FreeResource(var_4);
    }
    eax = ebx;
    return eax;
}
