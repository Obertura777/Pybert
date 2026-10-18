// sub_484a85 @ 0x484a85
// hopper name: sub_484a85
// contains unmarked entry 0x484c79
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_8c4664d1a66fef8236cd88844b2dea95039e991ab195e16719004367e7e764b8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484a85() {
    esi = &decomp_var_78;
    decomp_var_7c = esi;
    esp = esp - 0x84;
    asm { fstp       qword [esp+0x84+var_84] };
    esp = esp - 0x8;
    asm { fstp       qword [esp+0x8c+var_8C] };
    asm { wait };
    asm { fnsave     dword [esi+8] };
    eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
    asm { frstor     dword [esi+8] };
    asm { fld        qword [esi] };
    if (eax == 0x0) goto .l1;

.l1:
    return;
}
