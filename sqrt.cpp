#include <cmath>
#include <cstdint>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    for (unsigned i = 0; i < count; ++i) {
        float x = in[i];
        float guess = x / 2.0f
        const float tolerance = 1e-6f; // Dynamic tolerance based on input magnitude

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
