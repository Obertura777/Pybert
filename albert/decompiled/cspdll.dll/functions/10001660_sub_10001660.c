// sub_10001660 @ 0x10001660
// hopper name: sub_10001660
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001660() {
    eax = arg_0;
    decomp_var_4 = esi;
    esi = arg_8;
    edx = 0x0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_4;
    if (esi > 0x1) {
            while (true) {
                    ecx = *eax;
                    ecx = *(int16_t *)ecx;
                    if (ecx != 0x4b) {
                            temp_0 = 0x0;
                            break;
                    }
                    *(int8_t *)edi = HIBYTE(ecx);
                    edi = edi + 0x1;
                    *eax = *eax + 0x2;
                    esi = esi - 0x1;
                    edx = 0x1;
                    if (esi > 0x1) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    if (*(int16_t *)*eax != 0x4b && edx != 0x0) {
            *(int8_t *)edi = 0x0;
            eax = 0x1;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
