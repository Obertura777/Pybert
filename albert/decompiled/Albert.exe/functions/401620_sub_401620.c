// sub_401620 @ 0x401620
// hopper name: sub_401620
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401620() {
    ecx = arg_0;
    esp = esp - 0xc;
    if (ecx <= 0x0) {
            sub_46dbce(0x0);
    }
    else {
            if ((eax | 0xffffffff) / ecx < 0x1) {
                    arg_0 = 0x0;
                    sub_47a696(&arg_0);
                    var_C = 0x4af464;
                    sub_47a958(&var_C, 0x4bb630);
                    asm { int3 };
            }
            else {
                    sub_46dbce(ecx);
            }
    }
    return;
}
