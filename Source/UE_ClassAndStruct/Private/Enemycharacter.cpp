// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemycharacter.h"

// Sets default values
AEnemycharacter::AEnemycharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterStats.Name = TEXT("슬라임");
	CharacterStats.ATK = 10;
	CharacterStats.Health = 200;
	CharacterStats.MaxHealth = 200;
	CharacterStats.bIsAlive = true;
}

// Called when the game starts or when spawned
void AEnemycharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemycharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemycharacter::SetName(const FString& NewName)
{
	// NewName(적)
	Name = NewName + TEXT(" (적)");
	UE_LOG(LogTemp, Warning, TEXT("적 캐릭터의 이름이 %s(으)로 설정되었습니다"), *GetName());

}

void AEnemycharacter::Attack(ACharacterbase* Target)
{
	if (!Target || !Target->IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s는 공격할 수 없습니다! 대상이 유효하지 않거나 이미 사망했습니다"), *Target->GetName());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("%s가 %s에게 %d의 데미지를 입혔습니다"), *GetName(), *Target->GetName(), ATK);

	Target->ReceiveDamage(ATK);
}

void AEnemycharacter::ReceiveDamage(int32 Damage)
{
	Super::ReceiveDamage(Damage);

	if (!IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s가 사망했습니다. 20초 뒤에 랜덤한 위치에서 리젠됩니다"), *GetName());
	}
}

