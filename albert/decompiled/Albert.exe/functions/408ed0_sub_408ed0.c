// sub_408ed0 @ 0x408ed0
// hopper name: sub_408ed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_408ed0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    eax = *arg_24E4;
    eax = sub_408f00(edi, esi, ebp, ebx, decomp_var_50, decomp_var_4c, ecx, decomp_var_44, &arg_24E0, eax, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c);
    return eax;
}
