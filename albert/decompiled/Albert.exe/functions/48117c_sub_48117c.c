// sub_48117c @ 0x48117c
// hopper name: sub_48117c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48117c() {
    *dword_bc6630 = eax;
    *dword_bc662c = ecx;
    *dword_bc6628 = edx;
    *dword_bc6624 = ebx;
    *dword_bc6620 = esi;
    *dword_bc661c = edi;
    *(int16_t *)word_bc6648 = cs;
    *(int16_t *)word_bc663c = ??;
    *(int16_t *)word_bc6618 = es;
    *(int16_t *)word_bc6614 = ds;
    *(int16_t *)word_bc6610 = fs;
    *(int16_t *)word_bc660c = gs;
    asm { pushfd };
    *dword_bc6640 = var_328;
    *dword_bc6634 = *ebp;
    *dword_bc6638 = ret_addr;
    *dword_bc6644 = &arg_0;
    *dword_bc6580 = 0x10001;
    *dword_bc6534 = *dword_bc6638;
    *dword_bc6528 = 0xc0000409;
    *dword_bc652c = 0x1;
    var_328 = *dword_4c8db8;
    *dword_bc6578 = IsDebuggerPresent();
    sub_47fe08();
    SetUnhandledExceptionFilter(0x0);
    esp = (esp + 0x4 - 0x4) + 0x4 - 0x8;
    UnhandledExceptionFilter(0x4b3a34);
    if (*dword_bc6578 == 0x0) {
            sub_47fe08();
            esp = (esp - 0x4) + 0x4;
    }
    eax = GetCurrentProcess();
    eax = TerminateProcess(eax, var_328);
    return eax;
}
