#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    for (unsigned i = 0; i < count; ++i) {
        float x = in[i];
        if (x < 0) {
            out[i] = std::numeric_limits<float>::quiet_NaN(); // Handle negative inputs gracefully
            continue;
        }

        // Refined initial guess: bit manipulation approximation
        union {
            float f;
            uint32_t i;
        } conv = {x};
        conv.i = (conv.i >> 1) + 0x1fc00000; // Approximate sqrt via bit-level adjustment
        float guess = conv.f;

        // Refined Newton's method with dynamic stopping condition
        for (int iter = 0; iter < 10; ++iter) { // Up to 10 iterations
            float next_guess = 0.5f * (guess + x / guess);
            if (std::fabs(next_guess - guess) < 1e-4f) { // Early convergence check
                guess = next_guess;
                break;
            }
            guess = next_guess;
        }

        out[i] = guess;
    }
}
