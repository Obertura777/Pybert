// sub_40e890 @ 0x40e890
// hopper name: sub_40e890
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e890() {
    ecx = arg_8;
    asm { fld        qword [esp+arg_0] };
    eax = ecx;
    if (ecx < 0x0) {
            eax = -eax;
    }
    asm { fld1 };
    asm { fld        st0 };
    while (true) {
            if ((eax & 0x1) != 0x0) {
                    asm { fmul       st2 };
            }
            eax = eax >> 0x1;
            bool_1 = eax >= 0x0;
            if (eax == 0x0) {
                    break;
            }
            asm { fld        st2 };
            asm { fmulp      st3 };
    }
    asm { fstp       st2 };
    if (!bool_1) {
            asm { fdivrp     st1 };
    }
    else {
            asm { fstp       st0 };
    }
    return eax;
}
