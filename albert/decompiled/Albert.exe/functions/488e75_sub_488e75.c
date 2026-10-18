// sub_488e75 @ 0x488e75
// hopper name: sub_488e75
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

// DECOMPILE FAILED: {"code": "unreadable_output", "category": "execution_failure", "message": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed.", "retryable": false, "remediation": {"action": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed."}, "details": {"operation": "procedure_pseudo_code", "reason": "provider returned empty pseudocode"}}

// Fallback: REA procedure_assembly (Hopper)
/*
0x488e75: push ebp
0x488e76: mov ebp, esp
0x488e78: push ecx
0x488e79: mov ecx, dword [ebp+arg_8]
0x488e7c: push ebx
0x488e7d: xor eax, eax
0x488e7f: cmp dword [ebp+arg_0], eax
0x488e82: push esi
0x488e83: mov dword [edi], eax
0x488e85: mov esi, edx
0x488e87: mov edx, dword [ebp+arg_4]
0x488e8a: mov dword [ecx], 0x1
0x488e90: je loc_488e9b
0x488e92: mov ebx, dword [ebp+arg_0]
0x488e95: add dword [ebp+arg_0], 0x4
0x488e99: mov dword [ebx], edx
0x488ea3: xor eax, eax
0x488ea5: cmp dword [ebp+var_4], eax
0x488ea8: mov bl, 0x22
0x488eaa: sete al
0x488ead: inc esi
0x488eae: mov dword [ebp+var_4], eax
0x488eb1: jmp loc_488eef
0x488eef: cmp dword [ebp+var_4], 0x0
0x488ef3: jne loc_488e9e
0x488e9e: cmp byte [esi], 0x22
0x488ea1: jne loc_488eb3
0x488ef5: cmp bl, 0x20
0x488ef8: je loc_488eff
0x488efa: cmp bl, 0x9
0x488efd: jne loc_488e9e
0x488eff: test edx, edx
0x488f01: je loc_488f07
0x488f03: mov byte [edx-1], 0x0
0x488f14: mov al, byte [esi]
0x488f16: cmp al, 0x20
0x488f18: je loc_488f1e
0x488f1a: cmp al, 0x9
0x488f1c: jne loc_488f24
0x488f1e: inc esi
0x488f1f: jmp loc_488f14
0x488f24: cmp byte [esi], 0x0
0x488f27: je loc_488ffd
0x488f2d: cmp dword [ebp+arg_0], 0x0
0x488f31: je loc_488f3c
0x488f33: mov eax, dword [ebp+arg_0]
0x488f36: add dword [ebp+arg_0], 0x4
0x488f3a: mov dword [eax], edx
0x488f47: cmp byte [esi], 0x5c
0x488f4a: je loc_488f45
0x488f4c: cmp byte [esi], 0x22
0x488f4f: jne loc_488f77
0x488f51: test cl, 0x1
0x488f54: jne loc_488f75
0x488f56: cmp dword [ebp+var_4], 0x0
0x488f5a: je loc_488f68
0x488f5c: lea eax, dword [esi+1]
0x488f5f: cmp byte [eax], 0x22
0x488f62: jne loc_488f68
0x488f64: mov esi, eax
0x488f66: jmp loc_488f75
0x488f75: shr ecx, 0x1
0x488f7b: dec ecx
0x488f7c: test edx, edx
0x488f7e: je loc_488f84
0x488f80: mov byte [edx], 0x5c
0x488f83: inc edx
0x488f8a: mov dword [ebp+arg_4], edx
0x488f93: cmp dword [ebp+var_4], 0x0
0x488f97: jne loc_488fa1
0x488f99: cmp al, 0x20
0x488f9b: je loc_488fe8
0x488f9d: cmp al, 0x9
0x488f9f: je loc_488fe8
0x488fa1: test ebx, ebx
0x488fa3: je loc_488fe2
0x488fa5: test edx, edx
0x488fa7: movsx eax, al
0x488faa: push eax
0x488fab: je loc_488fd0
0x488fad: call sub_47f62e
0x488fb2: test eax, eax
0x488fb4: pop ecx
0x488fb5: je loc_488fc4
0x488fb7: mov al, byte [esi]
0x488fb9: mov ecx, dword [ebp+arg_4]
0x488fbc: inc dword [ebp+arg_4]
0x488fbf: mov byte [ecx], al
0x488fc1: inc esi
0x488fc2: inc dword [edi]
0x488fdd: inc dword [edi]
0x488fdf: mov edx, dword [ebp+arg_4]
0x488f3e: xor ebx, ebx
0x488f40: inc ebx
0x488f41: xor ecx, ecx
0x488f43: jmp loc_488f47
0x488fc4: mov ecx, dword [ebp+arg_4]
0x488fc7: mov al, byte [esi]
0x488fc9: inc dword [ebp+arg_4]
0x488fcc: mov byte [ecx], al
0x488fce: jmp loc_488fdd
0x488fd0: call sub_47f62e
0x488fd5: test eax, eax
0x488fd7: pop ecx
0x488fd8: je loc_488fdd
0x488fda: inc esi
0x488fdb: inc dword [edi]
0x488fe2: inc esi
0x488fe3: jmp loc_488f3e
0x488fe8: test edx, edx
0x488fea: je loc_488ff3
0x488fec: mov byte [edx], 0x0
0x488fef: inc edx
0x488ff0: mov dword [ebp+arg_4], edx
0x488f0b: cmp byte [esi], 0x0
0x488f0e: je loc_488ffd
0x488ff3: inc dword [edi]
0x488ff5: mov ecx, dword [ebp+arg_8]
0x488ff8: jmp loc_488f0b
0x488f84: inc dword [edi]
0x488f86: test ecx, ecx
0x488f88: jne loc_488f7b
0x488f8d: mov al, byte [esi]
0x488f8f: test al, al
0x488f91: je loc_488fe8
0x488f68: xor eax, eax
0x488f6a: xor ebx, ebx
0x488f6c: cmp dword [ebp+var_4], eax
0x488f6f: sete al
0x488f72: mov dword [ebp+var_4], eax
0x488f77: test ecx, ecx
0x488f79: je loc_488f8d
0x488f45: inc esi
0x488f46: inc ecx
0x488f3c: inc dword [ecx]
0x488ffd: mov eax, dword [ebp+arg_0]
0x489000: test eax, eax
0x489002: pop esi
0x489003: pop ebx
0x489004: je loc_489009
0x489006: and dword [eax], 0x0
0x489009: inc dword [ecx]
0x48900b: leave
0x48900c: ret
0x488f07: and dword [ebp+var_4], 0x0
0x488eb3: inc dword [edi]
0x488eb5: test edx, edx
0x488eb7: je loc_488ec1
0x488eb9: mov al, byte [esi]
0x488ebb: mov byte [edx], al
0x488ebd: inc edx
0x488ebe: mov dword [ebp+arg_4], edx
0x488ed2: inc dword [edi]
0x488ed4: cmp dword [ebp+arg_4], 0x0
0x488ed8: je loc_488ee4
0x488eda: mov ecx, dword [ebp+arg_4]
0x488edd: mov al, byte [esi]
0x488edf: inc dword [ebp+arg_4]
0x488ee2: mov byte [ecx], al
0x488f21: dec esi
0x488f22: jmp loc_488f07
0x488ee4: inc esi
0x488ee5: test bl, bl
0x488ee7: mov edx, dword [ebp+arg_4]
0x488eea: mov ecx, dword [ebp+arg_8]
0x488eed: je loc_488f21
0x488ec1: mov bl, byte [esi]
0x488ec3: movzx eax, bl
0x488ec6: push eax
0x488ec7: inc esi
0x488ec8: call sub_47f62e
0x488ecd: test eax, eax
0x488ecf: pop ecx
0x488ed0: je loc_488ee5
0x488e9b: mov dword [ebp+var_4], eax
*/
