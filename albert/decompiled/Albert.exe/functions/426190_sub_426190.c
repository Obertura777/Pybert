// sub_426190 @ 0x426190
// hopper name: sub_426190
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_426190() {

sub_426190:
    ebp = arg_60;
    if (ebx == 0x0 || ebx != &arg_5C) {
            sub_47a948();
    }
    if (edi == ebp) goto loc_4262de;
    goto loc_4261ad;

loc_4262de:
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&arg_20, &arg_5C, *arg_60, &arg_5C, arg_60);
    sub_47c8f9();
    eax = arg_10;
    *0x0 = arg_28;
    return eax;

loc_4261ad:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(edi + 0xc);
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    bool_8 = edi[0x1c] != 0x1;
    arg_14 = &decomp_var_10;
    eax = sub_465f60(&arg_4c);
    decomp_var_14 = ecx;
    decomp_var_14 = arg_48;
    esp = esp - 0x2c;
    eax = sub_465f60(&arg_38);
    eax = sub_422a90();
    if (!bool_8) {
            if (eax > 0xfffea070) {
                    sub_465f30(esi[0x2] + 0x2424);
                    decomp_var_38 = ecx;
                    decomp_var_38 = *(int16_t *)(esi[0x2] + 0x2424);
                    esp = esp - 0x2c;
                    sub_465f60(&arg_14);
                    arg_c = 0x2;
                    eax = sub_422a90();
                    if (eax <= 0xfffec780) {
                            eax = 0x186a0;
                    }
            }
    }
    ecx = var_34;
    if (ecx == 0x0 && eax == 0x186a0) {
            var_34 = eax;
            sub_40f6f0();
            edi = var_20;
            ebx = var_24;
    }
    else {
            if (eax < ecx) {
                    var_34 = eax;
            }
            sub_40f6f0();
            edi = var_20;
            ebx = var_24;
    }
    goto sub_426190;
}
