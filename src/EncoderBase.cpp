// the linker currently (<=td1.54) does not always link in _write
// this is a ugly workaround to fix it for T3.x boards
// T4.x don't show the issue.
#if defined(KINETISK)
extern "C" {
int _write(int file, char* ptr, int len)
{
    ((class Print*)file)->write((uint8_t*)ptr, len);
    return len;
}
}
#endif
