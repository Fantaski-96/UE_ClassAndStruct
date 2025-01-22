// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Characterbase.h"
#include "Enemycharacter.generated.h"

UCLASS()
class UE_CLASSANDSTRUCT_API AEnemycharacter : public ACharacterbase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemycharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetName(const FString& NewName) override;
	virtual void Attack(ACharacterbase* Target) override;
	virtual void ReceiveDamage(int32 Damage) override;
};
