// j_DocumentPropertiesA @ 0x492f8a
// hopper name: j_DocumentPropertiesA
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

j_DocumentPropertiesA() {
    eax = DocumentPropertiesA(saved_fp, hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput);
    return eax;
}
