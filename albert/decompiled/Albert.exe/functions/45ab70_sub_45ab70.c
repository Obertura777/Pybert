// sub_45ab70 @ 0x45ab70
// hopper name: sub_45ab70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ab70() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    esi = ecx;
    if (edi[0x1] == 0x0) {
            sub_45f990("Connected OK");
    }
    else {
            sub_45f990("Failed to connect to Server");
            sub_4700ea("Failed to connect to Server", 0x0, 0x0);
            sub_45f930("Failed to connect to Server. Error code %d", edi[0x1]);
            eax = *(*esi + 0xf4);
            esi[0x28] = 0x0;
            (eax)();
    }
    return;
}
