// Fill out your copyright notice in the Description page of Project Settings.

#include "MineCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "InventorySystem/Actor/PickupItem.h"


// Sets default values
AMineCharacter::AMineCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMineCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AMineCharacter::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AMineCharacter::EndOverlap);
}

void AMineCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AMineCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector CamLoc;
	//FRotator CamRot;

	//GetActorEyesViewPoint(CamLoc, CamRot);
	//const FVector Direction = CamRot.Vector();
	//const FVector TraceStart = CamLoc + (Direction * 40);
	//const FVector TraceEnd = TraceStart + (Direction * 500);//计算射线的终点

	//FCollisionQueryParams TraceParams(FName(TEXT("TraceUsableActor")), true, this);
	//TraceParams.bTraceAsyncScene = true;
	//TraceParams.bReturnPhysicalMaterial = false;
	//TraceParams.bTraceComplex = true;

	//FHitResult Hit(ForceInit);
	//GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Pawn, TraceParams);
	//绘制射线  
	//DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Blue, false, -1.f, 0, 1.0f);

}

// Called to bind functionality to input
void AMineCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardBackward", this, &AMineCharacter::onMoveForwardBackward);
	PlayerInputComponent->BindAxis("LeftRight", this, &AMineCharacter::onMoveLeftRight);
	PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);
}

APickupItem* AMineCharacter::GetNearestPickupItem()
{
	APickupItem* item = _nearbyItemSet.Pop();

	return item;
}


void AMineCharacter::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	APickupItem* item = Cast<APickupItem>(OtherActor);
	if (item)
	{
		AddNearByPickupItem(item);
	}
}

void AMineCharacter::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	APickupItem* item = Cast<APickupItem>(OtherActor);
	if (item)
	{
		RemoveNearByPickupItem(item);
	}
}

void AMineCharacter::AddNearByPickupItem(APickupItem* item)
{
	_nearbyItemSet.Add(item);
}

void AMineCharacter::RemoveNearByPickupItem(APickupItem* item)
{
	_nearbyItemSet.Remove(item);
}

void AMineCharacter::onMoveForwardBackward(float value)
{
	FRotator rotation = Controller->GetControlRotation();
	FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);

	AddMovementInput(direction, value);
}

void AMineCharacter::onMoveLeftRight(float value)
{
	FRotator rotation = Controller->GetControlRotation();
	FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);

	AddMovementInput(direction, -value);
}

void AMineCharacter::onYawChange(float value)
{
	AddControllerYawInput(value * 1.0f);
}

void AMineCharacter::onPitchChange(float value)
{
	AddControllerPitchInput(value * 1.0f);
}

FRotator AMineCharacter::getAimOffsets() const
{
	const FVector AimDirWS = GetBaseAimRotation().Vector();
	const FVector AimDirLS = ActorToWorld().InverseTransformVectorNoScale(AimDirWS);
	const FRotator AimRotLS = AimDirLS.Rotation();

	FString text = "WS: " + FString::SanitizeFloat(GetActorRotation().Pitch) + "  LS: " + FString::SanitizeFloat(GetActorRotation().Yaw);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, text);

	return AimRotLS;
}
