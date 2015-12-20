# SimplexNoise
DevDad - Afan Olovcic @ www.art-and-code.com - 08/12/2015

This algorithm was originally designed by Ken Perlin, but my code has been
adapted and extended from the implementation written by Stefan Gustavson (stegu@itn.liu.se)
and modified to fit to Unreal Engine 4


* This is a clean, fast, modern and free Perlin Simplex noise function.
* If we change float to double it could be even faster but there is no double type in Blueprint
* All Public Functions are BlueprintCallable so they can be used in every blueprint


From DevDad and Dedicated to you and Unreal Community
Use it free for what ever you want
I only request that you mention me in the credits for your game in the way that feels most appropriate to you.

static float SimplexNoise1D(float x);   1D Simplex Noise

static float SimplexNoise2D(float x, float y); 2D Simplex Noise

static float SimplexNoise3D(float x, float y, float z); 3D Simplex Noise

static float SimplexNoise4D(float x, float y, float z, float w); 4D Simplex Noise

##################

static float SimplexNoiseScaled1D(float x , float s);  1D Simplex Noise scaled with s value

static float SimplexNoiseScaled2D(float x, float y, float s); 2D Simplex Noise scaled with s value

static float SimplexNoiseScaled3D(float x, float y, float z, float s); 3D Simplex Noise scaled with s value

static float SimplexNoiseScaled4D(float x, float y, float z, float w, float s); 4D Simplex Noise scaled with s value

##################

static float SimplexNoiseInRange1D(float x, float rangeMin, float rangeMax);  1D Simplex Noise scaled with (rangeMax - rangeMin) value

static float SimplexNoiseInRange2D(float x, float y, float rangeMin, float rangeMax);  2D Simplex Noise scaled with (rangeMax - rangeMin) value

static float SimplexNoiseInRange3D(float x, float y, float z, float rangeMin, float rangeMax); 3D Simplex Noise scaled with (rangeMax - rangeMin) value

static float SimplexNoiseInRange4D(float x, float y, float z, float w, float rangeMin, float rangeMax); 4D Simplex Noise scaled with (rangeMax - rangeMin) value


#########################################################

SimplexNoise Function retruns float value between 0 - 1 
SimplexNoise Scaled retruns float value between 0 - scale factor 
SimplexNoise In Range returns float value between minRange - maxRange
