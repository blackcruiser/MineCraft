// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupItem.h"

#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

#include "MineCharacter.h"


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
	
	UClass *StartingWidgetClass = LoadClass<UUserWidget>(NULL, TEXT("Blueprint'/Game/InventorySystem/ItemName.ItemName_C'"));
	if (StartingWidgetClass != nullptr)
	{
		_nameBoard = CreateWidget<UUserWidget>(GetWorld(), StartingWidgetClass);
		if (_nameBoard != nullptr)
		{
			UTextBlock *text = Cast<UTextBlock>(_nameBoard->GetWidgetFromName(TEXT("NameLabel")));
			text->SetText(_itemInfo.name);
		}
	}

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
	AMineCharacter* character = Cast<AMineCharacter>(OtherActor);
	if (nullptr != character)
	{
		ShowNameBoard();

	}
}

void APickupItem::OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	AMineCharacter* character = Cast<AMineCharacter>(OtherActor);
	if (nullptr != character)
	{
		HideNameBoard();

	}
}

void APickupItem::OnPickup()
{
	GetWorld()->DestroyActor(this);
}

const FNormalItemInfo& APickupItem::getItemInfo() const
{
	return _itemInfo;
}

const int APickupItem::getItemCount() const
{
	return _count;
}

void APickupItem::ShowNameBoard()
{
	if (nullptr != _nameBoard)
		return;

	_nameBoard->AddToViewport();
}

void APickupItem::HideNameBoard()
{
	if (nullptr == _nameBoard)
		return;

	_nameBoard->RemoveFromViewport();
}