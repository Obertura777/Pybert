// sub_45e930 @ 0x45e930
// hopper name: sub_45e930
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45e930() {
    decomp_var_10 = esi;
    esi = arg_4;
    eax = sub_46dbce(esi);
    esp = (esp - 0x14) + 0x4;
    if (eax == 0x0) {
            sub_45f930("Failed to allocate memory to queue message", decomp_var_10);
    }
    else {
            sub_47c000(eax, arg_0, esi);
            WaitForSingleObject(*(*dword_bc2124 + 0x24), 0xffffffff);
            edi = *(*dword_bc2124 + 0x1c);
            eax = edi[0x1];
            eax = sub_45bae0(edi, eax, &var_18);
            ebx = eax;
            sub_45d3b0(0x1);
            edi[0x1] = ebx;
            *ebx[0x1] = ebx;
            ReleaseMutex(*(*dword_bc2124 + 0x24));
            PostMessageA(*(*(*dword_bc2124 + 0x4) + 0x20), 0x4149, 0x0, 0x0);
    }
    return;
}
