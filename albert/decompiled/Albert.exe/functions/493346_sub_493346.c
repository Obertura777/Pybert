// sub_493346 @ 0x493346
// hopper name: sub_493346
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493346() {
    if (*dword_bc6fdc == 0x0) {
            sub_4937a3(sub_493303);
            esp = (esp - 0x4) + 0x4;
    }
    eax = sub_46dbce(0x8);
    if (eax != 0x0) {
            *eax = *dword_bc6fdc;
            eax[0x1] = arg_0;
    }
    else {
            eax = 0x0;
    }
    *dword_bc6fdc = eax;
    return;
}
