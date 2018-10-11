// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupItem.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "Runtime/UMG/Public/Components/TextBlock.h"


// Sets default values
APickupItem::APickupItem() :
		 _nameBoard(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	

	OnActorBeginOverlap.AddDynamic(this, &APickupItem::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &APickupItem::OnEndOverlap);
}

void APickupItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnActorBeginOverlap.RemoveAll(this);
	OnActorEndOverlap.RemoveAll(this);

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_nameBoard)
	{
		FVector loc = GetActorLocation();
		APlayerController *playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (playerController)
		{
			FVector2D screenLoc;
			playerController->ProjectWorldLocationToScreen(loc, screenLoc);
			_nameBoard->SetPositionInViewport(screenLoc);
		}
	}
}

void APickupItem::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ShowNameBoard();
}

void APickupItem::OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	HideNameBoard();
}

void APickupItem::ShowNameBoard()
{
	if (nullptr != _nameBoard)
		return;

	UClass *StartingWidgetClass = LoadClass<UUserWidget>(NULL, TEXT("Blueprint'/Game/InventorySystem/ItemName.ItemName_C'"));
	if (StartingWidgetClass != nullptr)
	{
		_nameBoard = CreateWidget<UUserWidget>(GetWorld(), StartingWidgetClass);
		if (_nameBoard != nullptr)
		{
			_nameBoard->AddToViewport();
			UTextBlock *text = Cast<UTextBlock>(_nameBoard->GetWidgetFromName(TEXT("NameLabel")));
				text->SetText(_itemInfo.name);
		}
	}
}

void APickupItem::HideNameBoard()
{
	if (nullptr == _nameBoard)
		return;

	_nameBoard->RemoveFromViewport();
	_nameBoard = nullptr;
}