// sub_40b6e0 @ 0x40b6e0
// hopper name: sub_40b6e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b6e0() {
    decomp_var_8 = ebx;
    decomp_var_10 = esi;
    esi = *ecx;
    ebx = *(esi - 0xc);
    esi = esi - 0x10;
    var_4 = ecx;
    eax = (*(**esi + 0x10))(edi, decomp_var_10, ebp, decomp_var_8, var_4);
    ebp = arg_10;
    esp = esp - 0x1c;
    edi = (**eax)(ebp, 0x1);
    if (edi == 0x0) {
            sub_40b6d0();
    }
    ebp = edi + 0x10;
    eax = sub_47a5af(ebp, &arg_fffffffffffffffd, esi + 0x10, &arg_fffffffffffffffd);
    esp = (esp - 0x10) + 0x10;
    edi[0x1] = ebx;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], eax | 0xffffffff);
    eax = eax - 0x1;
    if (eax <= 0x0) {
            eax = *(**esi + 0x4);
            esp = esp - 0x4;
            eax = (eax)(esi);
    }
    *arg_8 = ebp;
    return eax;
}
