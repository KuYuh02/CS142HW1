#include <cstdint>
#include <cmath>

inline float initial_guess(float x) {
    union {
        float f;
        uint32_t i;
    } u = {x};

    // Adjust the bit-level representation to estimate the square root
    u.i = (u.i >> 1) + 0x1FC00000;
    return u.f;
}

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    unsigned i = 0;
    while (i < count) {
        float x = in[i];
        float y = initial_guess(x);

        int j = 0;
        do {
            y = 0.5f * (y + x / y);
            ++j;
        } while (j < 4);

        out[i] = y;
        ++i;
    }
}
