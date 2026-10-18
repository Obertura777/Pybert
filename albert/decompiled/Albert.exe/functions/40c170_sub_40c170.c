// sub_40c170 @ 0x40c170
// hopper name: sub_40c170
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c170() {
    arg_0 = ebx;
    ebx = arg_8;
    saved_fp = esi;
    esp = esp - 0xc;
    decomp_var_4 = edi;
    edi = ecx;
    edi[0x16] = ebx;
    if ((ebx & 0xffff0000) == 0x0 && edi[0x15] == 0x0) {
            edi[0x15] = ebx & 0xffff;
    }
    esi = *(sub_4715ba() + 0xc);
    ebx = LoadResource(esi, FindResourceA(esi, ebx, 0x5));
    esi = sub_470c1c(ebx, arg_c, esi);
    FreeResource(ebx);
    eax = esi;
    return eax;
}
