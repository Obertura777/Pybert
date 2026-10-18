// sub_40be30 @ 0x40be30
// hopper name: sub_40be30
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40be30() {
    decomp_var_6c = esi;
    esi = ecx;
    esp = esp - 0x70;
    if (IsIconic(esi[0x8]) != 0x0) {
            sub_476f3f(esi, edi, ebx);
            SendMessageA(esi[0x8], 0x27, var_50, 0x0);
            ebx = GetSystemMetrics(0xb);
            edi = GetSystemMetrics(0xc);
            GetClientRect(esi[0x8], &var_64);
            DrawIcon(var_50, SAR((var_5C - var_64 - ebx) + 0x1 - ((var_5C - var_64 - ebx) + 0x1 & 0x80000000 ? 0xffffffff : 0x0), 0x1), SAR((var_58 - var_60 - edi) + 0x1 - ((var_58 - var_60 - edi) + 0x1 & 0x80000000 ? 0xffffffff : 0x0), 0x1), esi[0x32]);
            sub_476f93();
            eax = sub_47ad69();
    }
    else {
            sub_47032d();
            eax = sub_47ad69();
    }
    return eax;
}
