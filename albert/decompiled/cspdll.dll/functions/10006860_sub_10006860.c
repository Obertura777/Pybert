// sub_10006860 @ 0x10006860
// hopper name: sub_10006860
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006860() {
    decomp_var_4 = esi;
    esi = arg_0;
    eax = *esi;
    eax = ftell(eax, decomp_var_4);
    esp = (esp - 0x8) + 0x4;
    if (eax > esi[0x41]) {
            fclose(*esi, edi, ebx);
            remove(esi + 0x80);
            rename(esi + 0x4, esi + 0x80);
            eax = fopen(esi + 0x4, 0x1000aaec);
            *esi = eax;
            esp = (esp - 0x20) + 0x20;
    }
    return eax;
}
