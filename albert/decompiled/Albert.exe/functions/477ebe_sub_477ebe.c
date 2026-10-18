// sub_477ebe @ 0x477ebe
// hopper name: sub_477ebe
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477ebe() {
    eax = ClientToScreen(arg_0, &arg_4);
    esp = esp - 0x18;
    while (true) {
            esi = GetWindow(decomp_var_c, decomp_var_8);
            if (esi == 0x0) {
                    break;
            }
            esp = esp - 0x4;
            if (GetDlgCtrlID(esi) == 0x0) {
                    esp = esp - 0x8;
                    continue;
            }
            var_10 = 0xfffffff0;
            esp = esp - 0x8;
            if ((GetWindowLongA(esi, 0xfffffff0) & 0x10000000) == 0x0) {
                    esp = esp - 0x8;
                    continue;
            }
            GetWindowRect(esi, &var_10);
            var_10 = arg_8;
            esp = esp - 0x14;
            eax = PtInRect(&var_10, arg_4);
            if (eax != 0x0) {
                    break;
            }
            esp = esp - 0x8;
    }
    return;
}
