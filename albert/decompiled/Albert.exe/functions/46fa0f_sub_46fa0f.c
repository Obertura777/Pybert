// sub_46fa0f @ 0x46fa0f
// hopper name: sub_46fa0f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46fa0f() {
    ebp = &saved_fp;
    arg_20c = *dword_4c8db8 ^ ebp;
    sub_47d6ee(arg_fffffffffffffffc);
    edi = arg_21c;
    esp = esp - 0x118;
    arg_e4 = arg_218;
    esi = RegOpenKeyA(arg_fffffffffffffffc, arg_0, arg_4);
    if (esi == 0x0) {
            while (true) {
                    esp = esp - 0x10;
                    eax = RegEnumKeyA(arg_fffffffffffffffc, arg_0, arg_4, arg_8);
                    esi = eax;
                    if (esi != 0x0) {
                            break;
                    }
                    sub_40bba0();
                    esp = esp - 0xc;
                    esi = sub_46fa0f();
                    arg_100 = 0x0;
                    sub_40b670();
                    if (esi != 0x0) {
                            break;
                    }
                    arg_100 = arg_100 | 0xffffffff;
            }
            if (esi == 0x103 || esi == 0x3f2) {
                    esp = esp - 0x8;
                    esi = RegDeleteKeyA(arg_fffffffffffffffc, arg_0);
            }
            esp = esp - 0x4;
            RegCloseKey(arg_fffffffffffffffc);
    }
    *0x0 = arg_f8;
    sub_47ad69();
    return;
}
