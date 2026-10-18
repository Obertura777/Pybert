// sub_4106d0 @ 0x4106d0
// hopper name: sub_4106d0
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4106d0() {
    eax = sub_47020b();
    if (eax == 0x0) {
            sub_40b5a0(0x80004005);
    }
    else {
            ecx = eax;
            esp = esp - 0x8;
            esi = (*(*eax + 0xc))(esi, ebx);
            eax = sign_extend_32(arg_8) - 0x44;
            esi = esi + 0x10;
            if (eax <= 0x30) {
                    (*((eax[0x4107e8] & 0xff) * 0x4 + 0x4107d4))();
            }
            else {
                    eax = esi - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
            }
    }
    return;
}
