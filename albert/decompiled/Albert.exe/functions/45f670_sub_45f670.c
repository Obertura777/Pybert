// sub_45f670 @ 0x45f670
// hopper name: sub_45f670
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f670() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    eax = *edi;
    esi = ecx;
    ecx = *(int8_t *)eax & 0xff;
    bool_2 = ecx == 0xff;
    if (ecx <= 0xff) {
            if (!bool_2) {
                    switch (*(ecx * 0x4 + switch_table)) {
                        case 0:
                            sub_45f930("Error - Initial message received", decomp_var_8);
                            sub_45f990("Initial Message received");
                            eax = (*(*esi + 0x10))();
                            break;
                        case 1:
                            sub_45d4b0(eax + 0x4, edi[0x1] - 0x4);
                            eax = (*(*esi + 0x10))();
                            break;
                        case 2:
                            sub_45f1f0(eax + 0x4, edi[0x1] - 0x4);
                            eax = (*(*esi + 0x10))();
                            break;
                        case 3:
                            sub_45f990("Final Message received");
                            eax = (*(*esi + 0x10))();
                            break;
                        default:
                            sub_45f990("Error Message received");
                            sub_45f930("Error Message Received. Error Code = %d", *(int16_t *)(*edi + 0x4) & 0xffff);
                            eax = (*(*esi + 0x10))();
                            break;
                        default:
                            sub_45f930("Unexpected Message type - %d", ecx);
                            eax = (*(*esi + 0x10))();
                    }
            }
            else {
                    sub_45cba0();
                    eax = (*(*esi + 0x10))();
            }
    }
    else {
            sub_45f930("Unexpected Message type - %d", ecx);
            eax = (*(*esi + 0x10))();
    }
    return eax;
}
