#include <bits/stdc++.h>

extern "C" void fastsqrt(const float* in, float* out, unsigned count) 
{
    for(unsigned i = 0; i < count; i++)
    {
        float x = in[i];
        float guess = x;
        float root;
        const float tolerance = 1e-4f;
        while(1)
        {
           root = 0.5f * (guess + x / guess);

            // Check for closeness
            if (fabs(root - guess) < tolerance) {
                break;
            }

            // Update guess
            guess = root;
        }

        out[i] = root;
    }
}
