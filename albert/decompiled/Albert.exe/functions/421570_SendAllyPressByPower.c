// SendAllyPressByPower @ 0x421570
// hopper name: sub_421570
// pybert name: SendAllyPressByPower
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

SendAllyPressByPower() {
    var_8 = 0x495da8;
    var_C = *0x0;
    decomp_var_4c = ebx;
    decomp_var_50 = ebp;
    decomp_var_54 = esi;
    decomp_var_58 = edi;
    *0x0 = &var_C;
    sub_465870();
    edx = &var_44;
    var_48 = arg_0 & 0xff | 0x4100;
    eax = sub_466ed0(edx, &var_48);
    sub_465ff0(eax);
    sub_465fa0();
    sub_418db0(arg_0);
    esp = esp - 0x70;
    decomp_var_60 = 0x0;
    if (*(int8_t *)byte_baed32 == 0x0) {
            esp = esp + 0x4;
            edi = sub_47b26f(decomp_var_60);
            ecx = sub_47b678();
            esi = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0xf - *dword_ba2880;
            bool_2 = true;
            eax = *dword_624ef4;
            ecx = (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0xf & 0x80000000 ? 0xffffffff : 0x0) - *dword_ba2884 + CARRY(EFLAGS(cf));
            ecx = ecx + edx + CARRY(EFLAGS(cf));
            esi = esi + edi + 0x7;
            ecx = ecx + 0x0 + CARRY(EFLAGS(cf));
            if (eax > 0x0) {
                    eax = *dword_624ef4;
                    eax = eax - 0x14;
                    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
                    bool_6 = ecx > edx;
                    if (ecx >= edx) {
                            if (!bool_6) {
                                    if (esi > eax) {
                                            ecx = edx;
                                            esi = eax;
                                    }
                            }
                            else {
                                    ecx = edx;
                                    esi = eax;
                            }
                    }
            }
    }
    else {
            eax = sub_47b26f(decomp_var_60);
            esp = esp + 0x4;
            eax = eax - *dword_ba2880;
            ecx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
            esi = eax;
    }
    var_20 = esi;
    sub_465f60(&var_30);
    sub_419c30(&var_40, &var_20, decomp_var_58);
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = var_8;
    return eax;
}
