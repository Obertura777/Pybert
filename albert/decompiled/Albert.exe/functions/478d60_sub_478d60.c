// sub_478d60 @ 0x478d60
// hopper name: sub_478d60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478d60() {
    ebx = arg_0;
    bool_1 = ebx[0x1] == 0xffff;
    bool_0 = ebx[0x1] == 0xffff;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    arg_0 = bool_1 ? 0x1 : 0x0;
    esi = sub_478d15(ebx);
    sub_478cea(ebx);
    esp = (esp - 0x10) + 0x8;
    if (!bool_0) {
            esp = (esp - 0x4) + 0x4;
            esi = esi + ((arg_0 != 0x0 ? 0x1 : 0x0) + (arg_0 != 0x0 ? 0x1 : 0x0) + 0x1) * 0x2 + sub_47d60b(esi + ((arg_0 != 0x0 ? 0x1 : 0x0) + (arg_0 != 0x0 ? 0x1 : 0x0) + 0x1) * 0x2) * 0x2 + 0x2;
    }
    if (arg_0 != 0x0) {
            edi = ebx[0x8] & 0xffff;
    }
    else {
            edi = ebx[0x4] & 0xffff;
    }
    if (edi <= 0x0) goto loc_478e21;
    goto loc_478dba;

loc_478e21:
    eax = esi - ebx;
    return eax;

loc_478dba:
    edx = (-arg_0 - -arg_0 + CARRY(EFLAGS(cf)) & 0x6) + 0x12;
    goto loc_478dc7;

loc_478dc7:
    eax = (esi + 0x3 & 0xfffffffc) + edx;
    if (*(int16_t *)eax == 0xffff) {
            eax = eax + 0x4;
    }
    else {
            ecx = *(int16_t *)eax;
            eax = eax + 0x2;
            if (ecx != 0x0) {
                    continue;
            }
            break;
    }
    if (*(int16_t *)eax == 0xffff) {
            eax = eax + 0x4;
    }
    else {
            do {
                    ecx = *(int16_t *)eax;
                    eax = eax + 0x2;
            } while (ecx != 0x0);
    }
    ecx = *(int16_t *)eax & 0xffff;
    if (ecx != 0x0 && arg_0 == 0x0) {
            ecx = ecx + 0xfffe;
    }
    edi = edi + 0xffff;
    esi = eax + (ecx & 0xffff) + 0x2;
    if (edi > 0x0) {
            continue;
    }
    break;
}
