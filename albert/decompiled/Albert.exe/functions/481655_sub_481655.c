// sub_481655 @ 0x481655
// hopper name: sub_481655
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481655() {
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    sub_47aea2(0x0);
    *dword_bc6850 = 0x0;
    if (esi == 0xfffffffe) {
            *dword_bc6850 = 0x1;
            GetOEMCP();
            if (var_4 != 0x0) {
                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
            }
    }
    else {
            if (esi == 0xfffffffd) {
                    *dword_bc6850 = 0x1;
                    GetACP();
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    if (esi == 0xfffffffc) {
                            *dword_bc6850 = 0x1;
                            if (var_4 != 0x0) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            if (var_4 != 0x0) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                    }
            }
    }
    return;
}
