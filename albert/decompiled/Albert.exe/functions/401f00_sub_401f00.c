// sub_401f00 @ 0x401f00
// hopper name: sub_401f00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401f00() {
    decomp_var_4 = ebx;
    ebx = arg_c;
    decomp_var_8 = esi;
    esi = arg_10;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_8;
    goto loc_401f10;

loc_401f10:
    eax = arg_0;
    if (eax == 0x0 || eax != edi) {
            eax = sub_47a948();
    }
    if (arg_4 != ebx) {
            *esi = *esi + 0x1;
            sub_401520();
            continue;
    }
    break;
    return eax;
}
