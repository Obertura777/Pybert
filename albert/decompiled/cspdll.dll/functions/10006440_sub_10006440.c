// sub_10006440 @ 0x10006440
// hopper name: sub_10006440
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006440() {
    edx = arg_4;
    decomp_var_4 = ebx;
    decomp_var_c = 0x0;
    esp = esp - 0x10;
    decomp_var_10 = &arg_4;
    ecx = ecx | 0xffffffff;
    asm { repne scasb al, byte [edi] };
    ebx = sub_100066d0(arg_0, edx, (!ecx - 0x1) + 0x1, decomp_var_10, decomp_var_c);
    esp = (esp - 0xc) + 0x14;
    if (ebx == 0x0) {
            esp = (esp - 0x4) + 0x4;
            *arg_c = atoi(arg_4);
    }
    eax = ebx;
    return eax;
}
