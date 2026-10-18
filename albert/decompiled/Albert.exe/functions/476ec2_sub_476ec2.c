// sub_476ec2 @ 0x476ec2
// hopper name: sub_476ec2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476ec2() {
    eax = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (eax != 0x0) {
            esi[0x1] = eax;
            sub_476e40() + 0x1c;
            *sub_47939c(esi[0x1]) = esi;
            esp = esp - 0xc;
            (*(*esi + 0xc))(esi[0x1]);
            eax = 0x1;
    }
    return eax;
}
