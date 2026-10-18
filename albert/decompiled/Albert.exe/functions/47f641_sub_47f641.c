// sub_47f641 @ 0x47f641
// hopper name: sub_47f641
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f641() {
    esp = esp - 0x8;
    sub_47f31c(saved_fp, arg_0);
    ebx = arg_4;
    if (ebx == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            loc_47f739();
    }
    else {
            esi = arg_8;
            if (esi > 0xffffffe0) {
                    *sub_47d812() = 0xc;
                    loc_47f739();
            }
            else {
                    if (*dword_bc720c == 0x3) {
                            sub_487c06(saved_fp);
                            eax = sub_487d79(saved_fp);
                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                            if (eax != 0x0 && esi <= *dword_bc7218) {
                                    sub_48826e(saved_fp, arg_0, arg_4) == 0x0;
                            }
                            sub_47f727();
                    }
                    else {
                            sub_47f730();
                    }
            }
    }
    return;
}
