// EvaluateOrderProposalsAndSendGOF @ 0x457520
// hopper name: sub_457520
// pybert name: EvaluateOrderProposalsAndSendGOF
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

EvaluateOrderProposalsAndSendGOF() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_74 = ebx;
    decomp_var_78 = ebp;
    decomp_var_7c = esi;
    decomp_var_80 = edi;
    esp = esp - 0x84;
    var_84 = *dword_4c8db8 ^ &decomp_var_80;
    *0x0 = &var_C;
    ebp = ecx;
    var_6C = ebp;
    var_6D = 0x0;
    sub_465870();
    sub_465870();
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    var_60 = 0xbb65c8;
    var_5C = **dword_bb65cc;
    goto loc_457593;

loc_457593:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi == *dword_bb65cc) goto .l13;
    goto loc_4575b2;

.l13:
    break;

loc_4575b2:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x20] != 0x0) {
            sub_40f860();
            esi = var_5C;
            edi = var_60;
            ebp = var_6C;
            continue;
    }
    var_6E = 0x1;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebp = esi + 0x30;
    ebx = *esi[0xd];
    var_58 = ebp;
    var_54 = ebx;
    goto loc_4575f0;
    if (var_6D == 0x1) {
            sub_40cdc0();
            sub_456b50();
    }
    else {
            sub_4424e0();
    }
    sub_465fa0();
    sub_465fa0();
    *0x0 = var_C;
    &decomp_var_70 = decomp_var_78;
    return;

loc_4575f0:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    edi = esi[0xd];
    if (ebp == 0x0 || ebp != esi + 0x30) {
            sub_47a948();
    }
    if (ebx != edi) {
            if (esi == var_60[0x1]) {
                    sub_47a948();
            }
            edi = esi + 0x3c;
            var_44 = esi[0x10];
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == ret_addr) {
                    sub_47a948();
            }
            ebp = ebx + 0xc;
            if (esi == var_60[0x1]) {
                    sub_47a948();
            }
            decomp_var_88 = ebp;
            esp = esp - 0x8;
            decomp_var_8c = &var_40;
            eax = sub_401ff0(decomp_var_8c, decomp_var_88, var_84, decomp_var_80, decomp_var_7c);
            eax = *eax;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (ret_addr == var_44) {
                    var_6E = 0x0;
            }
            sub_401520();
            ebx = var_54;
            ebp = var_58;
            edi = var_60;
            continue;
    }
    break;
    if (var_6E != 0x1) {
            sub_40f860();
            esi = var_5C;
            edi = var_60;
            ebp = var_6C;
            continue;
    }
    ebx = var_60;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esi[0x20] = 0x1;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x14] != 0x0) {
            sub_40f860();
            esi = var_5C;
            edi = var_60;
            ebp = var_6C;
            continue;
    }
    ebp = *(*dword_bb65e4 + 0x4);
    edi = ebp;
    if (arg_9 == 0x0) {
            &var_84 = &var_84;
            do {
                    sub_401950(edi[0x2]);
                    edi = *edi;
                    decomp_var_88 = ebp;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x11] == 0x0);
    }
    eax = *dword_bb65e4;
    eax[0x1] = eax;
    eax = *dword_bb65e4;
    *dword_bb65e8 = 0x0;
    *eax = eax;
    eax = *dword_bb65e4;
    eax[0x2] = eax;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    ebp = esi + 0x30;
    if (ebp != 0xbb65e0) {
            eax = *dword_bb65e4;
            decomp_var_8c = 0xbb65e0;
            decomp_var_90 = *eax;
            decomp_var_98 = &var_38;
            sub_403430(decomp_var_98, 0xbb65e0, decomp_var_90, 0xbb65e0, eax);
            esp = esp - 0x18;
            decomp_var_88 = ebp;
            sub_402210(decomp_var_88);
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    edi = esi + 0x54;
    ebx = *esi[0x16];
    var_50 = edi;
    var_4C = ebx;
    &var_84 = &var_84;
    goto loc_457780;

loc_457780:
    if (esi == var_60[0x1]) {
            sub_47a948();
    }
    ebp = esi[0x16];
    eax = esi + 0x54;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != ebp) {
            if (esi == var_60[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x10;
            decomp_var_94 = esi + 0x3c;
            sub_405090(decomp_var_94);
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x14;
            sub_465f60(ebx + 0xc);
            eax = sub_4240d0(decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70);
            if (eax == 0x1) {
                    var_6D = eax;
            }
            sub_401590();
            ebx = var_4C;
            edi = var_50;
            continue;
    }
    break;
    sub_40f860();
    esi = var_5C;
    edi = var_60;
    ebp = var_6C;
    continue;
}
