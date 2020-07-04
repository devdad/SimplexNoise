/*
SimplexNoise 1.2.0
-----
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

*/

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SimplexNoiseBPLibrary.generated.h"

	USTRUCT()
	struct FPoint {
		GENERATED_BODY()
		UPROPERTY()
			float x;
		UPROPERTY()
			float y;
		UPROPERTY()
			float z;
	};


	USTRUCT()
	struct FTriangle {
		GENERATED_BODY()
		UPROPERTY()
			FPoint point[3];
	};

	USTRUCT()
	struct FCell {
		GENERATED_BODY()
		UPROPERTY()
			FPoint point[8];
		UPROPERTY()
			float val[8];
	};
		
UCLASS()
class SIMPLEXNOISE_API USimplexNoiseBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
private:
	static unsigned char perm[];
	static float  _grad(int hash, float x);
	static float  _grad(int hash, float x, float y);
	static float  _grad(int hash, float x, float y, float z);
	static float  _grad(int hash, float x, float y, float z, float t);

	static float _simplexNoise1D(float x);
	static float _simplexNoise2D(float x, float y);
	static float _simplexNoise3D(float x, float y, float z);
	static float _simplexNoise4D(float x, float y, float z, float w);
	static int	  _polygonise(FCell cell, float isolevel, FTriangle* triangles);

public:

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static void setNoiseSeed(const int32& newSeed);
    
    UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static void setNoiseFromStream(FRandomStream& RandStream);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoise1D(float x, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoise2D(float x, float y, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoise3D(float x, float y, float z, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoise4D(float x, float y, float z, float w, float inFactor = 1.f);

	// Scaled by float value
	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseScaled1D(float x , float scaleOut = 1.f, float inFactor = 1.f);
	
	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseScaled2D(float x, float y, float scaleOut = 1.f, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseScaled3D(float x, float y, float z, float scaleOut = 1.f, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseScaled4D(float x, float y, float z, float w, float scaleOut = 1.f, float inFactor = 1.f);

	// Return value in Range between two float numbers
	// Return Value is scaled by difference between rangeMin & rangeMax value

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseInRange1D(float x, float rangeMin, float rangeMax, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseInRange2D(float x, float y, float rangeMin, float rangeMax, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseInRange3D(float x, float y, float z, float rangeMin, float rangeMax, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float SimplexNoiseInRange4D(float x, float y, float z, float w, float rangeMin, float rangeMax, float inFactor = 1.f);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float GetSimplexNoise1D_EX(float x, float lacunarity = 2.3f, float persistance = 0.6f, int octaves = 4, float inFactor = 1.0f, bool ZeroToOne = false);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float GetSimplexNoise2D_EX(float x, float y, float lacunarity = 2.3f, float persistance = 0.6f, int octaves = 4, float inFactor = 1.0f, bool ZeroToOne = false);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float GetSimplexNoise3D_EX(float x, float y, float z, float lacunarity = 2.3f, float persistance = 0.6f, int octaves = 4, float inFactor = 1.0f, bool ZeroToOne = false);

	UFUNCTION(BlueprintCallable, Category = "SimplexNoise")
		static float GetSimplexNoise4D_EX(float x, float y, float z, float w, float lacunarity = 2.3f, float persistance = 0.6f, int octaves = 4, float inFactor = 1.0f, bool ZeroToOne = false);

};

