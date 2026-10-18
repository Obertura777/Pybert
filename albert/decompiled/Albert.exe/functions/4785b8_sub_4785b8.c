// sub_4785b8 @ 0x4785b8
// hopper name: sub_4785b8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4785b8() {
    ebx = arg_8;
    esp = esp - 0x4;
    esi = ecx;
    if (ebx != 0x0) goto loc_4785cf;
    goto .l1;

loc_4785cf:
    if (arg_4 == 0x0) goto .l1;
    goto loc_4785d5;

.l1:
    return;

loc_4785d5:
    if ((esi[0x18] & 0x1) == 0x0) {
            sub_478ca7();
    }
    eax = esi[0xa];
    esp = esp - 0x4;
    edi = esi[0xb];
    edi = edi - eax;
    if (ebx < edi) {
            edi = ebx;
    }
    sub_46dc09(arg_4, ebx, eax, edi);
    esi[0xa] = esi[0xa] + edi;
    arg_4 = arg_4 + edi;
    esp = (esp - 0x10) + 0x10;
    ebx = ebx - edi;
    if (ebx == 0x0) goto loc_4786db;
    goto loc_478610;

loc_4786db:
    esp = esp + 0x4;
    return;

loc_478610:
    edi = ebx - ebx % esi[0x8];
    decomp_var_8 = decomp_var_8 & 0x0;
    decomp_var_4 = edi;
    goto loc_478622;

loc_478622:
    esp = esp - 0x8;
    eax = *esi[0x9];
    eax = (eax[0xd])(arg_4, decomp_var_4);
    arg_4 = arg_4 + eax;
    decomp_var_8 = decomp_var_8 + eax;
    decomp_var_4 = decomp_var_4 - eax;
    if (eax > 0x0 && decomp_var_4 > 0x0) {
            continue;
    }
    break;
    ebx = ebx - decomp_var_8;
    if (ebx != 0x0 && decomp_var_8 == edi) {
            if (esi[0x2] == 0x0) {
                    edi = 0x0;
                    if (esi[0x3] == 0x0) {
                            eax = esi[0x8];
                            decomp_var_4 = eax;
                            if (ebx > eax) {
                                    decomp_var_4 = ebx;
                            }
                    }
                    else {
                            decomp_var_4 = ebx;
                    }
                    decomp_var_8 = esi[0xc];
                    while (true) {
                            esp = esp - 0x8;
                            eax = *esi[0x9];
                            eax = (eax[0xd])(decomp_var_8, decomp_var_4);
                            decomp_var_8 = decomp_var_8 + eax;
                            decomp_var_4 = decomp_var_4 - eax;
                            edi = edi + eax;
                            if (eax <= 0x0) {
                                    temp_2 = 0x1;
                                    break;
                            }
                            if (decomp_var_4 <= 0x0) {
                                    temp_2 = 0x0;
                                    break;
                            }
                            if (edi < ebx) {
                                    continue;
                            }
                            temp_2 = 0x0;
                            break;
                    }
                    eax = esi[0xc];
                    esi[0xb] = eax + edi;
            }
            else {
                    esp = esp - 0x10;
                    (*(*esi[0x9] + 0x50))(0x0, esi[0x8], esi + 0x30, esi + 0x2c);
                    eax = esi[0xc];
            }
            edi = esi[0xb];
            edi = edi - eax;
            esi[0xa] = eax;
            if (ebx < edi) {
                    edi = ebx;
            }
            sub_46dc09(arg_4, ebx, eax, edi);
            esi[0xa] = esi[0xa] + edi;
            esp = (esp - 0x10) + 0x10;
            ebx = ebx - edi;
    }
    goto loc_4786db;
}
