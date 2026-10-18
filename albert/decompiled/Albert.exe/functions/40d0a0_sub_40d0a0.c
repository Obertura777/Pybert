// sub_40d0a0 @ 0x40d0a0
// hopper name: sub_40d0a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40d0a0() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    esp = esp - 0x2c;
    *0x0 = &var_C;
    ebx = 0x0;
    ebp = 0x0;
    eax = sub_465930();
    var_10 = eax;
    if (eax > 0x0) {
            do {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_14, ebp);
                    edi = *(int8_t *)eax & 0xff;
                    esi = 0x0;
                    do {
                            if (ebp != esi) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_12, esi);
                                    ebx = ebx | 0x1 | 0x2;
                                    if ((*(int8_t *)eax & 0xff) == edi) {
                                            eax = 0x1;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                            if ((ebx & 0x2) != 0x0) {
                                    ebx = ebx & 0xfffffffd;
                            }
                            if ((ebx & 0x1) != 0x0) {
                                    ebx = ebx & 0xfffffffe;
                            }
                            if (eax != 0x0) {
                                    var_5 = 0x1;
                            }
                            esi = esi + 0x1;
                    } while (esi < saved_fp);
                    ebp = &ret_addr;
            } while (ebp < saved_fp);
    }
    sub_465fa0();
    eax = var_5;
    *0x0 = arg_0;
    return eax;
}
