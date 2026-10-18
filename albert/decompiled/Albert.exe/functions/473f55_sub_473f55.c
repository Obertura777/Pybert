// sub_473f55 @ 0x473f55
// hopper name: sub_473f55
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473f55() {
    esi = ecx;
    if (esi[0x24] == 0x0) {
            sub_473a4a();
    }
    else {
            eax = *esi;
            var_4 = var_4 & 0x0;
            esp = esp - 0xc;
            eax = (eax[0x39])(arg_0, arg_4, &var_4);
            if (eax < 0x0) {
                    sub_473a4a();
            }
    }
    return;
}
