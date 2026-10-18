// sub_10003400 @ 0x10003400
// hopper name: sub_10003400
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003400() {
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = *esi;
    ecx = edi + 0x1;
    *esi = edi + 0x1;
    eax = *(int8_t *)ecx;
    if (eax != 0x27) {
            edi = arg_4;
            do {
                    esp = esp - 0x4;
                    decomp_var_c = sign_extend_32(eax) + 0x4b00;
                    *(int16_t *)*edi = (*0x10009140)();
                    *edi = *edi + 0x2;
                    eax = *esi;
                    ecx = eax + 0x1;
                    *esi = eax + 0x1;
                    eax = *(int8_t *)ecx;
            } while (eax != 0x27);
    }
    *esi = ecx + 0x1;
    return eax;
}
