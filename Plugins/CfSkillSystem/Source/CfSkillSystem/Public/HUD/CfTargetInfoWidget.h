// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CfTargetInfoWidget.generated.h"

/**
 * 유닛 머리에 붙이는 HP Bar
 */
UCLASS(Abstract)
class CFSKILLSYSTEM_API UCfTargetInfoWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HpBar;

public:
	void Update(AActor* DamagedActor, int32 HP, int32 MaxHP);
};
