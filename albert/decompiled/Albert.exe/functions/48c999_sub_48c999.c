// sub_48c999 @ 0x48c999
// hopper name: sub_48c999
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c999() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_34 = ebx;
    ebx = arg_8;
    decomp_var_38 = esi;
    var_30 = arg_c;
    decomp_var_3c = edi;
    sub_48c8de(&var_10, &arg_0);
    decomp_var_40 = &var_2C;
    decomp_var_44 = 0x0;
    decomp_var_48 = 0x11;
    esp = (esp - 0x14) + 0x8 - 0x18;
    decomp_var_54 = var_10;
    decomp_var_54 = var_10;
    asm { movsw      word [edi], word [esi] };
    esi = var_30;
    ebx[0x2] = sub_49106d(decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40);
    *ebx = sign_extend_32(var_2A);
    ebx[0x1] = sign_extend_32(var_2C);
    eax = sub_47db5e(esi, arg_10, &var_28);
    esp = (esp - 0xc) + 0x24;
    if (eax != 0x0) {
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    ebx[0x3] = esi;
    eax = sub_47ad69();
    return eax;
}
