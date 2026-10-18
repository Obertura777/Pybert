// sub_431bc0 @ 0x431bc0
// hopper name: sub_431bc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_431bc0() {

sub_431bc0:
    esi = arg_48;
    if (edi == 0x0 || edi != &arg_44) {
            sub_47a948();
    }
    if (ebp == esi) goto loc_431c64;
    goto loc_431bdd;

loc_431c64:
    eax = loc_431c68();
    return eax;

loc_431bdd:
    if (ebx == arg_14[0x1]) {
            sub_47a948();
    }
    esi = ebx + 0x30;
    arg_98 = ebx[0xd];
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    edi = &arg_8;
    if (ebx == arg_14[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_78, edi, saved_fp, arg_0, arg_4);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    sub_401520();
    ebp = arg_24;
    edi = arg_20;
    goto sub_431bc0;
}
