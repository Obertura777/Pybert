// sub_45a9b0 @ 0x45a9b0
// hopper name: sub_45a9b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45a9b0() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    sub_45fa10(0x0, ebx);
    esp = (esp - 0x10) + 0x8;
    if (ecx[0x28] != 0x0) {
            edi = sub_4658d0();
            esi = sub_46dbce(edi + edi + 0x6);
            esi[0x1] = edi + edi;
            *(int8_t *)esi = 0x2;
            sub_465890(esi + 0x4, edi + 0x1);
            esp = ((esp - 0x8) + 0x4 - 0x10) + 0xc;
            if (dcsp_client_send_message(esi, edi + edi + 0x4) == 0x0) {
                    sub_45f930("Failed to send message", saved_fp);
                    esp = (esp - 0x4) + 0x4;
            }
            sub_47c8f9();
    }
    else {
            sub_45f990("Message not sent - not connected");
    }
    return;
}
