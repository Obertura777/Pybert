// sub_45cec0 @ 0x45cec0
// hopper name: sub_45cec0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45cec0() {
    var_C = *0x0;
    decomp_var_40 = ebx;
    decomp_var_44 = ebp;
    decomp_var_48 = esi;
    decomp_var_4c = edi;
    decomp_var_50 = *dword_4c8db8 ^ &decomp_var_4c;
    *0x0 = &var_C;
    sub_465870();
    sub_465870();
    eax = sub_466060(&var_3C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_3C, 0x2);
    esp = esp - 0x68;
    sub_465ff0(eax);
    sub_465fa0();
    esi = ecx + 0x40;
    edi = *ecx[0x11];
    goto loc_45cf6d;

loc_45cf6d:
    ebx = esi[0x1];
    if (esi == 0x0 || esi != esi) {
            sub_47a948();
    }
    if (edi != ebx) {
            ebp = esi;
            ebx = edi;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi = *edi;
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_465d90(&var_1C);
            if (eax != 0x0) {
                    if (ebx == arg_0) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_465d90(&var_2C);
                    if (eax != 0x0) {
                            esp = esp - 0xc;
                            eax = sub_45cb30(&var_3C, ebp, ebx);
                    }
            }
            continue;
    }
    break;
    sub_465fa0();
    sub_465fa0();
    *0x0 = var_C;
    return;
}
