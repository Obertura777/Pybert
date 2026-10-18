// AwaitPressAndSendGOF @ 0x443ed0
// hopper name: sub_443ed0
// pybert name: AwaitPressAndSendGOF
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

AwaitPressAndSendGOF() {
    var_C = *0x0;
    decomp_var_30 = ebp;
    decomp_var_34 = esi;
    decomp_var_38 = edi;
    esp = esp - 0x3c;
    decomp_var_3c = *dword_4c8db8 ^ &decomp_var_38;
    *0x0 = &var_C;
    edi = ecx;
    sub_465870();
    sub_4424e0();
    if (*dword_bb65c4 == 0x0) goto .l2;
    goto loc_443f1f;

.l2:
    if (*(int8_t *)byte_baed47 == 0x1) {
            while (true) {
                    if (sub_411740() != 0x1) {
                            temp_0 = 0x0;
                            break;
                    }
                    if (sub_45b860() != 0x0) {
                            temp_0 = 0x0;
                            break;
                    }
                    if (*dword_bb65c4 != 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esp = esp - 0x4;
                    if (sub_4117d0(0xffffffff) != 0x1) {
                            temp_0 = 0x2;
                            break;
                    }
                    eax = sub_47b26f(0x0);
                    esi = *dword_ba2858;
                    ecx = *dword_ba285c;
                    esp = (esp - 0x4) + 0x4;
                    eax = eax - *dword_ba2880;
                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                    esi = esi + 0x19;
                    bool_201 = edx < ecx + 0x0 + CARRY(EFLAGS(cf));
                    if (edx > ecx + 0x0 + CARRY(EFLAGS(cf))) {
                            temp_0 = 0x3;
                            break;
                    }
                    if (bool_201) {
                            esp = esp - 0x4;
                            Sleep(0x3e8);
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    continue;
                            }
                            temp_0 = 0x4;
                            break;
                    }
                    if (eax > esi) {
                            temp_0 = 0x5;
                            break;
                    }
                    esp = esp - 0x4;
                    Sleep(0x3e8);
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            continue;
                    }
                    temp_0 = 0x4;
                    break;
            }
            switch (temp_0) {
                case 0:
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            if (sub_411740() == 0x1) {
                                    if (sub_45b860() == 0x0) {
                                            if (*dword_bb65c4 == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                            eax = sub_47b26f(0x0);
                                                            esi = *dword_ba2858;
                                                            ecx = *dword_ba285c;
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            esi = esi + 0x19;
                                                            bool_64 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                    if (!bool_64) {
                                                                            if (eax > esi) {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47b26f(0x0);
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            *dword_ba2860 = eax;
                                                            *dword_ba2864 = edx;
                                                            sub_465f30(0x4c6ce4);
                                                            sub_465ff0(&var_1C);
                                                            sub_465fa0();
                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                            eax = sub_45a9b0(&var_2C);
                                                            *(int8_t *)byte_baed47 = 0x0;
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
                    break;
                case 1:
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            if (sub_411740() == 0x1) {
                                    if (sub_45b860() == 0x0) {
                                            if (*dword_bb65c4 == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                            eax = sub_47b26f(0x0);
                                                            esi = *dword_ba2858;
                                                            ecx = *dword_ba285c;
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            esi = esi + 0x19;
                                                            bool_52 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                    if (!bool_52) {
                                                                            if (eax > esi) {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47b26f(0x0);
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            *dword_ba2860 = eax;
                                                            *dword_ba2864 = edx;
                                                            sub_465f30(0x4c6ce4);
                                                            sub_465ff0(&var_1C);
                                                            sub_465fa0();
                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                            eax = sub_45a9b0(&var_2C);
                                                            *(int8_t *)byte_baed47 = 0x0;
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
                    break;
                case 2:
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            if (sub_411740() == 0x1) {
                                    if (sub_45b860() == 0x0) {
                                            if (*dword_bb65c4 == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                            eax = sub_47b26f(0x0);
                                                            esi = *dword_ba2858;
                                                            ecx = *dword_ba285c;
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            esi = esi + 0x19;
                                                            bool_23 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                    if (!bool_23) {
                                                                            if (eax > esi) {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47b26f(0x0);
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            *dword_ba2860 = eax;
                                                            *dword_ba2864 = edx;
                                                            sub_465f30(0x4c6ce4);
                                                            sub_465ff0(&var_1C);
                                                            sub_465fa0();
                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                            eax = sub_45a9b0(&var_2C);
                                                            *(int8_t *)byte_baed47 = 0x0;
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
                    break;
                case 3:
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            if (sub_411740() == 0x1) {
                                    if (sub_45b860() == 0x0) {
                                            if (*dword_bb65c4 == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                            eax = sub_47b26f(0x0);
                                                            esi = *dword_ba2858;
                                                            ecx = *dword_ba285c;
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            esi = esi + 0x19;
                                                            bool_6 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                    if (!bool_6) {
                                                                            if (eax > esi) {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47b26f(0x0);
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            *dword_ba2860 = eax;
                                                            *dword_ba2864 = edx;
                                                            sub_465f30(0x4c6ce4);
                                                            sub_465ff0(&var_1C);
                                                            sub_465fa0();
                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                            eax = sub_45a9b0(&var_2C);
                                                            *(int8_t *)byte_baed47 = 0x0;
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
                    break;
                case 4:
                    sub_465fa0();
                    *0x0 = var_C;
                    break;
                default:
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            if (sub_411740() == 0x1) {
                                    if (sub_45b860() == 0x0) {
                                            if (*dword_bb65c4 == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                            eax = sub_47b26f(0x0);
                                                            esi = *dword_ba2858;
                                                            ecx = *dword_ba285c;
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            esi = esi + 0x19;
                                                            bool_29 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                    if (!bool_29) {
                                                                            if (eax > esi) {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47b26f(0x0);
                                                            eax = eax - *dword_ba2880;
                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                            *dword_ba2860 = eax;
                                                            *dword_ba2864 = edx;
                                                            sub_465f30(0x4c6ce4);
                                                            sub_465ff0(&var_1C);
                                                            sub_465fa0();
                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                            eax = sub_45a9b0(&var_2C);
                                                            *(int8_t *)byte_baed47 = 0x0;
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
                    break;
            }
    }
    else {
            sub_465fa0();
            *0x0 = var_C;
    }
    return;

loc_443f1f:
    while (true) {
            if (sub_45b860() != 0x0) {
                    temp_1 = 0x3;
                    break;
            }
            if (*(int8_t *)byte_baed47 != 0x1) {
                    temp_1 = 0x2;
                    break;
            }
            if (sub_411740() != 0x1) {
                    temp_1 = 0x0;
                    break;
            }
            esp = esp - 0x4;
            Sleep(0x3e8);
            sub_4424e0();
            if (*dword_bb65c4 != 0x0) {
                    continue;
            }
            temp_1 = 0x1;
            break;
    }
    if (temp_1 == 0x0) goto .l2;
    goto .l51;

.l51:
    if (temp_1 != 0x1) {
            if (temp_1 != 0x2) {
                    if (*(int8_t *)byte_baed47 == 0x1) {
                            while (true) {
                                    if (sub_411740() != 0x1) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (sub_45b860() != 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (*dword_bb65c4 != 0x0) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    if (sub_4117d0(0xffffffff) != 0x1) {
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    eax = sub_47b26f(0x0);
                                    esi = *dword_ba2858;
                                    ecx = *dword_ba285c;
                                    esp = (esp - 0x4) + 0x4;
                                    eax = eax - *dword_ba2880;
                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                    esi = esi + 0x19;
                                    bool_223 = edx < ecx + 0x0 + CARRY(EFLAGS(cf));
                                    if (edx > ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                            temp_0 = 0x3;
                                            break;
                                    }
                                    if (bool_223) {
                                            esp = esp - 0x4;
                                            Sleep(0x3e8);
                                            if (*(int8_t *)byte_baed47 == 0x1) {
                                                    continue;
                                            }
                                            temp_0 = 0x4;
                                            break;
                                    }
                                    if (eax > esi) {
                                            temp_0 = 0x5;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    Sleep(0x3e8);
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            continue;
                                    }
                                    temp_0 = 0x4;
                                    break;
                            }
                            switch (temp_0) {
                                case 0:
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            if (sub_411740() == 0x1) {
                                                    if (sub_45b860() == 0x0) {
                                                            if (*dword_bb65c4 == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                                            eax = sub_47b26f(0x0);
                                                                            esi = *dword_ba2858;
                                                                            ecx = *dword_ba285c;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            esi = esi + 0x19;
                                                                            bool_147 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                                    if (!bool_147) {
                                                                                            if (eax > esi) {
                                                                                                    eax = sub_47b26f(0x0);
                                                                                                    eax = eax - *dword_ba2880;
                                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                                    *dword_ba2860 = eax;
                                                                                                    *dword_ba2864 = edx;
                                                                                                    sub_465f30(0x4c6ce4);
                                                                                                    sub_465ff0(&var_1C);
                                                                                                    sub_465fa0();
                                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                                    break;
                                case 1:
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            if (sub_411740() == 0x1) {
                                                    if (sub_45b860() == 0x0) {
                                                            if (*dword_bb65c4 == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                                            eax = sub_47b26f(0x0);
                                                                            esi = *dword_ba2858;
                                                                            ecx = *dword_ba285c;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            esi = esi + 0x19;
                                                                            bool_87 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                                    if (!bool_87) {
                                                                                            if (eax > esi) {
                                                                                                    eax = sub_47b26f(0x0);
                                                                                                    eax = eax - *dword_ba2880;
                                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                                    *dword_ba2860 = eax;
                                                                                                    *dword_ba2864 = edx;
                                                                                                    sub_465f30(0x4c6ce4);
                                                                                                    sub_465ff0(&var_1C);
                                                                                                    sub_465fa0();
                                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                                    break;
                                case 2:
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            if (sub_411740() == 0x1) {
                                                    if (sub_45b860() == 0x0) {
                                                            if (*dword_bb65c4 == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                                            eax = sub_47b26f(0x0);
                                                                            esi = *dword_ba2858;
                                                                            ecx = *dword_ba285c;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            esi = esi + 0x19;
                                                                            bool_159 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                                    if (!bool_159) {
                                                                                            if (eax > esi) {
                                                                                                    eax = sub_47b26f(0x0);
                                                                                                    eax = eax - *dword_ba2880;
                                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                                    *dword_ba2860 = eax;
                                                                                                    *dword_ba2864 = edx;
                                                                                                    sub_465f30(0x4c6ce4);
                                                                                                    sub_465ff0(&var_1C);
                                                                                                    sub_465fa0();
                                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                                    break;
                                case 3:
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            if (sub_411740() == 0x1) {
                                                    if (sub_45b860() == 0x0) {
                                                            if (*dword_bb65c4 == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                                            eax = sub_47b26f(0x0);
                                                                            esi = *dword_ba2858;
                                                                            ecx = *dword_ba285c;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            esi = esi + 0x19;
                                                                            bool_191 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                                    if (!bool_191) {
                                                                                            if (eax > esi) {
                                                                                                    eax = sub_47b26f(0x0);
                                                                                                    eax = eax - *dword_ba2880;
                                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                                    *dword_ba2860 = eax;
                                                                                                    *dword_ba2864 = edx;
                                                                                                    sub_465f30(0x4c6ce4);
                                                                                                    sub_465ff0(&var_1C);
                                                                                                    sub_465fa0();
                                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                                    break;
                                case 4:
                                    sub_465fa0();
                                    *0x0 = var_C;
                                    break;
                                default:
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            if (sub_411740() == 0x1) {
                                                    if (sub_45b860() == 0x0) {
                                                            if (*dword_bb65c4 == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (sub_4117d0(0xffffffff) != 0x0) {
                                                                            eax = sub_47b26f(0x0);
                                                                            esi = *dword_ba2858;
                                                                            ecx = *dword_ba285c;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            esi = esi + 0x19;
                                                                            bool_165 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                            if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                                    if (!bool_165) {
                                                                                            if (eax > esi) {
                                                                                                    eax = sub_47b26f(0x0);
                                                                                                    eax = eax - *dword_ba2880;
                                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                                    *dword_ba2860 = eax;
                                                                                                    *dword_ba2864 = edx;
                                                                                                    sub_465f30(0x4c6ce4);
                                                                                                    sub_465ff0(&var_1C);
                                                                                                    sub_465fa0();
                                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    sub_465fa0();
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47b26f(0x0);
                                                                            eax = eax - *dword_ba2880;
                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                            *dword_ba2860 = eax;
                                                                            *dword_ba2864 = edx;
                                                                            sub_465f30(0x4c6ce4);
                                                                            sub_465ff0(&var_1C);
                                                                            sub_465fa0();
                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                            eax = sub_45a9b0(&var_2C);
                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                                    break;
                            }
                    }
                    else {
                            sub_465fa0();
                            *0x0 = var_C;
                    }
            }
            else {
                    sub_465fa0();
                    *0x0 = var_C;
            }
    }
    else {
            if (*(int8_t *)byte_baed47 == 0x1) {
                    while (true) {
                            if (sub_411740() != 0x1) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (sub_45b860() != 0x0) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (*dword_bb65c4 != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            esp = esp - 0x4;
                            if (sub_4117d0(0xffffffff) != 0x1) {
                                    temp_0 = 0x2;
                                    break;
                            }
                            eax = sub_47b26f(0x0);
                            esi = *dword_ba2858;
                            ecx = *dword_ba285c;
                            esp = (esp - 0x4) + 0x4;
                            eax = eax - *dword_ba2880;
                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                            esi = esi + 0x19;
                            bool_215 = edx < ecx + 0x0 + CARRY(EFLAGS(cf));
                            if (edx > ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                    temp_0 = 0x3;
                                    break;
                            }
                            if (bool_215) {
                                    esp = esp - 0x4;
                                    Sleep(0x3e8);
                                    if (*(int8_t *)byte_baed47 == 0x1) {
                                            continue;
                                    }
                                    temp_0 = 0x4;
                                    break;
                            }
                            if (eax > esi) {
                                    temp_0 = 0x5;
                                    break;
                            }
                            esp = esp - 0x4;
                            Sleep(0x3e8);
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    continue;
                            }
                            temp_0 = 0x4;
                            break;
                    }
                    switch (temp_0) {
                        case 0:
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    if (sub_411740() == 0x1) {
                                            if (sub_45b860() == 0x0) {
                                                    if (*dword_bb65c4 == 0x0) {
                                                            esp = esp - 0x4;
                                                            if (sub_4117d0(0xffffffff) != 0x0) {
                                                                    eax = sub_47b26f(0x0);
                                                                    esi = *dword_ba2858;
                                                                    ecx = *dword_ba285c;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    esi = esi + 0x19;
                                                                    bool_82 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                    if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                            if (!bool_82) {
                                                                                    if (eax > esi) {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47b26f(0x0);
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    *dword_ba2860 = eax;
                                                                    *dword_ba2864 = edx;
                                                                    sub_465f30(0x4c6ce4);
                                                                    sub_465ff0(&var_1C);
                                                                    sub_465fa0();
                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                    eax = sub_45a9b0(&var_2C);
                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                            break;
                        case 1:
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    if (sub_411740() == 0x1) {
                                            if (sub_45b860() == 0x0) {
                                                    if (*dword_bb65c4 == 0x0) {
                                                            esp = esp - 0x4;
                                                            if (sub_4117d0(0xffffffff) != 0x0) {
                                                                    eax = sub_47b26f(0x0);
                                                                    esi = *dword_ba2858;
                                                                    ecx = *dword_ba285c;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    esi = esi + 0x19;
                                                                    bool_70 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                    if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                            if (!bool_70) {
                                                                                    if (eax > esi) {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47b26f(0x0);
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    *dword_ba2860 = eax;
                                                                    *dword_ba2864 = edx;
                                                                    sub_465f30(0x4c6ce4);
                                                                    sub_465ff0(&var_1C);
                                                                    sub_465fa0();
                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                    eax = sub_45a9b0(&var_2C);
                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                            break;
                        case 2:
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    if (sub_411740() == 0x1) {
                                            if (sub_45b860() == 0x0) {
                                                    if (*dword_bb65c4 == 0x0) {
                                                            esp = esp - 0x4;
                                                            if (sub_4117d0(0xffffffff) != 0x0) {
                                                                    eax = sub_47b26f(0x0);
                                                                    esi = *dword_ba2858;
                                                                    ecx = *dword_ba285c;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    esi = esi + 0x19;
                                                                    bool_106 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                    if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                            if (!bool_106) {
                                                                                    if (eax > esi) {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47b26f(0x0);
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    *dword_ba2860 = eax;
                                                                    *dword_ba2864 = edx;
                                                                    sub_465f30(0x4c6ce4);
                                                                    sub_465ff0(&var_1C);
                                                                    sub_465fa0();
                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                    eax = sub_45a9b0(&var_2C);
                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                            break;
                        case 3:
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    if (sub_411740() == 0x1) {
                                            if (sub_45b860() == 0x0) {
                                                    if (*dword_bb65c4 == 0x0) {
                                                            esp = esp - 0x4;
                                                            if (sub_4117d0(0xffffffff) != 0x0) {
                                                                    eax = sub_47b26f(0x0);
                                                                    esi = *dword_ba2858;
                                                                    ecx = *dword_ba285c;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    esi = esi + 0x19;
                                                                    bool_137 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                    if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                            if (!bool_137) {
                                                                                    if (eax > esi) {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47b26f(0x0);
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    *dword_ba2860 = eax;
                                                                    *dword_ba2864 = edx;
                                                                    sub_465f30(0x4c6ce4);
                                                                    sub_465ff0(&var_1C);
                                                                    sub_465fa0();
                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                    eax = sub_45a9b0(&var_2C);
                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                            break;
                        case 4:
                            sub_465fa0();
                            *0x0 = var_C;
                            break;
                        default:
                            if (*(int8_t *)byte_baed47 == 0x1) {
                                    if (sub_411740() == 0x1) {
                                            if (sub_45b860() == 0x0) {
                                                    if (*dword_bb65c4 == 0x0) {
                                                            esp = esp - 0x4;
                                                            if (sub_4117d0(0xffffffff) != 0x0) {
                                                                    eax = sub_47b26f(0x0);
                                                                    esi = *dword_ba2858;
                                                                    ecx = *dword_ba285c;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    esi = esi + 0x19;
                                                                    bool_112 = edx > ecx + 0x0 + CARRY(EFLAGS(cf));
                                                                    if (edx >= ecx + 0x0 + CARRY(EFLAGS(cf))) {
                                                                            if (!bool_112) {
                                                                                    if (eax > esi) {
                                                                                            eax = sub_47b26f(0x0);
                                                                                            eax = eax - *dword_ba2880;
                                                                                            edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                            *dword_ba2860 = eax;
                                                                                            *dword_ba2864 = edx;
                                                                                            sub_465f30(0x4c6ce4);
                                                                                            sub_465ff0(&var_1C);
                                                                                            sub_465fa0();
                                                                                            esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                            eax = sub_45a9b0(&var_2C);
                                                                                            *(int8_t *)byte_baed47 = 0x0;
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            sub_465fa0();
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47b26f(0x0);
                                                                                    eax = eax - *dword_ba2880;
                                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                                    *dword_ba2860 = eax;
                                                                                    *dword_ba2864 = edx;
                                                                                    sub_465f30(0x4c6ce4);
                                                                                    sub_465ff0(&var_1C);
                                                                                    sub_465fa0();
                                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                                    eax = sub_45a9b0(&var_2C);
                                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                                    sub_465fa0();
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_465fa0();
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47b26f(0x0);
                                                                    eax = eax - *dword_ba2880;
                                                                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                                                                    *dword_ba2860 = eax;
                                                                    *dword_ba2864 = edx;
                                                                    sub_465f30(0x4c6ce4);
                                                                    sub_465ff0(&var_1C);
                                                                    sub_465fa0();
                                                                    esp = (esp - 0x4) + 0x4 - 0xc;
                                                                    eax = sub_45a9b0(&var_2C);
                                                                    *(int8_t *)byte_baed47 = 0x0;
                                                                    sub_465fa0();
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            sub_465fa0();
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    sub_465fa0();
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            sub_465fa0();
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    sub_465fa0();
                                    *0x0 = var_C;
                            }
                            break;
                    }
            }
            else {
                    sub_465fa0();
                    *0x0 = var_C;
            }
    }
    return;
}
