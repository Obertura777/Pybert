// sub_40a380 @ 0x40a380
// hopper name: sub_40a380
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

// DECOMPILE FAILED: {"code": "unreadable_output", "category": "execution_failure", "message": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed.", "retryable": false, "remediation": {"action": "Analysis returned an unreadable result. Run `rea doctor` and review the reported details; repeating the unchanged request is not expected to succeed."}, "details": {"operation": "procedure_pseudo_code", "reason": "provider returned empty pseudocode"}}

// Fallback: REA procedure_assembly (Hopper)
/*
0x40a380: push 0xffffffff
0x40a382: push 0x4945a8
0x40a387: mov eax, dword [fs:0x0]
0x40a38d: push eax
0x40a38e: sub esp, 0x30
0x40a391: push ebx
0x40a392: push ebp
0x40a393: push esi
0x40a394: push edi
0x40a395: mov eax, dword [dword_4c8db8]
0x40a39a: xor eax, esp
0x40a39c: push eax
0x40a39d: lea eax, dword [esp+0x50+var_C]
0x40a3a1: mov dword [fs:0x0], eax
0x40a3a7: mov ebx, ecx
0x40a3a9: mov dword [esp+0x50+var_3C], ebx
0x40a3ad: lea ecx, dword [esp+0x50+var_18]
0x40a3b1: call sub_4018e0
0x40a3b6: xor ebp, ebp
0x40a3b8: mov dword [esp+0x50+var_14], eax
0x40a3bc: mov dword [esp+0x50+var_10], ebp
0x40a3c0: mov eax, dword [ebx+0x2528]
0x40a3c6: mov esi, dword [eax]
0x40a3c8: lea edi, dword [ebx+0x2524]
0x40a3ce: mov dword [esp+0x50+var_4], ebp
0x40a3d2: mov dword [esp+0x50+var_30], ebp
0x40a3d6: mov dword [esp+0x50+var_28], edi
0x40a3da: mov dword [esp+0x50+var_24], esi
0x40a3de: mov edi, edi
0x40a3f4: cmp edi, eax
0x40a3f6: je loc_40a3fd
0x40a3f8: call sub_47a948
0x40a407: test edi, edi
0x40a409: jne loc_40a410
0x40a40b: call sub_47a948
0x40a415: call sub_47a948
0x40a450: mov edi, dword [eax]
0x40a452: push eax
0x40a453: call j_sub_47c8f9
0x40a458: add esp, 0x4
0x40a45b: cmp edi, dword [esp+0x50+var_14]
0x40a45f: mov eax, edi
0x40a461: jne loc_40a450
0x40a463: mov dword [esp+0x50+var_38], 0xffffffff
0x40a4b1: cmp eax, 0x1
0x40a4b4: je loc_40a4cc
0x40a4b6: mov eax, dword [esi]
0x40a4b8: mov ecx, dword [esp+0x50+var_14]
0x40a4bc: mov dword [esp+0x50+var_38], eax
0x40a4c0: mov eax, dword [ecx]
0x40a4c2: lea ecx, dword [esp+0x50+var_18]
0x40a4c6: mov dword [esp+0x50+var_30], ecx
0x40a4ca: mov ebp, eax
0x40a46b: mov ecx, dword [esp+0x50+var_14]
0x40a46f: mov edi, dword [ecx]
0x40a471: mov edx, dword [edi+4]
0x40a474: push esi
0x40a475: push edx
0x40a476: push edi
0x40a477: lea ecx, dword [esp+0x5c+var_18]
0x40a47b: call sub_401b00
0x40a480: push 0x1
0x40a482: lea ecx, dword [esp+0x54+var_18]
0x40a486: mov ebx, eax
0x40a488: call sub_403ec0
0x40a48d: mov dword [edi+4], ebx
0x40a490: mov eax, dword [ebx+4]
0x40a493: mov dword [eax], ebx
0x40a495: mov ecx, dword [esi]
0x40a497: mov edx, dword [esi+0x14]
0x40a49a: mov ebx, dword [esp+0x50+var_3C]
0x40a49e: lea edi, dword [esi+0x14]
0x40a4a1: push ecx
0x40a4a2: push edx
0x40a4a3: mov ecx, ebx
0x40a4a5: call sub_4090d0
0x40a4aa: test eax, eax
0x40a4ac: mov dword [esi+0x4c], eax
0x40a4af: je loc_40a4cc
0x40a4e2: cmp dword [esp+0x50+var_38], 0xffffffff
0x40a4e7: jne loc_40a53e
0x40a4e9: mov eax, dword [esp+0x50+var_14]
0x40a4ed: mov esi, dword [eax]
0x40a4ef: lea edi, dword [esp+0x50+var_18]
0x40a4fb: lea ecx, dword [esp+0x50+var_18]
0x40a4ff: cmp edi, ecx
0x40a501: je loc_40a508
0x40a503: call sub_47a948
0x40a510: test edi, edi
0x40a512: jne loc_40a519
0x40a514: call sub_47a948
0x40a51e: call sub_47a948
0x40a535: call sub_47a948
0x40a4f3: test edi, edi
0x40a4f5: mov ebx, dword [esp+0x50+var_14]
0x40a4f9: je loc_40a503
0x40a53a: mov esi, dword [esi]
0x40a53c: jmp loc_40a4f3
0x40a523: mov edx, dword [esi+8]
0x40a526: mov ecx, dword [esp+0x50+var_3C]
0x40a52a: push edx
0x40a52b: call sub_409250
0x40a530: cmp esi, dword [edi+4]
0x40a533: jne loc_40a53a
0x40a519: cmp esi, dword [edi+4]
0x40a51c: jne loc_40a523
0x40a6a3: lea ecx, dword [esp+0x50+var_28]
0x40a6a7: call sub_401520
0x40a6ac: mov esi, dword [esp+0x50+var_24]
0x40a6b0: mov edi, dword [esp+0x50+var_28]
0x40a6b4: mov ebx, dword [esp+0x50+var_3C]
0x40a6b8: jmp loc_40a3e0
0x40a3e0: test edi, edi
0x40a3e2: mov ecx, dword [ebx+0x2528]
0x40a3e8: lea eax, dword [ebx+0x2524]
0x40a3ee: mov dword [esp+0x50+var_1C], ecx
0x40a3f2: je loc_40a3f8
0x40a508: cmp esi, ebx
0x40a50a: je loc_40a6a3
0x40a53e: lea eax, dword [esp+0x50+var_38]
0x40a542: add ebx, 0x2450
0x40a548: push eax
0x40a549: mov ecx, ebx
0x40a54b: call sub_407720
0x40a550: mov ecx, dword [eax+0x4c]
0x40a553: cmp ecx, 0x2
0x40a556: jne loc_40a56a
0x40a558: mov ecx, dword [eax+0x14]
0x40a55b: push ecx
0x40a55c: mov ecx, dword [esp+0x54+var_3C]
0x40a560: call sub_4093f0
0x40a565: jmp loc_40a6a3
0x40a56a: cmp ecx, 0x4
0x40a56d: jne loc_40a57e
0x40a56f: mov ecx, dword [esp+0x50+var_3C]
0x40a573: push eax
0x40a574: call sub_404bc0
0x40a579: jmp loc_40a6a3
0x40a57e: mov edi, dword [esp+0x50+var_30]
0x40a582: test edi, edi
0x40a584: jne loc_40a58b
0x40a586: call sub_47a948
0x40a590: call sub_47a948
0x40a5a4: call sub_47a948
0x40a5ad: mov eax, dword [esp+0x50+var_14]
0x40a5b1: mov eax, dword [eax]
0x40a5b3: lea ecx, dword [esp+0x50+var_18]
0x40a5b7: mov dword [esp+0x50+var_30], ecx
0x40a5bb: mov ebp, eax
0x40a5bd: mov edi, ecx
0x40a5c3: call sub_47a948
0x40a5cd: call sub_47a948
0x40a5e5: mov ecx, dword [esp+0x50+var_3C]
0x40a5e9: push eax
0x40a5ea: call sub_404bc0
0x40a5ef: jmp loc_40a6a3
0x40a5f4: test ecx, ecx
0x40a5f6: je loc_40a610
0x40a5f8: mov edx, dword [eax+0x14]
0x40a5fb: mov ecx, dword [esp+0x50+var_3C]
0x40a5ff: push edx
0x40a600: call sub_4093f0
0x40a605: jmp loc_40a6a3
0x40a610: cmp ebp, dword [edi+4]
0x40a613: jne loc_40a61a
0x40a615: call sub_47a948
0x40a629: call sub_47a948
0x40a632: mov ecx, dword [esp+0x50+var_14]
0x40a636: mov eax, dword [ecx]
0x40a638: lea ecx, dword [esp+0x50+var_18]
0x40a63c: mov dword [esp+0x50+var_30], ecx
0x40a640: mov ebp, eax
0x40a642: mov edi, ecx
0x40a648: call sub_47a948
0x40a652: call sub_47a948
0x40a66c: cmp eax, 0x3
0x40a66f: je loc_40a685
0x40a671: cmp eax, 0x2
0x40a674: jne loc_40a68f
0x40a676: mov eax, dword [esi+0x14]
0x40a679: mov ecx, dword [esp+0x50+var_3C]
0x40a67d: push eax
0x40a67e: call sub_4093f0
0x40a683: jmp loc_40a68f
0x40a68f: mov esi, dword [esi+0x4c]
0x40a692: cmp esi, 0x1
0x40a695: je loc_40a610
0x40a69b: test esi, esi
0x40a69d: je loc_40a610
0x40a685: mov ecx, dword [esp+0x50+var_3C]
0x40a689: push esi
0x40a68a: call sub_404bc0
0x40a657: lea edx, dword [ebp+8]
0x40a65a: push edx
0x40a65b: mov ecx, ebx
0x40a65d: call sub_407720
0x40a662: mov esi, eax
0x40a664: mov eax, dword [esi+0x4c]
0x40a667: cmp eax, 0x4
0x40a66a: je loc_40a685
0x40a64d: cmp ebp, dword [edi+4]
0x40a650: jne loc_40a657
0x40a644: test edi, edi
0x40a646: jne loc_40a64d
0x40a62e: cmp ebp, esi
0x40a630: jne loc_40a644
0x40a61a: mov ebp, dword [ebp]
0x40a61d: mov esi, dword [esp+0x50+var_14]
0x40a621: lea eax, dword [esp+0x50+var_18]
0x40a625: cmp edi, eax
0x40a627: je loc_40a62e
0x40a5d2: lea ecx, dword [ebp+8]
0x40a5d5: push ecx
0x40a5d6: mov ecx, ebx
0x40a5d8: call sub_407720
0x40a5dd: mov ecx, dword [eax+0x4c]
0x40a5e0: cmp ecx, 0x4
0x40a5e3: jne loc_40a5f4
0x40a5c8: cmp ebp, dword [edi+4]
0x40a5cb: jne loc_40a5d2
0x40a5bf: test edi, edi
0x40a5c1: jne loc_40a5c8
0x40a5a9: cmp ebp, esi
0x40a5ab: jne loc_40a5bf
0x40a595: mov ebp, dword [ebp]
0x40a598: mov esi, dword [esp+0x50+var_14]
0x40a59c: lea edx, dword [esp+0x50+var_18]
0x40a5a0: cmp edi, edx
0x40a5a2: je loc_40a5a9
0x40a58b: cmp ebp, dword [edi+4]
0x40a58e: jne loc_40a595
0x40a4cc: push edi
0x40a4cd: lea ecx, dword [ebx+0x2450]
0x40a4d3: call sub_407720
0x40a4d8: mov edx, dword [esp+0x50+var_34]
0x40a4dc: mov esi, eax
0x40a4de: cmp dword [esi], edx
0x40a4e0: jne loc_40a46b
0x40a41a: mov edx, dword [esi+0xc]
0x40a41d: lea eax, dword [esp+0x50+var_34]
0x40a421: lea ecx, dword [ebx+0x2450]
0x40a427: push eax
0x40a428: mov dword [esp+0x54+var_34], edx
0x40a42c: call sub_407720
0x40a431: mov ecx, dword [esp+0x50+var_14]
0x40a435: mov esi, eax
0x40a437: mov eax, dword [ecx]
0x40a439: mov dword [ecx], ecx
0x40a43b: mov ecx, dword [esp+0x50+var_14]
0x40a43f: mov dword [ecx+4], ecx
0x40a442: cmp eax, dword [esp+0x50+var_14]
0x40a446: mov dword [esp+0x50+var_10], 0x0
0x40a44e: je loc_40a463
0x40a410: cmp esi, dword [edi+4]
0x40a413: jne loc_40a41a
0x40a6bd: mov ecx, dword [esp+0x50+var_14]
0x40a6c1: mov eax, dword [ecx]
0x40a6c3: mov dword [ecx], ecx
0x40a6c5: mov ecx, dword [esp+0x50+var_14]
0x40a6c9: mov dword [ecx+4], ecx
0x40a6cc: mov ecx, dword [esp+0x50+var_14]
0x40a6d0: cmp eax, ecx
0x40a6d2: mov dword [esp+0x50+var_10], 0x0
0x40a6da: je loc_40a6f5
0x40a6dc: lea esp, dword [esp+0x50+var_50]
0x40a6e0: mov esi, dword [eax]
0x40a6e2: push eax
0x40a6e3: call j_sub_47c8f9
0x40a6e8: mov ecx, dword [esp+0x54+var_14]
0x40a6ec: add esp, 0x4
0x40a6ef: cmp esi, ecx
0x40a6f1: mov eax, esi
0x40a6f3: jne loc_40a6e0
0x40a6f5: push ecx
0x40a6f6: call j_sub_47c8f9
0x40a6fb: add esp, 0x4
0x40a6fe: mov ecx, dword [esp+0x50+var_C]
0x40a702: mov dword [fs:0x0], ecx
0x40a709: pop ecx
0x40a70a: pop edi
0x40a70b: pop esi
0x40a70c: pop ebp
0x40a70d: pop ebx
0x40a70e: add esp, 0x3c
0x40a711: ret
0x40a3fd: cmp esi, dword [esp+0x50+var_1C]
0x40a401: je loc_40a6bd
*/
