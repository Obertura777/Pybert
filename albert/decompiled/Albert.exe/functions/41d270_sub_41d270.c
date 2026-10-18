// sub_41d270 @ 0x41d270
// hopper name: sub_41d270
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41d270() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_20 = ebx;
    decomp_var_24 = esi;
    esi = ecx + 0x4cfc;
    decomp_var_28 = edi;
    esp = esp - 0x2c;
    sub_4019f0(*(ecx[0x1340] + 0x4));
    eax = esi[0x1];
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    eax = esi[0x1];
    eax[0x2] = eax;
    eax = arg_0;
    ebx = eax;
    var_1C = ebx;
    var_18 = *eax[0x1];
    goto loc_41d2c0;

loc_41d2c0:
    edi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            eax = sub_47a948();
    }
    if (var_18 != edi) {
            ecx = sub_47b678();
            edi = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x7c17 + 0x1f4;
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_18 == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            var_14 = edi;
            eax = sub_419790(&var_C, &var_14, decomp_var_28);
            sub_401520();
            ebx = var_1C;
            eax = arg_0;
            continue;
    }
    break;
    &var_1C = ebp;
    return eax;
}
