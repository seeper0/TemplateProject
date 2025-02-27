// Copyright Epic Games, Inc. All Rights Reserved.

#include "CfSkillSystemEditor.h"
#include "Editor/Persona/Public/PersonaModule.h"
#include "Editor/Persona/Public/IPersonaPreviewScene.h"
#include "Editor/Persona/Private/AnimationEditorPreviewScene.h"
#include "CfLogger.h"
#include "CfNotifyDetails.h"

#define LOCTEXT_NAMESPACE "FCfSkillSystemEditorModule"

DECLARE_DELEGATE_OneParam(FOnGetPreviewSceneDelegate, FAnimationEditorPreviewScene*);

void FCfSkillSystemEditorModule::StartupModule()
{
	if ( FModuleManager::Get().IsModuleLoaded( "Persona" ) )
	{
		FPersonaModule& PersonaModule = FModuleManager::GetModuleChecked< FPersonaModule >( "Persona" );
		PreviewSceneCreatedHandle = PersonaModule.OnPreviewSceneCreated().AddRaw( this, &FCfSkillSystemEditorModule::OnPreviewSceneCreated );
	}

	const FName PropertyEditor(TEXT("PropertyEditor"));
	if ( FModuleManager::Get().IsModuleLoaded( PropertyEditor ) )
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked< FPropertyEditorModule >( PropertyEditor );

		const FName PropertyTypeName(TEXT("AnimNotifyEvent"));
		PropertyModule.RegisterCustomPropertyTypeLayout( PropertyTypeName, FOnGetPropertyTypeCustomizationInstance::CreateRaw( this, &FCfSkillSystemEditorModule::OnAnimNotifyEvent ) );
	}
}

void FCfSkillSystemEditorModule::ShutdownModule()
{
	const FName PropertyEditor(TEXT("PropertyEditor"));
	if ( FModuleManager::Get().IsModuleLoaded( PropertyEditor ) )
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked< FPropertyEditorModule >( PropertyEditor );

		const FName PropertyTypeName(TEXT("AnimNotifyEvent"));
		PropertyModule.UnregisterCustomPropertyTypeLayout(PropertyTypeName);
	}

	if ( FModuleManager::Get().IsModuleLoaded( "Persona" ) )
	{
		FPersonaModule& PersonaModule = FModuleManager::GetModuleChecked< FPersonaModule >( "Persona" );
		if ( PreviewSceneCreatedHandle.IsValid() )
		{
			PersonaModule.OnPreviewSceneCreated().Remove( PreviewSceneCreatedHandle );
			PreviewSceneCreatedHandle.Reset();
			PreviewSceneWorld = nullptr;
		}
	}
}

#pragma region OnPreviewSceneCreated
void FCfSkillSystemEditorModule::OnPreviewSceneCreated(const TSharedRef<IPersonaPreviewScene>& Shared)
{
	const TSharedRef< FAnimationEditorPreviewScene >& AnimationEditorPreviewScene = StaticCastSharedRef<FAnimationEditorPreviewScene>( Shared );
	PreviewSceneWorld = AnimationEditorPreviewScene->GetWorld();
}
#pragma endregion

#pragma region OnAnimNotifyEvent

TSharedRef<IPropertyTypeCustomization> FCfSkillSystemEditorModule::OnAnimNotifyEvent()
{
	TSharedRef< FCfNotifyDetails > NotifyDetails = MakeShareable( new FCfNotifyDetails );
	return NotifyDetails;
}
#pragma endregion

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCfSkillSystemEditorModule, CfSkillSystemEditor)