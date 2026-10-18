// CancelPriorPress @ 0x40e8e0
// hopper name: sub_40e8e0
// pybert name: CancelPriorPress
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

CancelPriorPress() {
    var_C = *0x0;
    decomp_var_30 = esi;
    esp = esp - 0x34;
    decomp_var_34 = *dword_4c8db8 ^ &decomp_var_30;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    bool_0 = *(int8_t *)byte_baed47 != 0x0;
    eax = esi[0x2];
    ecx = eax[0x2424] & 0xff;
    if (!bool_0) {
            if (*(ecx * 0x4 + dword_623990) <= 0x0) {
                    if (eax[0x92f] > 0x0) {
                            eax = sub_466ed0(&var_1C, 0x4c6ce4);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x10;
                            eax = sub_45a9b0(&var_2C);
                            *(int8_t *)byte_baed47 = 0x1;
                            eax = sub_465fa0();
                            *0x0 = var_C;
                    }
                    else {
                            eax = sub_465fa0();
                            *0x0 = var_C;
                    }
            }
            else {
                    eax = sub_466ed0(&var_1C, 0x4c6ce4);
                    sub_465ff0(eax);
                    sub_465fa0();
                    esp = esp - 0x10;
                    eax = sub_45a9b0(&var_2C);
                    *(int8_t *)byte_baed47 = 0x1;
                    eax = sub_465fa0();
                    *0x0 = var_C;
            }
    }
    else {
            eax = sub_465fa0();
            *0x0 = var_C;
    }
    return eax;
}
