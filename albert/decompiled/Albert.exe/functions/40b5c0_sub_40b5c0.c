// sub_40b5c0 @ 0x40b5c0
// hopper name: sub_40b5c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b5c0() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = edi;
    edi = arg_4;
    decomp_var_c = edi;
    esp = esp - 0x10;
    eax = LoadResource(ebx, decomp_var_c);
    if (eax != 0x0) goto loc_40b5d9;
    goto .l1;

loc_40b5d9:
    esp = esp - 0x8;
    esi = LockResource(eax);
    if (esi == 0x0) goto .l1;
    goto loc_40b5e7;

.l1:
    return;

loc_40b5e7:
    esp = esp - 0x8;
    eax = SizeofResource(ebx, edi);
    eax = eax + esi;
    ecx = arg_8 & 0xf;
    if (ecx <= 0x0) goto loc_40b610;
    goto loc_40b5fa;

loc_40b610:
    if (esi < eax) goto .l1;
    goto .l1;

loc_40b5fa:
    while (true) {
            if (esi >= eax) {
                    temp_0 = 0x0;
                    break;
            }
            ecx = ecx - 0x1;
            esi = esi + (*(int16_t *)esi & 0xffff) * 0x2 + 0x2;
            if (ecx != 0x0) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0 || esi >= eax) goto .l1;
}
