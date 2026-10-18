// sub_48501e @ 0x48501e
// hopper name: sub_48501e
// contains unmarked entry 0x4850b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48501e() {
    esi = arg_4;
    arg_4 = sub_4867ae(esi);
    eax = esi[0x3];
    esp = (esp - 0x4) + 0x4;
    if ((eax & 0x82) == 0x0) {
            eax = sub_47d812();
            *eax = 0x9;
            esi[0x3] = esi[0x3] | 0x20;
            eax = eax | 0xffffffff;
    }
    else {
            if ((eax & 0x40) != 0x0) {
                    eax = sub_47d812();
                    *eax = 0x22;
                    esi[0x3] = esi[0x3] | 0x20;
                    eax = eax | 0xffffffff;
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_c = ebx;
                    if ((eax & 0x1) != 0x0) {
                            esi[0x1] = 0x0;
                            if ((eax & 0x10) != 0x0) {
                                    *esi = esi[0x2];
                                    esi[0x3] = eax & 0xfffffffe;
                                    eax = esi[0x3];
                                    esi[0x3] = eax & 0xffffffef | 0x2;
                                    esi[0x1] = 0x0;
                                    var_4 = 0x0;
                                    if (((eax & 0xffffffef | 0x2) & 0x10c) == 0x0) {
                                            if (esi != sub_486807() + 0x20) {
                                                    if (esi == sub_486807() + 0x40) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_48e150(arg_4) == 0x0) {
                                                                    sub_48e10c(esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            sub_48e10c(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_48e150(arg_4) == 0x0) {
                                                            sub_48e10c(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_10 = edi;
                                    if ((esi[0x6] & 0x108) != 0x0) {
                                            ebx = 0x0;
                                            eax = esi[0x2];
                                            edi = *esi;
                                            *esi = eax + 0x1;
                                            edi = edi - eax;
                                            esi[0x1] = esi[0x6] - 0x1;
                                            if (edi > 0x0) {
                                                    esp = (esp - 0xc) + 0xc;
                                                    var_4 = sub_4878d3();
                                                    eax = esi[0x2];
                                                    *(int8_t *)eax = arg_0;
                                                    if (var_4 != edi) {
                                                            esi[0x3] = esi[0x3] | 0x20;
                                                            eax = eax | 0xffffffff;
                                                    }
                                                    else {
                                                            eax = arg_0 & 0xff;
                                                    }
                                                    esp = esp + 0x4;
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    ecx = arg_4;
                                                    if (ecx != 0xffffffff && ecx != 0xfffffffe) {
                                                            edx = SAR(ecx, 0x5);
                                                            eax = (ecx & 0x1f) * 0x28 + *(edx * 0x4 + dword_bc7240);
                                                    }
                                                    else {
                                                            eax = 0x4c9958;
                                                    }
                                                    if ((eax[0x4] & 0x20) != 0x0) {
                                                            eax = sub_48dff3();
                                                            eax = eax & edx;
                                                            esp = (esp - 0x10) + 0x10;
                                                            if (eax != 0xffffffff) {
                                                                    eax = esi[0x2];
                                                                    *(int8_t *)eax = arg_0;
                                                                    if (var_4 != edi) {
                                                                            esi[0x3] = esi[0x3] | 0x20;
                                                                            eax = eax | 0xffffffff;
                                                                    }
                                                                    else {
                                                                            eax = arg_0 & 0xff;
                                                                    }
                                                                    esp = esp + 0x4;
                                                                    esp = esp + 0x4;
                                                            }
                                                            else {
                                                                    esi[0x3] = esi[0x3] | 0x20;
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x4;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = esi[0x2];
                                                            *(int8_t *)eax = arg_0;
                                                            if (var_4 != edi) {
                                                                    esi[0x3] = esi[0x3] | 0x20;
                                                                    eax = eax | 0xffffffff;
                                                            }
                                                            else {
                                                                    eax = arg_0 & 0xff;
                                                            }
                                                            esp = esp + 0x4;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_4878d3();
                                            esp = (esp - 0xc) + 0xc;
                                            var_4 = eax;
                                            if (var_4 != 0x1) {
                                                    esi[0x3] = esi[0x3] | 0x20;
                                                    eax = eax | 0xffffffff;
                                            }
                                            else {
                                                    eax = arg_0 & 0xff;
                                            }
                                            esp = esp + 0x4;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esi[0x3] = eax | 0x20;
                                    eax = eax | 0x20 | 0xffffffff;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            eax = esi[0x3];
                            esi[0x3] = eax & 0xffffffef | 0x2;
                            esi[0x1] = 0x0;
                            var_4 = 0x0;
                            if (((eax & 0xffffffef | 0x2) & 0x10c) == 0x0) {
                                    if (esi != sub_486807() + 0x20) {
                                            if (esi == sub_486807() + 0x40) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_48e150(arg_4) == 0x0) {
                                                            sub_48e10c(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                            else {
                                                    sub_48e10c(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_48e150(arg_4) == 0x0) {
                                                    sub_48e10c(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                            }
                            esp = esp - 0x4;
                            decomp_var_10 = edi;
                            if ((esi[0x6] & 0x108) != 0x0) {
                                    ebx = 0x0;
                                    eax = esi[0x2];
                                    edi = *esi;
                                    *esi = eax + 0x1;
                                    edi = edi - eax;
                                    esi[0x1] = esi[0x6] - 0x1;
                                    if (edi > 0x0) {
                                            esp = (esp - 0xc) + 0xc;
                                            var_4 = sub_4878d3();
                                            eax = esi[0x2];
                                            *(int8_t *)eax = arg_0;
                                            if (var_4 != edi) {
                                                    esi[0x3] = esi[0x3] | 0x20;
                                                    eax = eax | 0xffffffff;
                                            }
                                            else {
                                                    eax = arg_0 & 0xff;
                                            }
                                            esp = esp + 0x4;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            ecx = arg_4;
                                            if (ecx != 0xffffffff && ecx != 0xfffffffe) {
                                                    edx = SAR(ecx, 0x5);
                                                    eax = (ecx & 0x1f) * 0x28 + *(edx * 0x4 + dword_bc7240);
                                            }
                                            else {
                                                    eax = 0x4c9958;
                                            }
                                            if ((eax[0x4] & 0x20) != 0x0) {
                                                    eax = sub_48dff3();
                                                    eax = eax & edx;
                                                    esp = (esp - 0x10) + 0x10;
                                                    if (eax != 0xffffffff) {
                                                            eax = esi[0x2];
                                                            *(int8_t *)eax = arg_0;
                                                            if (var_4 != edi) {
                                                                    esi[0x3] = esi[0x3] | 0x20;
                                                                    eax = eax | 0xffffffff;
                                                            }
                                                            else {
                                                                    eax = arg_0 & 0xff;
                                                            }
                                                            esp = esp + 0x4;
                                                            esp = esp + 0x4;
                                                    }
                                                    else {
                                                            esi[0x3] = esi[0x3] | 0x20;
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x4;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = esi[0x2];
                                                    *(int8_t *)eax = arg_0;
                                                    if (var_4 != edi) {
                                                            esi[0x3] = esi[0x3] | 0x20;
                                                            eax = eax | 0xffffffff;
                                                    }
                                                    else {
                                                            eax = arg_0 & 0xff;
                                                    }
                                                    esp = esp + 0x4;
                                                    esp = esp + 0x4;
                                            }
                                    }
                            }
                            else {
                                    eax = sub_4878d3();
                                    esp = (esp - 0xc) + 0xc;
                                    var_4 = eax;
                                    if (var_4 != 0x1) {
                                            esi[0x3] = esi[0x3] | 0x20;
                                            eax = eax | 0xffffffff;
                                    }
                                    else {
                                            eax = arg_0 & 0xff;
                                    }
                                    esp = esp + 0x4;
                                    esp = esp + 0x4;
                            }
                    }
            }
    }
    return eax;
}
