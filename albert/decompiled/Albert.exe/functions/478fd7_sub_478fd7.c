// sub_478fd7 @ 0x478fd7
// hopper name: sub_478fd7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478fd7() {
    var_4 = *dword_4c8db8 ^ ebp;
    edi = 0xa;
    esp = (esp - 0x10) + 0x4 - 0x4;
    var_44 = ecx;
    ebx = "System";
    eax = GetStockObject(0x11);
    if (eax == 0x0) {
            esp = esp - 0x4;
            eax = GetStockObject(0xd, var_44);
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    eax = GetObjectA(eax, 0x3c, &var_40);
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            ebx = &var_24;
                            esi = GetDC(0x0);
                            if (var_40 < 0x0) {
                                    var_40 = -var_40;
                            }
                            esp = esp - 0x1c;
                            edi = MulDiv(var_40, 0x48, GetDeviceCaps(esi, 0x5a)) & 0xffff;
                            ReleaseDC(0x0, esi);
                    }
                    eax = arg_0;
                    if (eax == 0x0) {
                            eax = edi & 0xffff;
                    }
                    sub_478e88(ebx, eax);
                    eax = sub_47ad69();
            }
            else {
                    eax = arg_0;
                    if (eax == 0x0) {
                            eax = 0xa & 0xffff;
                    }
                    sub_478e88("System", eax);
                    eax = sub_47ad69();
            }
    }
    else {
            esp = esp - 0xc;
            eax = GetObjectA(eax, 0x3c, &var_40);
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    ebx = &var_24;
                    esi = GetDC(0x0);
                    if (var_40 < 0x0) {
                            var_40 = -var_40;
                    }
                    esp = esp - 0x1c;
                    edi = MulDiv(var_40, 0x48, GetDeviceCaps(esi, 0x5a)) & 0xffff;
                    ReleaseDC(0x0, esi);
            }
            eax = arg_0;
            if (eax == 0x0) {
                    eax = edi & 0xffff;
            }
            sub_478e88(ebx, eax);
            eax = sub_47ad69();
    }
    return eax;
}
