// sub_484cf0 @ 0x484cf0
// hopper name: sub_484cf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484cf0() {
    asm { fld        st0 };
    asm { frndint };
    asm { fsubr      st1, st0 };
    asm { fxch       st0, st1 };
    asm { fchs };
    asm { f2xm1 };
    asm { fld1 };
    asm { faddp      st1 };
    asm { fscale };
    asm { fstp       st1 };
    return;
}
