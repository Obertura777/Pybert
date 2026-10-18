// sub_420dd0 @ 0x420dd0
// hopper name: sub_420dd0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_420dd0() {
    decomp_var_c = *0x0;
    decomp_var_4c = ebx;
    decomp_var_50 = ebp;
    decomp_var_54 = esi;
    decomp_var_58 = edi;
    esp = esp - 0x5c;
    decomp_var_5c = *dword_4c8db8 ^ &decomp_var_58;
    *0x0 = &decomp_var_c;
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_420e27;
    goto loc_420e1d;

loc_420e27:
    decomp_var_44 = (*(*eax + 0xc))() + 0x10;
    eax = sub_466060(&decomp_var_38, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&decomp_var_38, 0x0);
    esp = esp - 0x1c;
    sub_465900(&decomp_var_46, 0x0);
    sub_465fa0();
    esi = &arg_10;
    edi = *arg_14;
    decomp_var_40 = esi;
    decomp_var_3c = edi;
    goto loc_420eb0;

loc_420e1d:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_420eb0:
    ebp = arg_14;
    if (esi == 0x0 || esi != &arg_10) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_38, &decomp_var_1c, decomp_var_5c);
            sub_401520();
            edi = decomp_var_3c;
            esi = decomp_var_40;
            continue;
    }
    break;
    esp = esp - 0x4;
    eax = sub_46b050(&decomp_var_38, decomp_var_5c, decomp_var_58);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_44, "Recalculating: Because we have applied a NOT XDO: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    if (decomp_var_20 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = decomp_var_44 - 0x10;
    edi = sub_40bfa0(esi) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_38, &decomp_var_40, decomp_var_5c);
    eax = edi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (ecx <= 0x1) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    sub_403430(&decomp_var_40, &arg_10, *arg_14, &arg_10, arg_14);
    sub_47c8f9();
    eax = 0x1;
    *0x0 = decomp_var_c;
    return eax;
}
