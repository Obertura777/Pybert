// sub_4733ea @ 0x4733ea
// hopper name: sub_4733ea
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4733ea() {
    edi = arg_4;
    if (edi == 0x0) {
            eax = 0x80004003;
    }
    else {
            sub_471606(*(arg_0 - 0x18));
            *edi = *(arg_0 - 0x14);
            esp = (esp - 0x8) + 0x4;
            if (var_4 != 0x0) {
                    esp = esp - 0x8;
                    sub_470ddd();
            }
            eax = 0x0;
    }
    return eax;
}
