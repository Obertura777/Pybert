// sub_42e120 @ 0x42e120
// hopper name: sub_42e120
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42e120() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esi = ecx;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = arg_0;
    *esi = *edi;
    esi[0x1] = edi[0x1];
    esi[0x2] = edi[0x2];
    esi[0x6] = edi[0x6];
    esi[0x4] = edi[0x4];
    esi[0x5] = edi[0x5];
    esi[0x6] = edi[0x6];
    esi[0x7] = edi[0x7];
    eax = edi + 0x24;
    esi[0x8] = edi[0x8];
    if (esi + 0x24 != eax) {
            edx = eax[0x1];
            esp = esp - 0x14;
            sub_4226e0(eax, *edx, eax, edx);
    }
    ebp = edi + 0x34;
    ebx = esi + 0x34;
    esi[0xc] = edi[0xc];
    if (ebx != ebp) {
            eax = ebx[0x1];
            eax = sub_403430(&var_8, ebx, *eax, ebx, eax);
            esp = esp - 0x18;
            sub_402210(ebp);
    }
    esi[0x10] = edi[0x10];
    esi[0x44] = edi[0x44] & 0xff;
    esi[0x12] = edi[0x12];
    esi[0x13] = edi[0x13];
    esi[0x14] = edi[0x14];
    esi[0x54] = edi[0x54] & 0xff;
    esi[0x55] = edi[0x55] & 0xff;
    esi[0x56] = edi[0x56] & 0xff;
    esi[0x57] = edi[0x57] & 0xff;
    esi[0x58] = edi[0x58] & 0xff;
    esi[0x59] = edi[0x59] & 0xff;
    esi[0x5a] = edi[0x5a] & 0xff;
    esi[0x5b] = edi[0x5b] & 0xff;
    esi[0x5c] = edi[0x5c] & 0xff;
    ecx = edi[0x2f];
    ebx = edi + 0x60;
    edi = esi + 0x60;
    esi[0x2f] = ecx;
    if (edi != ebx) {
            eax = edi[0x1];
            sub_405260(&var_8, edi, *eax, edi, eax);
            esp = esp - 0x18;
            sub_402930(ebx);
    }
    eax = esi;
    return eax;
}
