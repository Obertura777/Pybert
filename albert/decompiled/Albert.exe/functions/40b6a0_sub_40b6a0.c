// sub_40b6a0 @ 0x40b6a0
// hopper name: sub_40b6a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b6a0() {
    eax = arg_0;
    if (eax >= 0x0) {
            edx = *ecx;
            if (eax <= *(edx - 0x8)) {
                    *(edx - 0xc) = eax;
                    *(int8_t *)(eax + *ecx) = 0x0;
            }
            else {
                    eax = sub_40b5a0(0x80070057);
            }
    }
    else {
            eax = sub_40b5a0(0x80070057);
    }
    return eax;
}
