#include <iostream>
#include <cmath>
#include <cstdint>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) {
    for (unsigned i = 0; i < count; ++i) {
        float x = in[i];
        float guess = x / 2.0f; // Initial guess
        const float tolerance = 1e-6f;
        const unsigned maxIterations = 20;
        unsigned iterations = 0;

        while (iterations < maxIterations) {
            float newGuess = 0.5f * (guess + x / guess);
            if (fabs(newGuess - guess) < tolerance) {
                break;
            }
            guess = newGuess;
            ++iterations;
        }

        out[i] = guess;
    }
}


int main() 
{
    return 0;
}