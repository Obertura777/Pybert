// sub_45cba0 @ 0x45cba0
// hopper name: sub_45cba0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45cba0() {
    decomp_var_c = *0x0;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    esp = esp - 0x24;
    decomp_var_24 = *dword_4c8db8 ^ &decomp_var_20;
    *0x0 = &decomp_var_c;
    esi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            ecx = eax;
            decomp_var_10 = (*(*eax + 0xc))() + 0x10;
            edi = arg_0;
            eax = edi[0x4] & 0xffff;
            eax = eax - 0x1;
            switch (*(eax * 0x4 + switch_table)) {
                case 0:
                    sub_45f990("Connected Message received");
                    esp = (esp - 0x4) + 0x4 - 0x4;
                    decomp_var_28 = edi;
                    ecx = esi;
                    sub_45ab70(decomp_var_28);
                    break;
                case 1:
                    decomp_var_28 = "Unexpected Local Message received";
                    sub_45f990("Unexpected Local Message received");
                    ecx = edi[0x4] & 0xffff;
                    sub_45f930("Unexpected Local message event %d", ecx);
                    esp = (esp - 0xc) + 0xc;
                    break;
                case 2:
                    decomp_var_28 = "Out of Memory Message received";
                    sub_45f990("Out of Memory Message received");
                    sub_45f930("Out of Memory", decomp_var_28);
                    esp = (esp - 0x8) + 0x8;
                    break;
                case 3:
                    decomp_var_28 = edi[0x1];
                    eax = sub_410c10(&decomp_var_10, "Read Error Message received. Error code %d", decomp_var_28);
                    sub_45f990(decomp_var_10);
                    edx = *(*esi + 0xf8);
                    esp = (esp - 0x10) + 0x10;
                    ecx = esi;
                    esi[0x28] = 0x0;
                    (edx)();
                    break;
                case 4:
                    decomp_var_28 = edi[0x1];
                    eax = sub_410c10(&decomp_var_10, "Write Error Message received. Error code %d", decomp_var_28);
                    sub_45f990(decomp_var_10);
                    eax = *(*esi + 0xf8);
                    esp = (esp - 0x10) + 0x10;
                    ecx = esi;
                    esi[0x28] = 0x0;
                    (eax)();
                    break;
                default:
                    decomp_var_28 = "Close Message received";
                    sub_45f990("Close Message received");
                    eax = *(*esi + 0xf8);
                    esp = (esp - 0x4) + 0x4;
                    ecx = esi;
                    esi[0x28] = 0x0;
                    (eax)();
                    break;
                default:
                    decomp_var_28 = "Unexpected Local Message received";
                    sub_45f990("Unexpected Local Message received");
                    ecx = edi[0x4] & 0xffff;
                    sub_45f930("Unexpected Local message event %d", ecx);
                    esp = (esp - 0xc) + 0xc;
            }
            eax = &decomp_var_10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    decomp_var_2c = eax;
                    eax = *(**eax + 0x4);
                    eax = (eax)(decomp_var_2c);
            }
            *0x0 = decomp_var_10;
    }
    return eax;
}
