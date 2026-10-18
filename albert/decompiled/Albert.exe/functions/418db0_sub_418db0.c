// sub_418db0 @ 0x418db0
// hopper name: sub_418db0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_418db0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_40 = ebx;
    decomp_var_44 = esi;
    decomp_var_48 = edi;
    decomp_var_4c = *dword_4c8db8 ^ &decomp_var_48;
    *0x0 = &var_C;
    sub_465870();
    var_3C = arg_0 & 0xff | 0x4100;
    eax = sub_466ed0(&var_30, &var_3C);
    esp = esp - 0x58;
    sub_465ff0(eax);
    sub_465fa0();
    goto loc_418e2c;

loc_418e2c:
    edi = **dword_bb65c0;
    esi = 0xbb65bc;
    var_34 = **dword_bb65c0;
    var_38 = 0xbb65bc;
    goto loc_418e40;

loc_418e40:
    if (esi == 0x0 || esi != 0xbb65bc) {
            sub_47a948();
    }
    if (edi == *dword_bb65c0) goto loc_418ea5;
    goto loc_418e5b;

loc_418ea5:
    sub_465fa0();
    *0x0 = var_C;
    &var_3C = ebp;
    return;

loc_418e5b:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&var_20);
    if (eax == 0x0) {
            sub_40e210();
            edi = var_34;
            esi = var_38;
            continue;
    }
    break;
    esp = esp - 0xc;
    eax = sub_411fb0(&var_30, esi, edi, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, var_3C, var_38, var_34, var_30, decomp_var_2c, decomp_var_28, decomp_var_24, var_20, decomp_var_1c, decomp_var_18, decomp_var_14);
    continue;
}
