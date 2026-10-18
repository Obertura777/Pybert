// sub_41d160 @ 0x41d160
// hopper name: sub_41d160
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41d160() {

sub_41d160:
    arg_38 = ebx[0x1];
    if (eax == 0x0 || eax != ebx) {
            sub_47a948();
            eax = arg_14;
    }
    if (edi == arg_38) goto loc_41d1e5;
    goto loc_41d17e;

loc_41d1e5:
    &arg_8 = ebp;
    return eax;

loc_41d17e:
    if (eax == 0x0) {
            sub_47a948();
            eax = arg_14;
    }
    if (edi == eax[0x1]) {
            sub_47a948();
    }
    arg_1c = edi[0x4];
    eax = sub_41c1e0(&arg_1c);
    esp = esp - 0x8;
    edi = eax;
    eax = sub_41c1e0(&arg_1c);
    *eax = *edi;
    eax[0x1] = edi[0x1];
    sub_40f6f0();
    edi = arg_18;
    eax = arg_14;
    goto sub_41d160;
}
