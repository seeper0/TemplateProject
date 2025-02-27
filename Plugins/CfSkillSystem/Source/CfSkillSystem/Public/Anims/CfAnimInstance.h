// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CfCheatManager.h"
#include "CfSkill.h"
#include "CfAnimInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, hideCategories=AnimInstance, BlueprintType, Within=SkeletalMeshComponent)
class CFSKILLSYSTEM_API UCfAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	inline static FName InputArrowName = TEXT("InputArrow");
	inline static FName VelocityArrowName = TEXT("VelocityArrow");
	
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	void SetLookAtRotation(const FRotator& Rotator);

private:
	void UpdateCharacterMomentum(float DeltaSeconds, ACharacter* InOwner);
	void UpdateCardinalDirection(float DeltaSeconds);
	void UpdateDebugArrow(float DeltaSeconds, ACharacter* InOwner);

	UPROPERTY()
	UCfCheatManager* CheatManager;

	UPROPERTY()
	class UArrowComponent* InputArrow;

	UPROPERTY()
	UArrowComponent* VelocityArrow;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool WasMovingLastUpdate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FVector WorldLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FVector PrevWorldLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float FrameDisplacement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float DisplacementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FVector LocalVelocity2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FVector WorldVelocity2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FVector WorldVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FRotator WorldRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float GroundSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float LocalVelocityDirectionAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool IsSprinting = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool IsFalling = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool HasVelocity = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool ShouldMove = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	ECfCardinalDirection CardinalDirection = ECfCardinalDirection::Forward;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float LookAtYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float LookAtPitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	float LookAtAlpha = 1.0f;
};
