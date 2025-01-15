#include <cmath>
#include <cstdint>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    for (unsigned i = 0; i < count; ++i) {
        float x = in[i];
        float guess = x * 0.5f;
        const float halfX = 0.5f * x;
        const float tolerance = 1e-6f;

        for (unsigned iterations = 0; iterations < 10; ++iterations) { // Reduced max iterations to 10
            float newGuess = 0.5f * (guess + halfX / guess);
            if (fabs(newGuess - guess) < tolerance) {
                break;
            }
            guess = newGuess;
        }

        out[i] = guess;
    }
}