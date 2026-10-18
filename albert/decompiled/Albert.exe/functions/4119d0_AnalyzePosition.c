// AnalyzePosition @ 0x4119d0
// hopper name: sub_4119d0
// pybert name: AnalyzePosition
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

AnalyzePosition() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = ecx;
    eax = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            do {
                    *(eax * 0x4 + 0x62e460) = 0x0;
                    eax = eax + 0x1;
            } while (eax < *(edi[0x2] + 0x2404));
    }
    eax = edi[0x2];
    ebp = *eax[0x915];
    esi = eax + 0x2450;
    var_8 = esi;
    var_4 = ebp;
    goto loc_411a20;

loc_411a20:
    eax = edi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (ebp != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            *(arg_14 * 0x4 + 0x62e460) = *(arg_14 * 0x4 + 0x62e460) + 0x1;
            sub_401390();
            ebp = var_4;
            esi = var_8;
            continue;
    }
    break;
    return eax;
}
