// Fill out your copyright notice in the Description page of Project Settings.


#include "Anims/CfWeaponAnimInstance.h"
#include "Anims/CfAnimInstance.h"
#include "Anims/CfAnimLocomotionData.h"
#include "CfLogger.h"
#include "CfSkillAsset.h"

void UCfWeaponAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	LocomotionData = UCfSkillAsset::GetLocomotionData(CharacterName, WeaponType, CF_FUNCTION);
}

UCfAnimInstance* UCfWeaponAnimInstance::GetMainAnimInstance()
{
	if(USkeletalMeshComponent* MeshComponent = GetOwningComponent())
	{
		if(UCfAnimInstance* MainAnimInstance =  Cast<UCfAnimInstance>(MeshComponent->GetAnimInstance()))
		{
			return MainAnimInstance;
		}
	}
	return nullptr;
}

#define RETURN_SEQUENCE(SequenceName) \
	if(LocomotionData) \
	{ \
		return LocomotionData->SequenceName; \
	} \
	return nullptr;

UAnimSequence* UCfWeaponAnimInstance::GetIdle() const
{
	RETURN_SEQUENCE(Idle);
}

UAnimSequence* UCfWeaponAnimInstance::GetWalk() const
{
	RETURN_SEQUENCE(Walk);
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkFwd() const
{
	RETURN_SEQUENCE(WalkFwd);
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkFwdLeft() const
{
	RETURN_SEQUENCE(WalkFwdLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkFwdRight() const
{
	RETURN_SEQUENCE(WalkFwdRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkLeft() const
{
	RETURN_SEQUENCE(WalkLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkRight() const
{
	RETURN_SEQUENCE(WalkRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkBwd() const
{
	RETURN_SEQUENCE(WalkBwd)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkBwdLeft() const
{
	RETURN_SEQUENCE(WalkBwdLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetWalkBwdRight() const
{
	RETURN_SEQUENCE(WalkBwdRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunFwd() const
{
	RETURN_SEQUENCE(RunFwd)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunFwdLeft() const
{
	RETURN_SEQUENCE(RunFwdLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunFwdRight() const
{
	RETURN_SEQUENCE(RunFwdRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunLeft() const
{
	RETURN_SEQUENCE(RunLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunRight() const
{
	RETURN_SEQUENCE(RunRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunBwd() const
{
	RETURN_SEQUENCE(RunBwd)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunBwdLeft() const
{
	RETURN_SEQUENCE(RunBwdLeft)
}

UAnimSequence* UCfWeaponAnimInstance::GetRunBwdRight() const
{
	RETURN_SEQUENCE(RunBwdRight)
}

UAnimSequence* UCfWeaponAnimInstance::GetJumpStart() const
{
	RETURN_SEQUENCE(JumpStart)
}

UAnimSequence* UCfWeaponAnimInstance::GetJumpLoop() const
{
	RETURN_SEQUENCE(JumpLoop)
}

UAnimSequence* UCfWeaponAnimInstance::GetJumpEnd() const
{
	RETURN_SEQUENCE(JumpEnd)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetCC() const
{
	RETURN_SEQUENCE(AimOffsetCC)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetCU() const
{
	RETURN_SEQUENCE(AimOffsetCU)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetCD() const
{
	RETURN_SEQUENCE(AimOffsetCD)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetLC() const
{
	RETURN_SEQUENCE(AimOffsetLC)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetLU() const
{
	RETURN_SEQUENCE(AimOffsetLU)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetLD() const
{
	RETURN_SEQUENCE(AimOffsetLD)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetRC() const
{
	RETURN_SEQUENCE(AimOffsetRC)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetRU() const
{
	RETURN_SEQUENCE(AimOffsetRU)
}

UAnimSequence* UCfWeaponAnimInstance::GetAimOffsetRD() const
{
	RETURN_SEQUENCE(AimOffsetRD)
}

#undef RETURN_SEQUENCE
