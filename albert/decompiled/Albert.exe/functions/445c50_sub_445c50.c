// sub_445c50 @ 0x445c50
// hopper name: sub_445c50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_445c50() {

sub_445c50:
    if (ebp == 0x0 || ebp != 0xbc1e1c) {
            sub_47a948();
    }
    if (ebx == *dword_bc1e20) goto loc_44606f;
    goto loc_445c6f;

loc_44606f:
    if (edi != 0xffffffff) {
            asm { fld        dword [esp+20] };
            asm { fstp       dword [dword_4ca540+484264+edi*4] };
            asm { fld        dword [esp+24] };
            asm { fstp       dword [dword_4ca540+483240+edi*4] };
    }
    &arg_c = arg_4;
    return;

loc_445c6f:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (ebx == arg_0) {
            sub_47a948();
    }
    if (ebx[0x3] != edi) {
            if (edi != 0xffffffff) {
                    asm { fld        dword [esp+20] };
                    asm { fstp       dword [dword_4ca540+484264+edi*4] };
                    asm { fld        dword [esp+24] };
                    asm { fstp       dword [dword_4ca540+483240+edi*4] };
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            asm { fldz };
            edi = ebx[0x3];
            asm { fst        dword [esp+20] };
            arg_24 = edi;
            asm { fstp       dword [esp+24] };
    }
    edx = arg_18[0x2];
    eax = edx + (edi + edi * 0x8) * 0x4;
    if (*(int8_t *)(edx + (edi + edi * 0x8) * 0x4 + 0x3) != 0x0) {
            eax = eax[0x10];
            if (ebx == arg_0) {
                    sub_47a948();
            }
            sub_445d10(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, ebx + 0x14, eax, arg_34, arg_38, arg_3c, arg_40, arg_44);
    }
    sub_40f6f0();
    ebx = arg_38;
    ebp = arg_34;
    edi = arg_24;
    goto sub_445c50;
}
