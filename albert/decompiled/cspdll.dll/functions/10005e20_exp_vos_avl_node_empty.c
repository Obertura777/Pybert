// exp_vos_avl_node_empty @ 0x10005e20
// hopper name: exp_vos_avl_node_empty
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_node_empty() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    ebx = arg_8;
    ebp = arg_0;
    esi = arg_4;
    esp = esp - 0x10;
    edi = arg_c;
    eax = esi[0x1];
    if (eax != 0x0) {
            vos_avl_node_empty(ebp, eax, ebx, edi);
            esp = (esp - 0x10) + 0x10;
    }
    eax = esi[0x3];
    if (eax != 0x0) {
            vos_avl_node_empty(ebp, eax, ebx, edi);
            esp = (esp - 0x10) + 0x10;
    }
    eax = (ebx)(esi - arg_e, edi);
    return eax;
}
