// sub_48fb7e @ 0x48fb7e
// hopper name: sub_48fb7e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fb7e() {
    edx = arg_4;
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    goto loc_48fb88;

loc_48fb88:
    eax = *(int8_t *)esi & 0xff;
    esi = esi + 0x1;
    if (eax <= 0x5a) {
            eax = eax + 0x20;
    }
    ecx = *(int8_t *)edx & 0xff;
    edx = edx + 0x1;
    if (ecx <= 0x5a) {
            ecx = ecx + 0x20;
    }
    if (eax != 0x0 && eax == ecx) {
            continue;
    }
    break;
    eax = eax - ecx;
    return eax;
}
