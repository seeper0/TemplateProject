// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CfSkill.h"
#include "CfActionBase.generated.h"

/**
 * 모든 Montage는 Action을 기반으로 움직인다. Skill 이나 HitReaction을 의미한다.
 */
UCLASS(Abstract)
class CFSKILLSYSTEM_API UCfActionBase : public UObject
{
	GENERATED_BODY()
public:
	static UCfActionBase* NewSkill(ACharacter* InOwner, class UCfActionComponent* InComponent, const struct FCfSkillData* InSkillData, const FVector& InputDirection);
	static UCfActionBase* NewHitReaction(ACharacter* InOwner, class UCfActionComponent* InComponent, const FCfDamageEvent& DamageEvent);
	static UCfActionBase* NewRecover(ACharacter* InOwner, class UCfActionComponent* InComponent);
protected:
	void InitAction(ACharacter* InOwner, class UCfActionComponent* InComponent, UAnimMontage* InMontage);
public:
	virtual FName GetActionName() const;
	virtual FString ToString() const;

	void Begin();
	void Tick(float DeltaTime);
	void End();
	void ReleaseButton(const ECfSkillKey InSkillKey);
	
protected:
	virtual void OnBegin();
	virtual void OnTick(float DeltaTime);
	virtual void OnEnd();
	virtual void OnButtonReleased(const ECfSkillKey InSkillKey);

public:
	virtual bool IsEnd() const;
	virtual bool CanMoveDuring() const;
	virtual bool CanInputAutoRapid() const;
	virtual bool CanInputRelease() const;
	virtual bool IsSuperArmorActive() const;
	virtual bool HasSkillKey(ECfSkillKey InSkillKey) const;
	FName GetCurrentSection() const;
	bool HasSection(FName InSection) const;

protected:
	UPROPERTY(Transient)
	ACharacter* Owner = nullptr;

	UPROPERTY(Transient)
	UCharacterMovementComponent* Movement = nullptr;
	
	UPROPERTY(Transient);
	UCfActionComponent* Component = nullptr;

	UPROPERTY(Transient);
	USkeletalMeshComponent* Mesh = nullptr;

	UPROPERTY(Transient);
	UAnimMontage* Montage = nullptr;

	UPROPERTY(Transient);
	UAnimInstance* AnimInstance = nullptr;

#pragma region Stun
public:
	void SetStun(const float InRecoveryTime, const float InStunPlayRate);
protected:
	float GetStunPlayRate() const { return StunPlayRate; }
private:
	void TickAnimStun(float DeltaTime);

	float ElapsedRecoveryTime = 0.0f;
	float RecoveryTime = 0.0f;
	float StunPlayRate = 1.0f;
	bool IsStunned = false; 
#pragma endregion
};
