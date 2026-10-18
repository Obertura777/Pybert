// sub_47b592 @ 0x47b592
// hopper name: sub_47b592
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b592() {
    asm { fld        st0 };
    asm { frndint };
    asm { fcomp      st1 };
    asm { wait };
    asm { fnstsw     ax };
    asm { sahf };
    if (!asm { sahf }) {
            ecx = 0x0;
            asm { fmul       qword [qword_4c8dd0] };
            ecx = ecx + 0x1;
            asm { fld        st0 };
            asm { frndint };
            asm { fcompp };
            asm { wait };
            asm { fnstsw     ax };
            asm { sahf };
    }
    else {
            asm { fstp       st0 };
    }
    return eax;
}
