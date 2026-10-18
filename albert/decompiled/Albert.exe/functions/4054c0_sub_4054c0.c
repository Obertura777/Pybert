// sub_4054c0 @ 0x4054c0
// hopper name: sub_4054c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4054c0() {
    var_C = *0x0;
    decomp_var_20 = ebx;
    decomp_var_24 = esi;
    decomp_var_28 = edi;
    esp = esp - 0x2c;
    decomp_var_2c = *dword_4c8db8 ^ ebp;
    eax = &var_C;
    *0x0 = eax;
    var_14 = ecx;
    esi = arg_8;
    edi = arg_c;
    ebx = arg_4;
    goto loc_405504;

loc_405504:
    if (esi == 0x0 || esi != arg_10) {
            eax = sub_47a948();
    }
    if (edi != arg_14) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x10;
            esi = sub_401b00(ebx, ebx[0x1], edi + 0x8);
            eax = sub_403ec0(0x1);
            ebx[0x1] = esi;
            *esi[0x1] = esi;
            if (edi == arg_8[0x1]) {
                    eax = sub_47a948();
            }
            edi = *edi;
            esi = arg_8;
            continue;
    }
    break;
    *0x0 = var_C;
    &var_1C = ebp;
    return eax;
}
