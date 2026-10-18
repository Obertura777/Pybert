// sub_46f1b2 @ 0x46f1b2
// hopper name: sub_46f1b2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f1b2() {
    ebp = &decomp_var_78;
    arg_70 = *dword_4c8db8 ^ ebp;
    esp = esp - 0xa0;
    eax = GetMenuCheckMarkDimensions();
    ebx = sign_extend_32(eax);
    ecx = sign_extend_32(eax >> 0x10);
    decomp_var_18 = ecx;
    if (ebx <= 0x4 || ecx <= 0x5) {
            sub_46dedc();
    }
    if (ebx > 0x20) {
            ebx = saved_fp;
            esp = (esp - 0x4) + 0x4;
    }
    esi = SAR(ebx + 0xf, 0x4);
    edi = (SAR(ebx - 0x4 - (ebx - 0x4 & 0x80000000 ? 0xffffffff : 0x0), 0x1)) + (esi << 0x4) - ebx;
    if (edi > 0xc) {
            edi = saved_fp;
            esp = (esp - 0x4) + 0x4;
    }
    eax = saved_fp;
    esp = (esp - 0x4) + 0x4;
    if (ecx > eax) {
            decomp_var_18 = eax;
    }
    sub_47ba40(saved_fp, arg_0, arg_4);
    esp = (esp - 0xc) + 0xc;
    eax = ebp + ((SAR(decomp_var_18 - 0x6, 0x1)) * esi * 0x2 - 0xc);
    edx = 0x4b26fc;
    decomp_var_14 = esi + esi;
    decomp_var_10 = 0x5;
    do {
            esi = *(int8_t *)edx & 0xff;
            edx = edx + 0x1;
            *(int8_t *)eax = HIBYTE(!(esi << edi) & 0xffff);
            eax[0x1] = !(esi << edi) & 0xffff;
            eax = eax + decomp_var_14;
            decomp_var_10 = decomp_var_10 - 0x1;
    } while (decomp_var_10 != 0x0);
    eax = CreateBitmap(saved_fp, arg_0, arg_4, arg_8, arg_c);
    *dword_bc6238 = eax;
    esp = (esp - 0x14) + 0xc;
    if (eax == 0x0) {
            *dword_bc6238 = LoadBitmapA(saved_fp, arg_0);
    }
    sub_47ad69();
    return;
}
