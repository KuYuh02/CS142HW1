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
        float guess = x / 2.0f; // Initial guess
        float prev_guess;
        
        // Optimized iteration using a fixed small number of steps
        for (int iter = 0; iter < 6; ++iter) { // 6 iterations typically sufficient for float precision
            prev_guess = guess;
            guess = 0.5f * (guess + x / guess);
        }

        out[i] = guess;
    }
}
