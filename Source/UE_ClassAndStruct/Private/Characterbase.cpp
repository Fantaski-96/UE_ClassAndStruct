// Fill out your copyright notice in the Description page of Project Settings.


#include "Characterbase.h"

// 앞에 붙는 A는 Actor를 의미하고 상속받았단뜻
// Sets default values
ACharacterbase::ACharacterbase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterStats.Name = TEXT("빈 캐릭터");
}

// Called when the game starts or when spawned
void ACharacterbase::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ACharacterbase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*CurrentTime += DeltaTime;

	if (CurrentTime >= MaxTime)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s (가)이 생성되었습니다."), *Name);
		CurrentTime = 0.0f;
	
	}*/
}

void ACharacterbase::ReceiveDamage(int32 Damage)
{
	CharacterStats.Health -= Damage;

	if (CharacterStats.Health <= 0)
	{
		CharacterStats.bIsAlive = false;
		CharacterStats.Health = 0;
		UE_LOG(LogTemp, Warning, TEXT("%s (가)이 사망했습니다."), *GetName());
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s (가)이 %d의 데미지를 받았습니다."), *GetName(), Damage);
	}
}
	

	
	

