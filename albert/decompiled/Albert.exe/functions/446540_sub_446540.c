// sub_446540 @ 0x446540
// hopper name: sub_446540
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_446540() {
    eax = arg_0;
    esp = esp - 0x4;
    ebx = ecx;
    *ebx = *eax;
    ebx[0x1] = eax[0x1];
    ebx[0x2] = eax[0x2];
    ebx[0x3] = eax[0x3];
    ebx[0x4] = eax[0x4];
    asm { fld        dword [eax+0x14] };
    asm { fstp       dword [ebx+0x14] };
    ebx[0x6] = eax[0x6];
    ebx[0x7] = eax[0x7];
    ebx[0x8] = eax[0x8];
    ebx[0x9] = eax[0x9];
    ebx[0xa] = eax[0xa];
    ebx[0xb] = eax[0xb];
    ebx[0xc] = eax[0xc];
    ebx[0x34] = eax[0x34];
    esp = esp - 0x4;
    ebx[0x35] = eax[0x35];
    ebx[0xe] = eax[0xe];
    asm { fld        dword [eax+0x3c] };
    asm { fstp       dword [ebx+0x3c] };
    ebx[0x10] = eax[0x10];
    ebx[0x2e] = eax[0x2e];
    ebx[0x4c] = eax[0x4c];
    asm { fld        dword [eax+0x1a8] };
    asm { fstp       dword [ebx+0x1a8] };
    ebx[0x6b] = eax[0x6b];
    ebx[0x80] = eax[0x80];
    sub_433c50(eax + 0x600);
    eax = ebx;
    return eax;
}
