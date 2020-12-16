#include <stdint.h>
#include <Windows.h>

static uint64_t xor64(void) {
  static uint64_t x = 88172645463325252ULL;
  x = x ^ (x << 7);
  return x = x ^ (x >> 9);
}

int main(void) {
    INPUT input[2] = { 0 };
    input[0].type = input[1].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    for(;;) {
        Sleep(100 + xor64() % 100);
        if (!(GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
            continue;
        }
        if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            continue;
        }
        SendInput(2, input, sizeof(INPUT));
    }
    return 0;
}
