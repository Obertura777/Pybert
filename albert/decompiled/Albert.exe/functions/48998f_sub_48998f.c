// sub_48998f @ 0x48998f
// hopper name: sub_48998f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48998f() {
    edx[0x1] = edx[0x1] - 0x1;
    if (edx[0x1] >= 0x0) {
            *edx = *edx + 0x1;
    }
    else {
            sub_48f940(saved_fp);
    }
    return;
}
