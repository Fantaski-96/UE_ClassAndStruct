// Fill out your copyright notice in the Description page of Project Settings.


#include "Playercharacter.h"

// Sets default values
APlayercharacter::APlayercharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterStats.Name = TEXT("용 사");
	CharacterStats.Health = 200;
	CharacterStats.MaxHealth = 200;
	CharacterStats.ATK = 20;
	CharacterStats.bIsAlive = true;
}

// Called when the game starts or when spawned
void APlayercharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayercharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayercharacter::SetName(const FString& NewName)
{
	UE_LOG(LogTemp, Warning, TEXT("플레이어의 이름이 %s(으)로 설정되었습니다"), *GetName());
}

void APlayercharacter::Attack(ACharacterbase* Target)
{
	//class 앞에 !를 붙이면 nullptr을 체크할 수 있다
	//Target != nullptr을 축약한것이다.
	//!Target->IsAlive() / Target->IsAlive() == false
	if (!Target || !Target->IsAlive()) // 타겟에 bIsAlive를 대입, 생존 여부 확인
	{
		UE_LOG(LogTemp, Warning, TEXT("%s는 공격할 수 없습니다! 대상이 유효하지 않거나 이미 사망했습니다"), *Target->GetName());
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("%s가 %s에게 %d의 데미지를 입혔습니다!"), *Name, *Target->GetName(), ATK);

	Target->ReceiveDamage(ATK);

}

void APlayercharacter::ReceiveDamage(int32 Damage)
{
	// 부모 ReceiveDamage 로직을 실행한 뒤
	Super::ReceiveDamage(Damage);

	// 자식 ReceiveDamage 로직 실행
	if (!IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s (가)이 30초 뒤 우물에서 부활합니다!"), *GetName());
	}
}

