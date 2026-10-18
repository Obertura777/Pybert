// sub_4890c6 @ 0x4890c6
// hopper name: sub_4890c6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

// DECOMPILE FAILED: {"code": "unreadable_output", "category": "execution_failure", "message": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed.", "retryable": false, "remediation": {"action": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed."}, "details": {"operation": "procedure_pseudo_code", "reason": "provider returned empty pseudocode"}}

// Fallback: REA procedure_assembly (Hopper)
/*
0x4890c6: push ecx
0x4890c7: push ecx
0x4890c8: mov eax, dword [dword_bc6e20]
0x4890cd: push ebx
0x4890ce: push ebp
0x4890cf: push esi
0x4890d0: push edi
0x4890d1: mov edi, dword [imp_GetEnvironmentStringsW]
0x4890d7: xor ebx, ebx
0x4890d9: xor esi, esi
0x4890db: cmp eax, ebx
0x4890dd: push 0x2
0x4890df: pop ebp
0x4890e0: jne loc_48910f
0x4890e2: call edi
0x4890e4: mov esi, eax
0x4890e6: cmp esi, ebx
0x4890e8: je loc_4890f6
0x4890ea: mov dword [dword_bc6e20], 0x1
0x4890f4: jmp loc_489118
0x489118: cmp esi, ebx
0x48911a: jne loc_48912b
0x48911c: call edi
0x48911e: mov esi, eax
0x489120: cmp esi, ebx
0x489122: jne loc_48912b
0x489124: xor eax, eax
0x489126: jmp loc_4891f4
0x4891f4: pop edi
0x4891f5: pop esi
0x4891f6: pop ebp
0x4891f7: pop ebx
0x4891f8: pop ecx
0x4891f9: pop ecx
0x4891fa: ret
0x48912b: cmp word [esi], bx
0x48912e: mov eax, esi
0x489130: je loc_489140
0x489132: add eax, ebp
0x489134: cmp word [eax], bx
0x489137: jne loc_489132
0x489139: add eax, ebp
0x48913b: cmp word [eax], bx
0x48913e: jne loc_489132
0x489140: mov edi, dword [imp_WideCharToMultiByte]
0x489146: push ebx
0x489147: push ebx
0x489148: push ebx
0x489149: sub eax, esi
0x48914b: push ebx
0x48914c: sar eax, 0x1
0x48914e: inc eax
0x48914f: push eax
0x489150: push esi
0x489151: push ebx
0x489152: push ebx
0x489153: mov dword [esp+0x38+var_4], eax
0x489157: call edi
0x489159: mov ebp, eax
0x48915b: cmp ebp, ebx
0x48915d: je loc_489191
0x48915f: push ebp
0x489160: call sub_481280
0x489165: cmp eax, ebx
0x489167: pop ecx
0x489168: mov dword [esp+0x18+var_8], eax
0x48916c: je loc_489191
0x48916e: push ebx
0x48916f: push ebx
0x489170: push ebp
0x489171: push eax
0x489172: push dword [esp+0x28+var_4]
0x489176: push esi
0x489177: push ebx
0x489178: push ebx
0x489179: call edi
0x48917b: test eax, eax
0x48917d: jne loc_48918d
0x48917f: push dword [esp+0x18+var_8]
0x489183: call sub_47c8f9
0x489188: pop ecx
0x489189: mov dword [esp+0x18+var_8], ebx
0x48918d: mov ebx, dword [esp+0x18+var_8]
0x489191: push esi
0x489192: call dword [imp_FreeEnvironmentStringsW]
0x489198: mov eax, ebx
0x48919a: jmp loc_4891f4
0x4890f6: call dword [imp_GetLastError]
0x4890fc: cmp eax, 0x78
0x4890ff: jne loc_48910a
0x489101: mov eax, ebp
0x489103: mov dword [dword_bc6e20], eax
0x489108: jmp loc_48910f
0x48910f: cmp eax, 0x1
0x489112: jne loc_48919c
0x48919c: cmp eax, ebp
0x48919e: je loc_4891a4
0x4891a0: cmp eax, ebx
0x4891a2: jne loc_489124
0x4891a4: call dword [imp_GetEnvironmentStrings]
0x4891aa: mov esi, eax
0x4891ac: cmp esi, ebx
0x4891ae: je loc_489124
0x4891b4: cmp byte [esi], bl
0x4891b6: je loc_4891c2
0x4891b8: inc eax
0x4891b9: cmp byte [eax], bl
0x4891bb: jne loc_4891b8
0x4891bd: inc eax
0x4891be: cmp byte [eax], bl
0x4891c0: jne loc_4891b8
0x4891c2: sub eax, esi
0x4891c4: inc eax
0x4891c5: mov ebp, eax
0x4891c7: push ebp
0x4891c8: call sub_481280
0x4891cd: mov edi, eax
0x4891cf: cmp edi, ebx
0x4891d1: pop ecx
0x4891d2: jne loc_4891e0
0x4891d4: push esi
0x4891d5: call dword [imp_FreeEnvironmentStringsA]
0x4891db: jmp loc_489124
0x4891e0: push ebp
0x4891e1: push esi
0x4891e2: push edi
0x4891e3: call sub_47c000
0x4891e8: add esp, 0xc
0x4891eb: push esi
0x4891ec: call dword [imp_FreeEnvironmentStringsA]
0x4891f2: mov eax, edi
0x48910a: mov eax, dword [dword_bc6e20]
*/
