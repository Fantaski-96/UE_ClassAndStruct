#pragma once

#include "CoreMinimal.h"
#include "CharacterStats.generated.h"

USTRUCT()
struct FCharacterStats
{
	GENERATED_BODY()

public:
	FString Name;
	int32 Health;
	int32 MaxHealth;
	int32 ATK;
	bool bIsAlive;

	FCharacterStats()
		: Name(TEXT("Unknown")), Health(100), ATK(10), bIsAlive(true)
	{

	}
};