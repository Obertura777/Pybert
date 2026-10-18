// sub_40b7d0 @ 0x40b7d0
// hopper name: sub_40b7d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b7d0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    ecx = arg_0;
    if (ecx == 0x0) {
            sub_40b5a0(0x80004005);
    }
    else {
            *esi = (*(*ecx + 0xc))() + 0x10;
    }
    return;
}
