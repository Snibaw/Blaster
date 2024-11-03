// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(const FString& TextToDisplay)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::SetPlayerName(const FString& Name)
{
	if(PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(Name));		
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch(RemoteRole)
	{
		case ROLE_None:
			Role = "None";
			break;
		case ROLE_SimulatedProxy:
			Role = "Simulated Proxy";
			break;
		case ROLE_AutonomousProxy:
			Role = "Autonomous Proxy";
			break;
		case ROLE_Authority:
			Role = "Authority";
			break;
		default:
			Role = "Unknown";
			break;
	}
	SetDisplayText(FString::Printf(TEXT("Remote Role: %s"), *Role));
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	SetPlayerName(InPawn->GetPlayerState()->GetPlayerName());
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
