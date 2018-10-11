// Fill out your copyright notice in the Description page of Project Settings.

#include "MinePlayerController.h"
#include "Blueprint/UserWidget.h"

#include <algorithm>

AMinePlayerController::AMinePlayerController()
{

}

 AMinePlayerController::~AMinePlayerController()
 {}


void AMinePlayerController::BeginPlay()
{
	Super::BeginPlay();

	FSoftClassPath W_MainHUDPath(TEXT("/Game/UI/W_MainHUD.W_MainHUD_C"));
	if (UClass* W_MainHUDClass = W_MainHUDPath.TryLoadClass<UUserWidget>())
		_mainHUD = CreateWidget<UUserWidget>(this, W_MainHUDClass);
	if (_mainHUD)
		_mainHUD->AddToViewport();
}

void AMinePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindKey(EKeys::I, IE_Pressed, this, &AMinePlayerController::OnToggleInventoryShow);
}

void AMinePlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AMinePlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
}

UInventoryManager* AMinePlayerController::GetInventoryManager() const
{
	return _inventoryManager;
}


void AMinePlayerController::UpdateHealth(int value)
{
	_health += value;
	_health = std::min(_health, _maxHealth);
}

void AMinePlayerController::OnToggleInventoryShow()
{
}