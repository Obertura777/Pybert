// sub_492c14 @ 0x492c14
// hopper name: sub_492c14
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492c14() {
    edx = (arg_0 & 0x1f) * 0x28;
    decomp_var_4 = ebx;
    ebx = arg_4;
    decomp_var_8 = esi;
    esi = (SAR(arg_0, 0x5)) * 0x4 + dword_bc7240;
    ecx = *esi + edx;
    arg_0 = ecx[0x4] & 0xff & 0x80;
    eax = ecx[0x24];
    esp = esp - 0xc;
    decomp_var_c = edi;
    eax = SAR(sign_extend_32(eax + eax), 0x1);
    switch (ebx) {
        case 16384:
            ecx[0x4] = ecx[0x4] | 0x80;
            ecx = *esi;
            *(int8_t *)(ecx + edx + 0x24) = *(int8_t *)(ecx + edx + 0x24) & 0x80;
            break;
        case 32768:
            ecx[0x4] = ecx[0x4] & 0x7f;
            break;
        case 65536:
            ecx[0x4] = ecx[0x4] | 0x80;
            ecx = *esi;
            ecx = ecx + edx + 0x24;
            edx = *(int8_t *)ecx;
            edx = edx & 0x82 | 0x2;
            *(int8_t *)ecx = edx;
            break;
        case 131072:
            ecx[0x4] = ecx[0x4] | 0x80;
            ecx = *esi;
            ecx = ecx + edx + 0x24;
            edx = *(int8_t *)ecx;
            edx = edx & 0x82 | 0x2;
            *(int8_t *)ecx = edx;
            break;
        case 262144:
            ecx[0x4] = ecx[0x4] | 0x80;
            ecx = *esi;
            ecx = ecx + edx + 0x24;
            edx = *(int8_t *)ecx;
            edx = edx & 0x81 | 0x1;
            *(int8_t *)ecx = edx;
            break;
    }
    if (arg_0 == 0x0) {
            eax = 0x8000;
    }
    else {
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xc000) + 0x4000;
    }
    return eax;
}
