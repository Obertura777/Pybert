// sub_4ac252 @ 0x4ac252
// hopper name: sub_4ac252
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_e41e03f52e8d11a579d3f07a670615b5498a477b1a79ea69d8a397696ef7f69f
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4ac252() {
    esp = esp - 0x4;
    if (InterlockedDecrement() < 0x0) {
            esp = esp - 0x4;
            esi = 0xbc6f78;
            do {
                    sub_493782(saved_fp);
                    esi = esi + 0x18;
                    esp = (esp - 0x4) + 0x4;
            } while (esi < 0xbc6fd8);
    }
    return;
}
