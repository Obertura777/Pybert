// sub_4706e0 @ 0x4706e0
// hopper name: sub_4706e0
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4706e0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = esi[0x19];
    if (eax != 0x0) {
            esp = esp - 0x4;
            eax = sub_4761e0(eax);
    }
    else {
            esp = esp - 0x4;
            eax = sub_476629(esi[0x16]);
    }
    if (eax == 0x0) {
            sub_4703ba(0xffffffff);
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            if (sub_473437() != 0x0) {
                    esp = esp - 0x4;
                    esi = sub_4766cb(0xe146);
                    if (esi != 0x0) {
                            eax = sub_47068a();
                            esp = esp - 0x4;
                            sub_476779(--eax - --eax + CARRY(EFLAGS(cf)) & 0x5);
                    }
                    eax = 0x1;
            }
            else {
                    sub_4703ba(0xffffffff);
                    eax = 0x0;
            }
    }
    return eax;
}
