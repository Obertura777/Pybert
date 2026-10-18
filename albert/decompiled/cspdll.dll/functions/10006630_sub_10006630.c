// sub_10006630 @ 0x10006630
// hopper name: sub_10006630
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006630() {
    decomp_var_4 = ebx;
    ebx = arg_8;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    decomp_var_10 = edi;
    eax = sub_10006750(arg_0, arg_4, ebx);
    esp = (esp - 0x1c) + 0xc;
    ebp = arg_0[0x1] + (eax * 0x8 - eax) * 0x4;
    if (ebp != 0x0) {
            if (arg_c == ebx) {
                    edi = arg_8;
                    esi = arg_4;
                    asm { rep  cmpsb byte [esi], byte [edi] };
                    if (!asm { rep  cmpsb byte [esi], byte [edi] }) {
                            ebp = *(*ebp + 0x8);
                            if (ebp != 0x0) {
                                    continue;
                            }
                            eax = 0x0;
                            break;
                    }
                    else {
                            *(*ebp + 0x4) = arg_0;
                            *arg_0 = *ebp;
                            *ebp = 0x0;
                            free(arg_8);
                            free(arg_10);
                            eax = 0x1;
                            break;
                    }
            }
            else {
                    ebp = *(*ebp + 0x8);
                    if (ebp != 0x0) {
                            continue;
                    }
                    eax = 0x0;
                    break;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
