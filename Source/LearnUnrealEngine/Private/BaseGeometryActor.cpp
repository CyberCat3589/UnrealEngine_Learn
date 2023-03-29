// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	//PrintTypes();
	//PrintStringTypes();
	//PrintTransform();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovementSin();
}

void ABaseGeometryActor::PrintTypes()
{
	UE_LOG(LogBaseGeometry, Warning, TEXT("Actors name: %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons num = %d, kills num = %i"), WeaponsNum, KillsNum);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Health = %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Is fall = %d"), IsFall);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Has weapon = %d"), static_cast<int>(HasWeapon));
}

void ABaseGeometryActor::PrintStringTypes()
{
	FString Name = "John Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsFallStr = "Is fall = " + FString(IsFall ? "true" : "false");

	FString Stats = FString::Printf(TEXT(" \n == All stats == \n %s \n %s \n %s"), *WeaponsNumStr, *HealthStr, *IsFallStr);

	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stats);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Emerald, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, Stats, true, FVector2D(1.5f, 1.5f));
}

void ABaseGeometryActor::PrintTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actors name: %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform: %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location: %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotation: %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale: %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Human transform: %s"), *Transform.ToHumanReadableString());
}

void ABaseGeometryActor::MovementSin()
{
	FVector CurrentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * Time);
	SetActorLocation(CurrentLocation);
}

