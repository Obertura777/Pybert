// sub_44b760 @ 0x44b760
// hopper name: sub_44b760
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44b760() {
    edi = ecx;
    sub_45abe0();
    ebx = arg_8;
    esi = edi + (ebx + ebx * 0x4) * 0x4;
    edi[0xa84] = *(edi + (ebx + ebx * 0x4) * 0x4 + 0x218);
    var_20 = edi + (ebx + ebx * 0x4 + 0x87) * 0x4;
    edi[0xa85] = *(edi + (ebx + ebx * 0x4 + 0x87) * 0x4);
    edi[0xa86] = esi[0x88];
    sub_461560(arg_4, ebx, esi[0x85], edi + 0x2a10, decomp_var_30);
    eax = sub_41c340(&arg_8);
    *eax = arg_4;
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaedac) = arg_c;
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaeda0) = 0x6;
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaeda8) = ebx;
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaedfc) = esi[0x85];
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaee08) = esi[0x86];
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaee0c) = *var_20;
    *(((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + 0xbaee10) = esi[0x88];
    esp = (esp - 0x38) + 0x8 - 0x18;
    eax = sub_41c1e0(&arg_8);
    ebp = arg_4;
    if (esi[0x85] > 0x0) {
            sub_460880(esi[0x86], ebp, ebx);
            eax = esi[0x86];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) = 0x5;
            eax = esi[0x86];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda4) = ebp;
            ecx = esi[0x86];
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaeda8) = ebx;
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaedac) = arg_c;
            eax = esi[0x86];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) = 0x1;
            edx = esi[0x86];
            ecx = (edx << 0x4) - edx;
            eax = (arg_0 << 0x8) + edx;
            edx = *(eax * 0x8 + 0x55b0e8);
            eax = *(eax * 0x8 + 0x55b0ec);
            *(ecx * 0x8 + 0xbaedb8) = edx;
            *(ecx * 0x8 + 0xbaedbc) = eax;
            esp = esp - 0x14;
            sub_437510(arg_0, esi[0x86]);
    }
    if (esi[0x85] > 0x1) {
            sub_460880(*var_20, ebp, ebx);
            eax = *var_20;
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) = 0x5;
            eax = *var_20;
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda4) = arg_4;
            ecx = *var_20;
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaeda8) = ebx;
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaedac) = arg_c;
            eax = *var_20;
            *(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) = 0x1;
            edx = *var_20;
            ecx = (edx << 0x4) - edx;
            eax = (arg_0 << 0x8) + edx;
            edx = *(eax * 0x8 + 0x55b0e8);
            eax = *(eax * 0x8 + 0x55b0ec);
            *(ecx * 0x8 + 0xbaedb8) = edx;
            *(ecx * 0x8 + 0xbaedbc) = eax;
            esp = esp - 0x14;
            sub_437510(arg_0, *var_20);
            ebp = arg_4;
    }
    if (esi[0x85] > 0x2) {
            sub_460880(esi[0x88], ebp, ebx);
            eax = esi[0x88];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) = 0x5;
            eax = esi[0x88];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaeda4) = ebp;
            ecx = esi[0x88];
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaeda8) = ebx;
            *(((ecx << 0x4) - ecx) * 0x8 + 0xbaedac) = arg_c;
            eax = esi[0x88];
            *(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) = 0x1;
            edx = esi[0x88];
            ecx = (edx << 0x4) - edx;
            eax = (arg_0 << 0x8) + edx;
            edx = *(eax * 0x8 + 0x55b0e8);
            eax = *(eax * 0x8 + 0x55b0ec);
            *(ecx * 0x8 + 0xbaedb8) = edx;
            *(ecx * 0x8 + 0xbaedbc) = eax;
            esp = esp - 0x14;
            sub_437510(arg_0, esi[0x88]);
    }
    var_1C = 0x4;
    goto loc_44bad0;

loc_44bad0:
    eax = edi + 0x4cfc;
    ebp = *edi[0x1340];
    var_8 = eax;
    var_4 = ebp;
    goto loc_44baf0;

loc_44baf0:
    ecx = edi + 0x4cfc;
    arg_10 = edi[0x1340];
    if (eax == 0x0 || eax != ecx) {
            sub_47a948();
            eax = arg_4;
    }
    if (ebp != arg_10) {
            if (eax == 0x0) {
                    sub_47a948();
                    eax = arg_4;
            }
            if (ebp == eax[0x1]) {
                    sub_47a948();
                    eax = arg_4;
            }
            if (arg_c != esi[0x86]) {
                    if (ebp == eax[0x1]) {
                            sub_47a948();
                            eax = arg_4;
                    }
                    if (arg_c != *saved_fp) {
                            if (ebp == eax[0x1]) {
                                    sub_47a948();
                                    eax = arg_4;
                            }
                            if (arg_c != esi[0x88]) {
                                    sub_40f400();
                                    ebp = arg_8;
                                    eax = arg_4;
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    else {
                            temp_0 = 0x0;
                            break;
                    }
            }
            else {
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x2;
            break;
    }
    goto .l3;

.l3:
    if (temp_0 != 0x0) {
            if (temp_0 != 0x1) {
                    arg_0 = arg_0 - 0x1;
                    if (arg_0 != 0x0) {
                            continue;
                    }
                    break;
            }
            else {
                    esp = esp - 0xc;
                    var_1C = &arg_14;
                    sub_411cf0(var_1C, eax, ebp, decomp_var_10, decomp_var_c, var_8, var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24);
                    arg_0 = arg_0 - 0x1;
                    if (arg_0 != 0x0) {
                            continue;
                    }
                    break;
            }
    }
    else {
            esp = esp - 0xc;
            var_1C = &arg_14;
            sub_411cf0(var_1C, eax, ebp, decomp_var_10, decomp_var_c, var_8, var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24);
            arg_0 = arg_0 - 0x1;
            if (arg_0 != 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l2:
    var_1C = ebx;
    eax = sub_4412c0(arg_20, arg_24, var_1C, decomp_var_18, 0x1, decomp_var_10, decomp_var_c, var_8, var_4, saved_fp);
    return eax;
}
