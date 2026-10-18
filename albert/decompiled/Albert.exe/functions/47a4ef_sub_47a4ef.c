// sub_47a4ef @ 0x47a4ef
// hopper name: sub_47a4ef
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a4ef() {
    edi = arg_4;
    esi = ecx;
    if (edi < 0x0) {
            sub_46dedc();
    }
    ebx = arg_c;
    if (ebx <= 0x0) {
            sub_46dedc();
    }
    esp = esp - 0x4;
    decomp_var_14 = 0xffffffff;
    if (edi >= esi[0x2]) {
            esp = esp - 0x4;
            decomp_var_18 = edi + ebx;
            sub_47a3cb();
    }
    else {
            edi = esi[0x2];
            decomp_var_18 = edi + ebx;
            sub_47a3cb();
            ecx = esi[0x1];
            sub_478599(ecx + (arg_4 + ebx) * 0x4, esi[0x2] - arg_4 - ebx << 0x2, ecx + arg_4 * 0x4, edi - arg_4 << 0x2);
            sub_47ba40(esi[0x1] + (arg_4 << 0x2), 0x0, ebx << 0x2);
            edi = arg_4;
            esp = (esp - 0x20) + 0x1c;
    }
    eax = edi << 0x2;
    do {
            ebx = ebx - 0x1;
            *(eax + esi[0x1]) = arg_8;
            eax = eax + 0x4;
    } while (ebx != 0x0);
    return;
}
