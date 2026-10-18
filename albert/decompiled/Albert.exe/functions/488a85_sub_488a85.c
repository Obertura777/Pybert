// sub_488a85 @ 0x488a85
// hopper name: sub_488a85
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488a85() {
    esp = (esp - 0x4) + 0x4;
    if (sub_48f60c(0x3) != 0x1) {
            esp = (esp - 0x4) + 0x4;
            if (sub_48f60c(0x3) == 0x0 && *dword_4c8e20 == 0x1) {
                    sub_4888e5(0xfc);
                    sub_4888e5(0xff);
            }
    }
    else {
            sub_4888e5(0xfc);
            sub_4888e5(0xff);
    }
    return;
}
