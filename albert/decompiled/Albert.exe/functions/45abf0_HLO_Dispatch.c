// HLO_Dispatch @ 0x45abf0
// hopper name: sub_45abf0
// pybert name: HLO_Dispatch
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

HLO_Dispatch() {
    var_C = *0x0;
    decomp_var_40 = ebx;
    decomp_var_44 = esi;
    decomp_var_48 = edi;
    decomp_var_4c = *dword_4c8db8 ^ &decomp_var_48;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    sub_465870();
    edi = arg_0;
    eax = sub_466060(&var_1C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_1C, 0x2);
    sub_465ff0(eax);
    sub_465fa0();
    decomp_var_50 = ecx;
    arg_0 = &decomp_var_50;
    sub_4658f0(&decomp_var_50);
    sub_460de0(decomp_var_50);
    esp = esp - 0x70;
    eax = sub_4658f0(&arg_0);
    eax = *(int16_t *)eax & 0xffff;
    bool_0 = (eax & 0x2000) == 0x0;
    eax = eax & 0xffff;
    if (!bool_0) {
            eax = eax | 0xffffe000;
    }
    *(esi[0x2] + 0x2428) = eax;
    eax = sub_466060(&var_1C, 0x3);
    sub_465ff0(eax);
    sub_465fa0();
    *(int8_t *)(esi[0x2] + 0x2448) = 0x1;
    (*(*esi + 0xd4))(edi);
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
