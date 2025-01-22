// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterStats.h"
#include "Characterbase.generated.h"

UENUM(BlueprintType)
enum class EChracterState : uint8
{
	Idle UMETA(DisplayName = "대기"),
	Walking UMETA(DisplayName = "걷기"),
	Running UMETA(DisplayName = "달리기"),
	Attacking UMETA(DisplayName = "공격"),
	Defending UMETA(DisplayName = "방어")
};

UCLASS(Abstract) //추상적인 개념화 된다
class UE_CLASSANDSTRUCT_API ACharacterbase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	// 반환값 함수명();
	// 클래스명();
	// 생성자라는 함수입니다
	// 생성자는 이 클래스가 생성이될 때 즉 객체화될 때 발동되는 함수
	ACharacterbase();


	/*float CurrentTime;
	float MaxTime;*/

protected:
	// Called when the game starts or when spawned
	// 접근제한
	virtual void BeginPlay() override;

	//FString Name;
	//int32 Health;
	//int32 MaxHealth;
	//int32 ATK;
	//bool bIsAlive; //살아있는지 여부 확인

	FCharacterStats CharacterStats;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 프로퍼티 게터 함수, 규모가 커질수록 중요해짐, 게터 함수는 ;을 내부에서 사용
	FString GetName() const { return CharacterStats.Name; }

	// Astract 함수 선언방법
	virtual void SetName(const FString& NerName) PURE_VIRTUAL(ACharacterbase::SetName, );

	int32 GetHealth() const { return CharacterStats.Health; }
	void SetHealth(int32 NewHealth) { CharacterStats.Health = NewHealth; }

	bool IsAlive() const { return CharacterStats.bIsAlive; }

	// Astract 함수
	virtual void Attack(ACharacterbase* Target) PURE_VIRTUAL(ACharacterbase::Attack, );

	// virtual 함수
	virtual void ReceiveDamage(int32 Damage);
	
};
