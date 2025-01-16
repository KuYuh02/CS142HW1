#include <cstdint>
#include <cmath>

inline float initial_guess(float x) 
{
    union 
    {
        float y;
        uint32_t i;
    } 
    u = {x};

    // Approximate sqrt by manipulating the exponent
    u.i = (u.i >> 1) + 0x1FC00000;
    return u.y;
}

extern "C" void fastsqrt(const float* in, float* out, unsigned count) 
{
    //Initialize variables
    for (unsigned i = 0; i < count; i++) 
    {
        float a = in[i];
        float b = initial_guess(a);

        // Perform Newton's Method'
        for (int j = 0; j < 4; j++) 
        {
            b = 0.5f * (b + a / b);
        }

        out[i] = b;
    }
}
