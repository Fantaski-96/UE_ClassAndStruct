// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "CharacterStats.h"

void UMyGameInstance::Init()
{
	// 1)

	Super::Init(); //버츄얼로 구현된 함수에는 Super를 붙여주는게 좋다

	StartBattle();


}

void UMyGameInstance::StartBattle()
{
	Player = NewObject<APlayercharacter>();
	//Player != nullPtr
	if (Player)
	{
		Player->SetName(TEXT("전 사"));
		UE_LOG(LogTemp, Warning, TEXT("플레이어 %s(가)이 생성됐습니다"), *Player->GetName());
	}

	Enemy = NewObject<AEnemycharacter>();
	if (Enemy)
	{
		Enemy->SetName(TEXT("고블린"));
		UE_LOG(LogTemp, Warning, TEXT("적 %s(가)이 생성됐습니다"), *Enemy->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("전투를 시작합니다"));

	/*Player->Attack(Enemy);

	Enemy->Attack(Player);

	if (!Enemy->IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("플레이어가 %s가 전투에서 승리했습니다!"), *Player->GetName());
	}
	else if (!Player->IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s(가)이 전투에서 승리했습니다!"), *Enemy->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("플레이어와 적 모두 살아남았습니다! 전투는 무승부입니다."));
	}*/

	/*while (Player->IsAlive() && Enemy->IsAlive())
	{
		Player->Attack(Enemy);

		if (Enemy->IsAlive())
		{
			Enemy->Attack(Player);
		}

		UE_LOG(LogTemp, Warning, TEXT("현재상태"));
		UE_LOG(LogTemp, Warning, TEXT("플레이어 %s - 체력 : %d"), *Player->GetName(), Player->GetHealth());
		UE_LOG(LogTemp, Warning, TEXT("%s - 체력 : %d"), *Enemy->GetName(), Enemy->GetHealth());
	}

	if (!Enemy->IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("플레이어가 %s가 전투에서 승리했습니다!"), *Player->GetName());
	}
	else if (!Player->IsAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s(가)이 전투에서 승리했습니다!"), *Enemy->GetName());
	}*/
	

	ECharacterStats Stats = ECharacterStats::Idle;
	
	switch (Stats)
	{
	case ECharacterStats::Idle:
		UE_LOG(LogTemp, Warning, TEXT("캐릭터가 걷는중입니다"));
		break;
	case ECharacterStats::Walking:
		UE_LOG(LogTemp, Warning, TEXT("캐릭터가 걷는중입니다"));
		break;
	case ECharacterStats::Running:
		break;
	case ECharacterStats::Attacking:
		break;
	case ECharacterStats::Defending:
		break;
		
	default:
		break;
	}
	uint8 NumberValue = static_cast<uint8>(Stats);

	if (NumberValue == 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("enum이 Uint8 2로 변환 성공했습니다"));
	}
}
