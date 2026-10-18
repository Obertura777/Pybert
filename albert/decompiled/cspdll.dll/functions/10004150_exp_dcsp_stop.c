// exp_dcsp_stop @ 0x10004150
// hopper name: exp_dcsp_stop
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_stop() {
    SetEvent(*(*dword_1000ab38 + 0x20));
    WaitForSingleObject(*(*dword_1000ab38 + 0x24), 0xffffffff);
    (*0x10009164)();
    vos_trace_terminate();
    eax = sub_100047a0();
    return eax;
}
