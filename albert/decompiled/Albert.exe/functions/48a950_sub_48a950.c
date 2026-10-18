// sub_48a950 @ 0x48a950
// hopper name: sub_48a950
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48a950() {
    eax = 0x1;
    if ((arg_0[0x1] & 0x6) != 0x0) {
            eax = sub_47ad69();
            sub_48a995(eax[0x9], eax[0xa]);
            *arg_c = arg_4;
            eax = 0x3;
    }
    return eax;
}
