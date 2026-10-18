// ComputeWinterBuilds @ 0x445be0
// hopper name: sub_445be0
// pybert name: ComputeWinterBuilds
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputeWinterBuilds() {
    &saved_fp = &saved_fp & 0xfffffff8;
    asm { fldz };
    edx = ecx;
    eax = 0x0;
    if (*(edx[0x2] + 0x2400) > 0x0) {
            do {
                    asm { fst        dword [dword_4ca540+484264+eax*4] };
                    eax = eax + 0x1;
                    asm { fst        dword [dword_4ca540+483236+eax*4] };
            } while (eax < *(edx[0x2] + 0x2400));
    }
    asm { fstp       st0 };
    eax = sub_445c50();
    return eax;
}
