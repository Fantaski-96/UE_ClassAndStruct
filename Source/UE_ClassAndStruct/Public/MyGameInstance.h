// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Playercharacter.h"
#include "Enemycharacter.h"
#include "MyGameInstance.generated.h" //include를 추가할때는 generated보다 위에 넣을것



/**
 * 
 */
//언리얼 엔진에서 사용할 수 있게 변경해주는 매크로
//리플렉션, 가비지셀렉터가 자동으로 적용되게 해준다.
//UMyGameInstance 앞에 U가 붙는건 UObject에서 상속 받는것이라는 표시
UCLASS()
class UE_CLASSANDSTRUCT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

//접근제한자 지정이유
//1. 기능을 모르는 사람이 속성을 변경해서 에러가 나타날 수 있는걸 방지
//2. 접근제한자를 지정해줘야 코드 가독성이 올라간다
// 누구나 접근가능한 속성이나 기능
public:
	void Init() override;

// 나와 내 자식만 접근 가능한 속성이나 기능
protected:

// 나만 접근 가능한 속성이나 기능
private:
	void StartBattle();
	
	APlayercharacter* Player;
	AEnemycharacter* Enemy;


};
