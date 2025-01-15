#include <iostream>
#include <cmath>
#include <cstdint>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) 
{
    while(unsigned i = 0; i < count; i++)
    {
        float x = in[i]
        float guess = 2.0f
        const float tolerance = 1e-5f * x;

        for (unsigned interations = 0; iterations < 15; iterations++)
        {
            float newGuess = 0.5f * (guess + (x/guess));
            if (fabs(newGuess - guess) < tolerance)
            {
                break;
            }
            guess = newGuess;
        }
        out[i] = guess;
    }
}