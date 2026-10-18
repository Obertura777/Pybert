// sub_40ace0 @ 0x40ace0
// hopper name: sub_40ace0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40ace0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_4c = ebx;
    decomp_var_50 = ebp;
    decomp_var_54 = esi;
    ebx = ecx;
    esi = *ebx[0x947];
    esp = esp - 0x58;
    decomp_var_58 = edi;
    edi = ebx + 0x2518;
    ebp = edi;
    var_40 = ebx;
    var_41 = 0x0;
    var_34 = ebp;
    var_30 = esi;
    goto loc_40ad10;

loc_40ad10:
    var_20 = edi[0x1];
    if (ebp == 0x0 || ebp != edi) {
            sub_47a948();
    }
    if (esi == var_20) goto .l14;
    goto loc_40ad2e;

.l14:
    break;

loc_40ad2e:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi == ret_addr) {
            sub_47a948();
    }
    if (esi[0x6] != 0x0) goto loc_40af78;
    goto loc_40ad4b;
    eax = var_41;
    &decomp_var_48 = decomp_var_50;
    return eax;

loc_40af78:
    sub_401590();
    esi = var_30;
    ebp = var_34;
    goto .l2;

loc_40ad4b:
    if (esi == ret_addr) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_407720(esi + 0xc);
    ebp = eax + 0x24;
    var_3C = eax;
    ebx = *ret_addr;
    var_41 = 0x0;
    edi = ebp;
    goto loc_40ad77;

.l2:
    continue;

loc_40ad77:
    var_18 = ret_addr;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx != var_18) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            edi = ebx[0x2];
            var_38 = edi;
            esi = sub_409640(edi, 0x0, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c);
            esp = esp - 0xc;
            decomp_var_5c = edi;
            if (esi == 0xffffffff) {
                    sub_4093f0(decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50);
            }
            else {
                    sub_4095a0(decomp_var_5c);
                    sub_409250(esi);
                    esp = esp - 0x8;
                    eax = sub_407720(&var_38);
                    eax[0x5a] = 0x1;
                    eax[0x14] = esi;
                    var_41 = 0x1;
            }
            edi = ebp;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            ebx = *ebx;
            esi = var_30;
            continue;
    }
    break;
    if (var_41 != 0x1) goto loc_40aed2;
    goto loc_40ae1b;

loc_40aed2:
    edi = var_40;
    sub_4095a0(var_3C[0x5]);
    var_2C = var_3C[0x5];
    esp = esp - 0xc;
    var_28 = *var_3C;
    eax = sub_405120(&var_C, &var_2C, decomp_var_58);
    goto loc_40af0b;

loc_40ae1b:
    edi = *ret_addr;
    esi = ebp;
    goto loc_40ae22;

loc_40af0b:
    ebp = var_34;
    if (esi == ret_addr) {
            sub_47a948();
    }
    ebx = esi + 0x10;
    if (esi[0x4] != 0xffffffff) {
            if (esi == ret_addr) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_405c60(ebx);
            eax[0x1] = eax[0x1] - 0x1;
            if (eax[0x1] == 0x0) {
                    eax[0x2] = 0x0;
            }
    }
    edi = edi + 0x2518;
    esp = esp - 0xc;
    eax = sub_403170(&var_14, ebp, esi, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, var_40, var_3C, var_38, var_34, var_30, var_2C, var_28, decomp_var_24, var_20);
    ecx = *eax;
    edx = eax[0x1];
    ebx = var_40;
    var_34 = ecx;
    var_30 = edx;
    var_41 = 0x1;
    esi = edx;
    ebp = ecx;
    goto .l2;

loc_40ae22:
    ebx = ret_addr;
    if (esi == 0x0 || esi != ebp) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            *(sub_407720(edi + 0x8) + 0x30) = 0x1;
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi = *edi;
            continue;
    }
    break;
    ebx = var_3C;
    ebx[0xc] = 0x9;
    ebx[0x56] = 0x1;
    ebp = *(ebx[0xe] + 0x4);
    edi = ebx + 0x34;
    esi = ebp;
    if (arg_9 == 0x0) {
            do {
                    sub_401950(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = esi;
            } while (esi[0x11] == 0x0);
    }
    eax = edi[0x1];
    esi = var_30;
    eax[0x1] = eax;
    eax = edi[0x1];
    edi[0x2] = 0x0;
    *eax = eax;
    edi = edi[0x1];
    edi[0x2] = edi;
    edi = var_40;
    ebx[0x10] = 0x0;
    goto loc_40af0b;
}
