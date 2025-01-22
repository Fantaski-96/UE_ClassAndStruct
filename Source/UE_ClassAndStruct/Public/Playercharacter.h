// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Characterbase.h"
#include "Playercharacter.generated.h"

UCLASS()
class UE_CLASSANDSTRUCT_API APlayercharacter : public ACharacterbase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayercharacter();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//ACharacterbase의 Abstract 함수 SetName을 상속
	//virtual void SetName(const FString& NewName) PURE_VIRTUAL(ACharacterbase::SetName, );
	virtual void SetName(const FString& NewName) override;
	virtual void Attack(ACharacterbase* Target) override;
	virtual void ReceiveDamage(int32 Damage) override;
};
