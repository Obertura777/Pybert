// sub_471fc1 @ 0x471fc1
// hopper name: sub_471fc1
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471fc1() {
    ebx = ecx;
    esp = esp - 0xc;
    eax = sub_477ebe(ebx[0x8], arg_0, arg_4);
    edi = eax;
    if (edi != 0x0) {
            esp = esp - 0x8;
            esi = arg_8;
            arg_4 = GetDlgCtrlID(edi) & 0xffff;
            if (esi != 0x0 && *esi >= 0x28) {
                    eax = ebx[0x8];
                    esi[0x1] = esi[0x1] | 0x1;
                    esi[0x9] = esi[0x9] | 0xffffffff;
                    esp = esp - 0x10;
                    esi[0x2] = eax;
                    esi[0x3] = edi;
                    if ((SendMessageA(edi, 0x87, 0x0, 0x0) & 0x2000) == 0x0) {
                            esi[0x1] = esi[0x1] | 0x80000002;
                    }
            }
            eax = arg_4;
            esp = esp + 0x4;
    }
    else {
            eax = eax | 0xffffffff;
    }
    return eax;
}
