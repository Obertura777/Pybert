// sub_4726b6 @ 0x4726b6
// hopper name: sub_4726b6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4726b6() {
    if (decomp_var_24 != 0x2) {
            esi = decomp_var_1c == ebx ? 0x1 : 0x0;
            if (decomp_var_1c != ebx) {
                    edi = GetLastError();
            }
            else {
                    edi = 0x0;
            }
            esp = esp - 0x8;
            sub_470ddd();
            if (esi != ebx) {
                    SetLastError(edi);
            }
    }
    return;
}
