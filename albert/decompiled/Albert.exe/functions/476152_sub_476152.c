// sub_476152 @ 0x476152
// hopper name: sub_476152
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476152() {
    decomp_var_4 = 0x30;
    sub_47d6ee(0x30);
    esi = arg_4;
    esp = (esp - 0x10) + 0xc;
    if (sub_472514() == 0x0) {
            esp = (esp - 0x4) + 0x4;
            if (sub_472481() != 0x0) {
                    if (*(int8_t *)(sub_4715ba() + 0x14) != 0x0) {
                            sub_478104();
                            sub_4715ba();
                            sub_46ddc3(esi[0x9]);
                            sub_46dd4c(0xa);
                            sub_478171();
                    }
            }
    }
    eax = sub_47d75a();
    return eax;
}
