// sub_449ad0 @ 0x449ad0
// hopper name: sub_449ad0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_449ad0() {

sub_449ad0:
    eax = arg_c[0x2];
    ebx = eax[0x91e];
    eax = eax + 0x2474;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l1;
    goto .l2;

.l1:
    eax = (null)();
    return eax;

.l2:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    bool_6 = edi != esi[0x1];
    arg_B0 = edi[0x3];
    if (!bool_6) {
            sub_47a948();
    }
    eax = arg_c[0x2];
    ecx = eax[0x92f];
    bool_5 = ecx <= eax[0x938];
    ecx = arg_60;
    if (!bool_5) {
            esp = esp - 0x4;
            eax = sub_41c1e0(&arg_B0);
            *eax = *eax + 0x2710;
            eax[0x1] = eax[0x1] + 0x0 + CARRY(EFLAGS(cf));
            sub_40e680();
            edi = arg_90;
            esi = arg_8C;
    }
    else {
            esp = esp - 0x4;
            eax = sub_41c1e0(&arg_B0);
            *eax = *eax + 0xffffd8f0;
            eax[0x1] = eax[0x1] + 0xffffffff + CARRY(EFLAGS(cf));
            sub_40e680();
            edi = arg_90;
            esi = arg_8C;
    }
    goto sub_449ad0;
}
