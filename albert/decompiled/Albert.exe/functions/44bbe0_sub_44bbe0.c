// sub_44bbe0 @ 0x44bbe0
// hopper name: sub_44bbe0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44bbe0() {
    decomp_var_10 = ebx;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    edi = ecx;
    decomp_var_24 = edi;
    var_8 = edi;
    var_9 = 0x0;
    sub_45abe0();
    esp = (esp - 0x24) + 0x8 - 0x4;
    eax = sub_407720(&arg_4);
    if (*(int16_t *)word_4c6c08 == eax[0x2]) {
            var_9 = 0x1;
    }
    ebp = arg_8;
    ebx = arg_4;
    decomp_var_24 = ebp;
    decomp_var_28 = ebx;
    sub_4606e0(decomp_var_28, decomp_var_24, arg_c);
    eax = sub_41c340(&arg_8);
    *eax = ebx;
    edi = ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx) + ((ebx << 0x4) - ebx);
    edi[0x2ebb68] = 0x2;
    edi[0x2ebb6a] = ebp;
    edi[0x2ebb6b] = arg_c;
    esp = esp - 0x14;
    esi = ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp);
    esi[0x2ebb75] = 0x1;
    eax = sub_41c1e0(&arg_8);
    esi[0x2ebb6e] = *eax;
    edx = eax[0x1];
    eax = arg_0;
    esi[0x2ebb6f] = edx;
    esi[0x2ebb79] = *((((eax << 0x8) + ebx << 0x8) + ebp) * 0x4 + 0x635578);
    if (var_9 == 0x1 && edi[0x2ebb7c] != 0x5) {
            esi[0x2ebb80] = 0x0;
            esi[0x2ebb81] = 0x0;
    }
    sub_437510(eax, ebp);
    decomp_var_28 = ebp;
    eax = sub_4412c0(arg_0, ebx, decomp_var_28, decomp_var_24, 0x0, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c);
    return eax;
}
