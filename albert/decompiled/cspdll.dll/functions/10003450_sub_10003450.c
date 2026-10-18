// sub_10003450 @ 0x10003450
// hopper name: sub_10003450
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003450() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    edi = arg_0;
    esi = *edi;
    eax = *(int8_t *)esi;
    if (eax >= 0x30) {
            while (true) {
                    if (eax > 0x39) {
                            temp_0 = 0x0;
                            break;
                    }
                    eax = esi[0x1];
                    esi = esi + 0x1;
                    if (eax >= 0x30) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    ebx = *(int8_t *)esi;
    *(int8_t *)esi = 0x0;
    eax = *edi;
    atoi(eax);
    *(int8_t *)esi = ebx;
    *edi = esi;
    eax = (*0x10009140)();
    *(int16_t *)arg_4 = eax;
    return eax;
}
