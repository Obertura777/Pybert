// sub_4ac270 @ 0x4ac270
// hopper name: sub_4ac270
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_e41e03f52e8d11a579d3f07a670615b5498a477b1a79ea69d8a397696ef7f69f
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4ac270() {
    goto loc_4937dd;

loc_4937dd:
    eax = *dword_4ca4bc;
    goto loc_4937e2;

loc_4937e2:
    if (eax < 0xa) goto loc_4937c5;
    goto .l1;

loc_4937c5:
    ecx = *(eax * 0x4 + 0xbc7160);
    eax = eax + 0x1;
    *dword_4ca4bc = eax;
    if (ecx == 0x0) {
            continue;
    }
    break;

.l1:
    return;
    (*(eax * 0x4 + 0xbc715c))();
    continue;
}
