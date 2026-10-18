// sub_10002eb0 @ 0x10002eb0
// hopper name: sub_10002eb0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002eb0() {
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    decomp_var_14 = edi;
    edi = arg_4 + 0x4;
    esp = esp - 0x18;
    decomp_var_18 = arg_4[0x1];
    esi = (*0x10009150)();
    if (esi > 0x0) {
            ebp = saved_fp;
            while (true) {
                    decomp_var_1c = *(int16_t *)edi;
                    eax = (*0x10009150)();
                    eax = sub_10002f50(ebp, eax, &arg_0, &arg_4, &var_9, decomp_var_1c, decomp_var_18);
                    esp = (esp - 0x18) + 0x14;
                    if (eax == 0x0) {
                            *(int8_t *)(arg_0 - 0x1) = 0x0;
                            eax = 0x0;
                            break;
                    }
                    esi = esi + 0xfffe;
                    edi = edi + 0x2;
                    if (esi > 0x0) {
                            continue;
                    }
                    *(int8_t *)(arg_0 - 0x1) = 0x0;
                    eax = 0x1;
                    break;
            }
    }
    else {
            eax = 0x1;
            *(int8_t *)(arg_4 - 0x1) = 0x0;
    }
    return eax;
}
