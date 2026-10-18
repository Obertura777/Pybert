// sub_100066d0 @ 0x100066d0
// hopper name: sub_100066d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100066d0() {
    decomp_var_4 = ebx;
    ebx = arg_8;
    decomp_var_8 = ebp;
    ebp = arg_4;
    decomp_var_c = esi;
    decomp_var_10 = edi;
    eax = sub_10006750(arg_0, ebp, ebx);
    esp = (esp - 0x1c) + 0xc;
    eax = *(arg_0[0x1] + (eax * 0x8 - eax) * 0x4);
    eax = eax[0x2];
    if (eax != 0x0) {
            while (true) {
                    if (ebx != eax[0x10]) {
                            eax = *eax;
                            eax = eax[0x2];
                            if (eax != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    edi = eax[0x3];
                    esi = ebp;
                    asm { rep  cmpsb byte [esi], byte [edi] };
                    if (asm { rep  cmpsb byte [esi], byte [edi] }) {
                            ecx = arg_10;
                            if (ecx != 0x0) {
                                    *ecx = eax[0x6];
                                    temp_0 = 0x1;
                            }
                            else {
                                    temp_0 = 0x1;
                            }
                            break;
                    }
                    eax = *eax;
                    eax = eax[0x2];
                    if (eax != 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    ecx = arg_c;
                    if (ecx != 0x0) {
                            *ecx = eax[0x5];
                    }
                    eax = 0x0;
            }
            else {
                    eax = 0x2;
            }
    }
    else {
            eax = 0x2;
    }
    return eax;
}
