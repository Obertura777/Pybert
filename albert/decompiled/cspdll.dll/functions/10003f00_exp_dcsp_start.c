// exp_dcsp_start @ 0x10003f00
// hopper name: exp_dcsp_start
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_start() {
    esp = esp - 0x1a4;
    eax = (*0x1000917c)(0x202, &var_190, esi, ebp, ebx);
    if (eax == 0x0) {
            eax = malloc(0x64);
            esp = (esp - 0x4) + 0x4;
            bool_43 = true;
            *dword_1000ab38 = eax;
            if (eax != 0x0) {
                    *eax = 0x0;
                    ebp = arg_10;
                    *(*dword_1000ab38 + 0x4) = 0x0;
                    *(*dword_1000ab38 + 0x8) = 0x0;
                    *(*dword_1000ab38 + 0xc) = 0x0;
                    *(*dword_1000ab38 + 0x10) = 0x0;
                    *(*dword_1000ab38 + 0x14) = 0x0;
                    *(*dword_1000ab38 + 0x18) = 0x0;
                    *(*dword_1000ab38 + 0x1c) = 0x0;
                    *(*dword_1000ab38 + 0x20) = 0x0;
                    *(*dword_1000ab38 + 0x24) = 0x0;
                    *(*dword_1000ab38 + 0x28) = *ebp;
                    esp = (esp - 0x18) + 0x18;
                    if (vos_trace_initialise(arg_28, arg_24, arg_2c, arg_30, arg_34, edi, decomp_var_18c) != 0x0) {
                            esp = esp - 0xc;
                            *(*dword_1000ab38 + 0x8) = CreateMutexA(0x0, 0x0, 0x0);
                            if (*(*dword_1000ab38 + 0x8) != 0x0) {
                                    esp = esp - 0x10;
                                    *(*dword_1000ab38 + 0x1c) = CreateSemaphoreA(0x0, 0x0, 0x7fffffff, 0x0);
                                    if (*(*dword_1000ab38 + 0x1c) == 0x0) {
                                            GetLastError();
                                            if (*dword_1000ab38 != 0x0) {
                                                    (*0x10009164)();
                                                    eax = *dword_1000ab38;
                                                    eax = eax[0x9];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            CloseHandle(eax);
                                                            *(*dword_1000ab38 + 0x24) = 0x0;
                                                    }
                                                    eax = *(*dword_1000ab38 + 0x20);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            CloseHandle(eax);
                                                            *(*dword_1000ab38 + 0x20) = 0x0;
                                                    }
                                                    eax = *(*dword_1000ab38 + 0x1c);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            CloseHandle(eax);
                                                            *(*dword_1000ab38 + 0x1c) = 0x0;
                                                    }
                                                    ebx = 0x0;
                                                    eax = *dword_1000ab38;
                                                    eax = eax[0x2];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            CloseHandle(eax);
                                                            *(*dword_1000ab38 + 0x8) = ebx;
                                                    }
                                                    free(*dword_1000ab38);
                                                    *dword_1000ab38 = 0x0;
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(*dword_1000ab38 + 0x20) = CreateEventA(0x0, 0x1, 0x0, 0x0);
                                            if (*(*dword_1000ab38 + 0x20) != 0x0) {
                                                    ebx = 0x0;
                                                    esp = esp - 0x10;
                                                    *(*dword_1000ab38 + 0x24) = CreateSemaphoreA(0x0, 0x0, 0x1, 0x0);
                                                    if (*(*dword_1000ab38 + 0x24) != 0x0) {
                                                            eax = *dword_1000ab38;
                                                            esp = esp - 0x18;
                                                            **dword_1000ab38 = CreateThread(ebx, ebx, sub_10004880, eax + 0x8, ebx, eax + 0x4);
                                                            if (**dword_1000ab38 != ebx) {
                                                                    Sleep(0x3e8);
                                                                    vos_trace_thread_start();
                                                                    free(ebp);
                                                                    eax = 0x1;
                                                            }
                                                            else {
                                                                    ebx = 0x0;
                                                                    if (*dword_1000ab38 != 0x0) {
                                                                            (*0x10009164)();
                                                                            eax = *dword_1000ab38;
                                                                            eax = eax[0x9];
                                                                            if (eax != ebx) {
                                                                                    esp = esp - 0x4;
                                                                                    CloseHandle(eax);
                                                                                    *(*dword_1000ab38 + 0x24) = ebx;
                                                                            }
                                                                            ebx = 0x0;
                                                                            eax = *(*dword_1000ab38 + 0x20);
                                                                            if (eax != 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    CloseHandle(eax);
                                                                                    *(*dword_1000ab38 + 0x20) = ebx;
                                                                            }
                                                                            eax = *(*dword_1000ab38 + 0x1c);
                                                                            if (eax != ebx) {
                                                                                    esp = esp - 0x4;
                                                                                    CloseHandle(eax);
                                                                                    *(*dword_1000ab38 + 0x1c) = ebx;
                                                                            }
                                                                            ebx = 0x0;
                                                                            eax = *dword_1000ab38;
                                                                            eax = eax[0x2];
                                                                            if (eax != 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    CloseHandle(eax);
                                                                                    *(*dword_1000ab38 + 0x8) = ebx;
                                                                            }
                                                                            free(*dword_1000ab38);
                                                                            *dword_1000ab38 = ebx;
                                                                            eax = ebx;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (*dword_1000ab38 != ebx) {
                                                                    (*0x10009164)();
                                                                    eax = *dword_1000ab38;
                                                                    eax = eax[0x9];
                                                                    if (eax != ebx) {
                                                                            esp = esp - 0x4;
                                                                            CloseHandle(eax);
                                                                            *(*dword_1000ab38 + 0x24) = ebx;
                                                                    }
                                                                    eax = *(*dword_1000ab38 + 0x20);
                                                                    if (eax != 0x0) {
                                                                            esp = esp - 0x4;
                                                                            CloseHandle(eax);
                                                                            *(*dword_1000ab38 + 0x20) = 0x0;
                                                                    }
                                                                    ebx = 0x0;
                                                                    eax = *(*dword_1000ab38 + 0x1c);
                                                                    if (eax != 0x0) {
                                                                            esp = esp - 0x4;
                                                                            CloseHandle(eax);
                                                                            *(*dword_1000ab38 + 0x1c) = ebx;
                                                                    }
                                                                    eax = *dword_1000ab38;
                                                                    eax = eax[0x2];
                                                                    if (eax != ebx) {
                                                                            esp = esp - 0x4;
                                                                            CloseHandle(eax);
                                                                            *(*dword_1000ab38 + 0x8) = ebx;
                                                                    }
                                                                    free(*dword_1000ab38);
                                                                    *dword_1000ab38 = ebx;
                                                                    eax = ebx;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                            }
                                            else {
                                                    ebx = 0x0;
                                                    if (*dword_1000ab38 != 0x0) {
                                                            (*0x10009164)();
                                                            eax = *dword_1000ab38;
                                                            eax = eax[0x9];
                                                            if (eax != ebx) {
                                                                    esp = esp - 0x4;
                                                                    CloseHandle(eax);
                                                                    *(*dword_1000ab38 + 0x24) = ebx;
                                                            }
                                                            eax = *(*dword_1000ab38 + 0x20);
                                                            if (eax != ebx) {
                                                                    esp = esp - 0x4;
                                                                    CloseHandle(eax);
                                                                    *(*dword_1000ab38 + 0x20) = ebx;
                                                            }
                                                            eax = *(*dword_1000ab38 + 0x1c);
                                                            if (eax != ebx) {
                                                                    esp = esp - 0x4;
                                                                    CloseHandle(eax);
                                                                    *(*dword_1000ab38 + 0x1c) = ebx;
                                                            }
                                                            eax = *dword_1000ab38;
                                                            eax = eax[0x2];
                                                            if (eax != ebx) {
                                                                    esp = esp - 0x4;
                                                                    CloseHandle(eax);
                                                                    *(*dword_1000ab38 + 0x8) = ebx;
                                                            }
                                                            free(*dword_1000ab38);
                                                            *dword_1000ab38 = ebx;
                                                            eax = ebx;
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (*dword_1000ab38 != 0x0) {
                                            ebx = 0x0;
                                            (*0x10009164)();
                                            eax = *dword_1000ab38;
                                            eax = eax[0x9];
                                            if (eax != 0x0) {
                                                    ebx = 0x0;
                                                    esp = esp - 0x4;
                                                    CloseHandle(eax);
                                                    *(*dword_1000ab38 + 0x24) = 0x0;
                                            }
                                            eax = *(*dword_1000ab38 + 0x20);
                                            if (eax != ebx) {
                                                    esp = esp - 0x4;
                                                    CloseHandle(eax);
                                                    *(*dword_1000ab38 + 0x20) = ebx;
                                            }
                                            eax = *(*dword_1000ab38 + 0x1c);
                                            if (eax != ebx) {
                                                    esp = esp - 0x4;
                                                    CloseHandle(eax);
                                                    *(*dword_1000ab38 + 0x1c) = ebx;
                                            }
                                            ebx = 0x0;
                                            eax = *dword_1000ab38;
                                            eax = eax[0x2];
                                            if (eax != 0x0) {
                                                    ebx = 0x0;
                                                    esp = esp - 0x4;
                                                    CloseHandle(eax);
                                                    *(*dword_1000ab38 + 0x8) = 0x0;
                                            }
                                            free(*dword_1000ab38);
                                            *dword_1000ab38 = ebx;
                                            eax = ebx;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            if (*dword_1000ab38 != 0x0) {
                                    (*0x10009164)();
                                    eax = *dword_1000ab38;
                                    eax = eax[0x9];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            CloseHandle(eax);
                                            *(*dword_1000ab38 + 0x24) = 0x0;
                                    }
                                    ebx = 0x0;
                                    eax = *(*dword_1000ab38 + 0x20);
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            CloseHandle(eax);
                                            *(*dword_1000ab38 + 0x20) = ebx;
                                    }
                                    eax = *(*dword_1000ab38 + 0x1c);
                                    if (eax != ebx) {
                                            esp = esp - 0x4;
                                            CloseHandle(eax);
                                            *(*dword_1000ab38 + 0x1c) = ebx;
                                    }
                                    eax = *dword_1000ab38;
                                    eax = eax[0x2];
                                    if (eax != ebx) {
                                            esp = esp - 0x4;
                                            CloseHandle(eax);
                                            *(*dword_1000ab38 + 0x8) = ebx;
                                    }
                                    free(*dword_1000ab38);
                                    *dword_1000ab38 = ebx;
                                    eax = ebx;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            if (*dword_1000ab38 != 0x0) {
                    (*0x10009164)();
                    eax = *dword_1000ab38;
                    eax = eax[0x9];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            CloseHandle(eax);
                            *(*dword_1000ab38 + 0x24) = 0x0;
                    }
                    ebx = 0x0;
                    eax = *(*dword_1000ab38 + 0x20);
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            CloseHandle(eax);
                            *(*dword_1000ab38 + 0x20) = ebx;
                    }
                    eax = *(*dword_1000ab38 + 0x1c);
                    if (eax != ebx) {
                            esp = esp - 0x4;
                            CloseHandle(eax);
                            *(*dword_1000ab38 + 0x1c) = ebx;
                    }
                    ebx = 0x0;
                    eax = *dword_1000ab38;
                    eax = eax[0x2];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            CloseHandle(eax);
                            *(*dword_1000ab38 + 0x8) = ebx;
                    }
                    free(*dword_1000ab38);
                    *dword_1000ab38 = ebx;
                    eax = ebx;
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
