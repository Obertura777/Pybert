// sub_481faf @ 0x481faf
// hopper name: sub_481faf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481faf() {
    esi = arg_8;
    esp = (esp - 0xc) + 0xc;
    if (sub_47db5e(arg_0, arg_4, esi) != 0x0) {
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    eax = esi + 0x40;
    if (*(int8_t *)eax != 0x0) {
            sub_481e48(arg_0, arg_4, 0x2);
            esp = (esp - 0x14) + 0x14;
    }
    eax = esi + 0x80;
    esp = esp + 0x8;
    if (*(int8_t *)eax != 0x0) {
            eax = sub_481e48(arg_0, arg_4, 0x2);
            esp = (esp - 0x14) + 0x14;
    }
    return eax;
}
