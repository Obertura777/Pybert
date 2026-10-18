// sub_484d35 @ 0x484d35
// hopper name: sub_484d35
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484d35() {
    eax = edx[0x1];
    eax = eax & 0x7ff00000;
    if (eax != 0x7ff00000) {
            asm { fld        qword [edx] };
    }
    else {
            eax = edx[0x1];
            ecx = *edx;
            asm { shld       eax, ecx, 0xb };
            asm { fld        tword [esp+0xa+var_A] };
            eax = edx[0x1];
    }
    return eax;
}
