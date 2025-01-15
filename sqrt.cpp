#include <cmath>
#include <cstdint>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    for (unsigned i = 0; i < count; ++i) {
        float x = in[i];
        float guess = x > 1.0f ? x * 0.25f : x; // Improved initial guess
        const float tolerance = 1e-5f * x; // Dynamic tolerance based on input magnitude

        for (unsigned iterations = 0; iterations < 15; ++iterations) { // Increased iterations to ensure convergence
            float newGuess = 0.5f * (guess + x / guess);
            if (fabs(newGuess - guess) < tolerance) {
                break;
            }
            guess = newGuess;
        }

        out[i] = guess;
    }
}
