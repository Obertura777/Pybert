// sub_46f8be @ 0x46f8be
// hopper name: sub_46f8be
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f8be() {
    if (*(int8_t *)(sub_4715ba() + 0x14) == 0x0) {
            *(sub_471099() + 0x2c) = SetWindowsHookExA(0xffffffff, 0x46f72a, 0x0, GetCurrentThreadId());
    }
    return;
}
