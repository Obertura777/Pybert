// sub_48ee89 @ 0x48ee89
// hopper name: sub_48ee89
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48ee89() {
    if (decomp_var_1c != esi) {
            if (decomp_var_20 != esi) {
                    eax = *edi;
                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x4) = *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x4) & 0xfe;
            }
            sub_48e54d(*edi);
    }
    return;
}
